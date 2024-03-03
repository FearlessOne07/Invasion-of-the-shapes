#pragma once
#include <vector>
#include <memory>
#include <unordered_map>

class Spawner;
class Enemy;
class Player;
class AssetManager;
class EnemyManager
{
public:
	typedef enum SpawnerID
	{
		RUNNER = 0
	} SpawnerID;
private:
	std::vector<std::shared_ptr<Enemy>> _enemies;
	std::unordered_map<SpawnerID, std::shared_ptr<Spawner>> _spawners;

	std::shared_ptr<AssetManager> _assets;

public:
	EnemyManager(std::shared_ptr<AssetManager> assets);
	void Update(Player& player);
	void Render();
	void Reset();
	void Spawn(SpawnerID);
};

