#include "enemy.hpp"
#include "player.hpp"
#include <vector>
#include <random>
class EnemyManager
{
private:
    // Enemy Management
    std::vector<Enemy> _enemies{};
    Color _colors[5] = {GREEN, RED, PINK, ORANGE, BLUE};
    int _enemyRadius{};

    // Enemy Spawning
    float _spawnTimer{};
    int _spawnInterval{};

private:
    void SpawnEnemy();
    void SpawnEnemies(float& dt);

public:
    EnemyManager();
    void Update(float &dt, const Vector2 &playerPos);
};