#include <algorithm>
#include "enemy/enemy.hpp"
#include "enemy_manager/enemy_manager.hpp"
#include "utils/bullet/bullet.hpp"
#include "bullet_manager/bullet_manager.hpp"
#include "player/player.hpp"

EnemyManager::EnemyManager(
	std::shared_ptr<AssetManager> assets,
	std::shared_ptr<BulletManager> bulletManager,
	std::shared_ptr<Camera2D> camera
) 
	: _assets(assets), _bulMan(bulletManager), _camera(camera)
{	
	_enemies = {};
	_enemySpawner = Spawner(_assets);
}

void EnemyManager::CheckBulletColissions(std::vector<Bullet>& bullets, Player& player)
{
	for (Bullet& b : bullets)
	{
		if(b.GetTag() == Bullet::PLAYER_BULLET)
		{
			for (std::shared_ptr<Enemy>& e : _enemies)
			{
				if (CheckCollisionCircles(e->GetPos(), e->GetRadius(), b.GetPos(), b.GetRad()))
				{
					b.SetIsActive(false);
					e->SetIsAlive(false);
					player.SetScore(e->GetScore() + player.GetScore());
				}
			}
		}
		
	}
}

void EnemyManager::CheckPlayerColission(Player& player)
{
	for (std::shared_ptr<Enemy>& e : _enemies)
	{
		if (CheckCollisionCircles(e->GetPos(), e->GetRadius(), player.GetPos(), player.GetRaduis()))
		{
			player.SetDead(true);
		}
	}
}

void EnemyManager::RemoveDeadEnemies()
{
	auto it = std::remove_if(
		_enemies.begin(), 
		_enemies.end(), 
		[](std::shared_ptr<Enemy>& e) {return !e->isAlive(); }
	);
	_enemies.erase(it, _enemies.end());
}


void EnemyManager::Update(Player& player)
{
	for (std::shared_ptr<Enemy> e : _enemies)
	{
		e->Update(player);
	}
	//Spawn(RUNNER);
	Spawn(SHOOTER);
	CheckBulletColissions(_bulMan->GetBullets(), player);
	CheckPlayerColission(player);
	RemoveDeadEnemies();
}

void EnemyManager::Render()
{
	for (std::shared_ptr<Enemy> e : _enemies)
	{
		e->Render();
	}
}

void EnemyManager::Reset()
{
	_enemies.clear();
	_enemySpawner.Reset();
}

void EnemyManager::Spawn(SpawnerID spawner)
{
	_enemySpawner.Spawn(_enemies, spawner, _bulMan, _camera);
}

