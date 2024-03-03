#pragma once
#include <memory>
#include <vector>

class Enemy;
class Spawner
{
public:
	virtual ~Spawner() {};
	virtual void Spawn(std::vector<std::shared_ptr<Enemy>>& enemies) = 0;
};