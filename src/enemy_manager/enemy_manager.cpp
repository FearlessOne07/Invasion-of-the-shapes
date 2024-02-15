#include "enemy_manager.hpp"
#include "../particles/enemy_child_spawner.h"

EnemyManager::EnemyManager(AssetManager& assets) : _assets(assets)
{
	_enemyRadius = 50;
	_spawnInterval = 5;
	_enemyDieSound = _assets.GetSound("enemy_die");

	_particleSpawner = std::make_shared<EnemyChildSpawner>();
}

void EnemyManager::SpawnEnemy()
{
	std::random_device rd;
	std::mt19937 gen(rd());

	// Color & Sides
	std::uniform_int_distribution<int> colorDist(0, (sizeof(_colors) / sizeof(Color)) - 1);
	Color color = _colors[colorDist(gen)];
	std::uniform_int_distribution<int> sidesDist(3, 8);
	int sides = sidesDist(gen);

	// Speed
	std::uniform_real_distribution<float> speedDist(200, 300);
	float speed = speedDist(gen);

	// Position
	std::uniform_int_distribution<int> sideDist(0, 3);
	std::uniform_real_distribution<float> distX(_enemyRadius * -1.f, GetScreenWidth() + _enemyRadius);
	std::uniform_real_distribution<float> distY(_enemyRadius * -1.f, GetScreenHeight() + _enemyRadius);

	Vector2 position;
	int side = sideDist(gen);

	switch (side)
	{
	case 0: // UP
		position = { distX(gen), _enemyRadius * -1.f };
		break;
	case 1: // DOWN
		position = { distX(gen), static_cast<float>(GetScreenHeight()) + static_cast<float>(_enemyRadius) };
		break;
	case 2: // LEFT
		position = { -1.f * _enemyRadius, distY(gen) };
		break;
	case 3: // RIGHT
		position = { static_cast<float>(GetScreenWidth()) + _enemyRadius, distY(gen) };
		break;
	default:
		position = { 0, 0 };
		break;
	}
	_enemies.emplace_back(Enemy(color, sides, position, _enemyRadius, speed, _particleSpawner));
}

void EnemyManager::SpawnEnemies(float& dt)
{
	// Determine When to spawn next Enemy
	_spawnTimer += dt;
	if (_spawnTimer >= _spawnInterval)
	{
		_spawnTimer = 0;
		SpawnEnemy();
	}
}

void EnemyManager::RemoveDeadEnemies()
{

	// Check for and remove Dead enemies

	for (Enemy& e : _enemies)
	{
		if (e.GetDead())
		{
			e.Die();
		}
	}

	auto it = std::remove_if(
		_enemies.begin(),
		_enemies.end(),
		[](Enemy& e) -> bool
		{ return e.GetDead(); }
	);

	_enemies.erase(it, _enemies.end());

}

void EnemyManager::CheckPlayerCols(Player& player, const Enemy& enemy)
{
	// Check if an enemy has collided with the player
	if (CheckCollisionCircles(player.GetPos(), static_cast<float>(player.radius), enemy._position, static_cast<float>(enemy._radius)))
	{
		player.SetDead(true);
	}
}

void EnemyManager::Update(float& dt, Player& player, std::vector<Bullet>& bullets)
{

	SpawnEnemies(dt);

	for (Enemy& enemy : _enemies)
	{
		enemy.Update(player.GetPos(), dt);
		CheckPlayerCols(player, enemy);
	}
	CheckBulletCol(bullets, player);
	_particleSpawner->Update();
	RemoveDeadEnemies();


	_particleSpawner->Render();
	for (Enemy& enemy : _enemies)
	{
		enemy.Render();
	}
}

void EnemyManager::Reset()
{
	_particleSpawner->Reset();
	_enemies.clear();
	_enemies.shrink_to_fit();
	SetInterval(5);
}

void EnemyManager::SetInterval(float interval)
{
	_spawnInterval = interval;
}


void EnemyManager::CheckBulletCol(std::vector<Bullet>& bullets, Player& player)
{
	// Check if a bullet has collided with an enemy
	for (Bullet& b : bullets)
	{
		for (Enemy& e : _enemies)
		{
			if (CheckCollisionCircles(e.GetPos(), static_cast<float>(_enemyRadius), b.GetPos(), static_cast<float>(b.GetRad())))
			{
				PlaySound(*_enemyDieSound);
				b.SetIsActive(false);
				e.SetDead(false);
				player.SetScore(player.GetScore() + 100);
			}
		}
	}
}
