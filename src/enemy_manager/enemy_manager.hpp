#pragma once
#include "enemy.hpp"
#include "../player/player.hpp"
#include <vector>
#include <random>
#include <algorithm>
#include "../bullet_manager/bullet_manager.hpp"
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

    // Sounds
    Sound _enemyDieSound;

private:
    void SpawnEnemy();
    void SpawnEnemies(float &dt);
    void RemoveDeadEnemies();
    void CheckPlayerCols(Player &player, Enemy &enemy);
    void CheckBulletCol(std::vector<Bullet> &bullets);

public:
    EnemyManager();
    ~EnemyManager();
    void Update(float &dt, Player &player, std::vector<Bullet>& bullets);
    void Reset();
    void SetInterval(float interval);
};