#include <random>
#include "raylib.h"
#include "spawner.hpp"
#include "enemy/runner.hpp"
#include "enemy/shooter.hpp"
#include "enemy_manager/enemy_manager.hpp"
#include "asset_manager/asset_manager.hpp"

Spawner::Spawner(std::shared_ptr<AssetManager> assets)
	: _assets(assets)
{
	_enemyScore = 0;
	_spawnTimer = 0;
	_spawnInterval = 3;
}

void Spawner::Spawn(std::vector<std::shared_ptr<Enemy>> &enemies, short unsigned int type)
{
	float dt = GetFrameTime();
	_spawnTimer += dt;

	if (_spawnTimer >= _spawnInterval)
	{
		_spawnTimer = 0;
		std::random_device rd;
		std::mt19937 gen(rd());

		float _enemyRadius = 20.f;
		std::uniform_int_distribution<int> sideDist(0, 3);
		std::uniform_real_distribution<float> distX(_enemyRadius * -1.f, GetScreenWidth() + _enemyRadius);
		std::uniform_real_distribution<float> distY(_enemyRadius * -1.f, GetScreenHeight() + _enemyRadius);

		Vector2 position;
		int side = sideDist(gen);

		switch (side)
		{
		case 0: // UP
			position = {distX(gen), _enemyRadius * -1.f};
			break;
		case 1: // DOWN
			position = {distX(gen), static_cast<float>(GetScreenHeight()) + static_cast<float>(_enemyRadius)};
			break;
		case 2: // LEFT
			position = {-1.f * _enemyRadius, distY(gen)};
			break;
		case 3: // RIGHT
			position = {static_cast<float>(GetScreenWidth()) + _enemyRadius, distY(gen)};
			break;
		default:
			position = {0, 0};
			break;
		}

		std::shared_ptr<Enemy> enemy;

		switch (type)
		{
		case EnemyManager::SpawnerID::RUNNER:
			enemy = std::make_shared<Runner>(position, 100, 100);
			break;
		case EnemyManager::SpawnerID::SHOOTER:
			enemy = std::make_shared<Shooter>(position, _assets->GetTexture("bullet"));
		default:
			break;
		}

		enemies.emplace_back(enemy);
	}
}

void Spawner::Reset()
{
	_spawnTimer = 0;
}
