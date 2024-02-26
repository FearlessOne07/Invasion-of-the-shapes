#pragma once
#include "enemy.hpp"
#include "../player/player.hpp"
#include <vector>
#include <random>
#include <algorithm>
#include "../bullet_manager/bullet_manager.hpp"
#include "../particles/enemy_child_spawner.h"

class EnemyManager
{
private:
    // Enemy Management
    std::vector<Enemy> _enemies{};
    Color _colors[5] = {GREEN, RED, PINK, ORANGE, BLUE};
    int _enemyRadius{};

    // Enemy Spawning
    float _spawnTimer{};
    float _spawnInterval{};

    // Assets
    std::shared_ptr<AssetManager> _assets;
    Sound* _enemyDieSound;

    // Particle Spawner
    std::shared_ptr<EnemyChildSpawner> _particleSpawner;

private:
    void SpawnEnemy();
    void SpawnEnemies(float &dt);
    void RemoveDeadEnemies();
    void CheckPlayerCols(Player &player, const Enemy &enemy);
    void CheckBulletCol(std::vector<Bullet> &bullets, Player& player);

public:
    EnemyManager(std::shared_ptr<AssetManager> assets);
    void Update(float &dt, Player &player, std::vector<Bullet>& bullets);
    void Reset();
    void SetInterval(float interval);
};