#include "enemy_manager.h"
#include "../enemy/enemy.h"
#include "../spawners/spawner.h"

EnemyManager::EnemyManager(std::shared_ptr<AssetManager> assets) : _assets(assets)
{
	_enemies = {};
}

void EnemyManager::Update(Player& player)
{
	for (std::shared_ptr<Enemy> e : _enemies)
	{
		e->Update(player);
	}
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
}

void EnemyManager::Spawn(SpawnerID spawner)
{
	_spawners[spawner]->Spawn(_enemies);
}

