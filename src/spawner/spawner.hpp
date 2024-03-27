#pragma once
#include <memory>
#include <vector>
#include "enemy/enemy.hpp"
class AssetManager;
class BulletManager;
class Spawner
{
protected:
	int _enemyScore;
	float _spawnInterval;
	float _spawnTimer;

	std::shared_ptr<AssetManager> _assets;
public:
	Spawner(std::shared_ptr<AssetManager> assets);
	Spawner() = default;
	void Spawn(
		std::vector<std::shared_ptr<Enemy>>& enemies, 
		short unsigned int type, 
		std::shared_ptr<BulletManager> bulMan,
		std::shared_ptr<Camera2D> camera
	);
	void Reset();
};