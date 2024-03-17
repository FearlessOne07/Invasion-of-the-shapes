#include "enemy_manager.h"
#include "../enemy/enemy.h"
#include "../spawner/spawner.h"
#include "../bullet_manager/bullet.hpp"
#include "../bullet_manager/bullet_manager.hpp"
#include "../player/player.hpp"
#include <algorithm>

void EnemyManager::CheckBulletColissions(std::vector<Bullet>& bullets, Player& player)
{
	for (Bullet& b : bullets)
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
	auto it = std::remove_if(_enemies.begin(), _enemies.end(), [](std::shared_ptr<Enemy>& e) {return !e->isAlive(); });
	_enemies.erase(it, _enemies.end());
}

EnemyManager::EnemyManager(std::shared_ptr<AssetManager> assets) : _assets(assets)
{
	_enemies = {};
}

void EnemyManager::Update(Player& player, BulletManager& bulletManager)
{
	for (std::shared_ptr<Enemy> e : _enemies)
	{
		e->Update(player);
	}
	//Spawn(RUNNER);
	Spawn(RUNNER);
	CheckBulletColissions(bulletManager.GetBullets(), player);
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
	_enemySpawner.Spawn(_enemies, spawner);
}

