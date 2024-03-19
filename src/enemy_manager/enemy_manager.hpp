#pragma once
#include <vector>
#include <memory>
#include <unordered_map>
#include "raylib.h"
#include "spawner/spawner.hpp"

class Enemy;
class Player;
class AssetManager;
class Bullet;
class BulletManager;
class EnemyManager
{
public:
	typedef enum SpawnerID : short unsigned int
	{
		RUNNER = 0,
		DASHER,
		SHOOTER
	} SpawnerID;
	
private:
	std::vector<std::shared_ptr<Enemy>> _enemies;
	Spawner _enemySpawner;
	std::shared_ptr<AssetManager> _assets;
private:
	void CheckBulletColissions(std::vector<Bullet>& bullets, Player& player);
	void CheckPlayerColission(Player& player);
	void RemoveDeadEnemies();
public:
	EnemyManager(std::shared_ptr<AssetManager> assets);
	void Update(Player& player, BulletManager& bulletManager);
	void Render();
	void Reset();
	void Spawn(SpawnerID);
};

