#pragma once
#include <memory>
#include <vector>
#include "enemy/enemy.hpp"

class Spawner
{
protected:
	int _enemyScore;
	float _spawnInterval;
	float _spawnTimer;
public:
	Spawner();
	void Spawn(std::vector<std::shared_ptr<Enemy>>& enemies, short unsigned int type);
	void Reset();
};