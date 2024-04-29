#pragma once
#include <vector>
#include <memory>
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
	typedef enum EnemyType : short unsigned int
	{
		RUNNER = 0,
		DASHER,
		SHOOTER
	} EnemyType;
	
private:
	std::shared_ptr<Camera2D> _camera;

	std::vector<std::shared_ptr<Enemy>> _enemies;

	Spawner _enemySpawner;

	std::shared_ptr<AssetManager> _assets;

	std::shared_ptr<BulletManager> _bulMan;

private:
	void CheckBulletColissions(std::vector<Bullet>& bullets, Player& player);
	void CheckPlayerColission(Player& player);
	void RemoveDeadEnemies();
public:
	EnemyManager(
		std::shared_ptr<AssetManager> assets,
		std::shared_ptr<BulletManager> bulletManager,
		std::shared_ptr<Camera2D> camera
	);
	void Update(Player& player);
	void Render();
	void Reset();
	void Spawn(EnemyType type);
};

