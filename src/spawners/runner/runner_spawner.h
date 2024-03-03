#pragma once
#include "../spawner.h"

class RunnerSpawner : public Spawner
{
	void Spawn(std::vector<std::shared_ptr<Enemy>>& enemies) override;
};

