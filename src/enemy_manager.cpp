#include "enemy_manager.hpp"

EnemyManager::EnemyManager()
{
    _enemyRadius = 50;
    _spawnInterval = 5;
}

void EnemyManager::SpawnEnemy()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    // Color & Sides
    std::uniform_int_distribution<int> colorDist(0, (sizeof(_colors) / sizeof(Color)) - 1);
    Color color = _colors[colorDist(gen)];
    std::uniform_int_distribution<int> sidesDist(3, 8);
    int sides = sidesDist(gen);

    // Position
    std::uniform_int_distribution<int> sideDist(0, 3);
    std::uniform_real_distribution<float> distX(-100, GetScreenWidth() + 100);
    std::uniform_real_distribution<float> distY(-100, GetScreenHeight() + 100);

    Vector2 position;
    int side = sideDist(gen);

    switch (side)
    {
    case 0: // UP
        position = {distX(gen), -100};
        break;
    case 1: // DOWN
        position = {distX(gen), (float)(GetScreenHeight()) + 100};
        break;
    case 2: // LEFT
        position = {-100, distY(gen)};
        break;
    case 3: // RIGHT
        position = {(float)(GetScreenWidth()) + 100, distY(gen)};
        break;
    default:
        position = {0, 0};
        break;
    }
    _enemies.push_back(Enemy(color, sides, position, _enemyRadius));
}
void EnemyManager::SpawnEnemies(float &dt)
{
    _spawnTimer += dt;
    if (_spawnTimer >= _spawnInterval)
    {
        _spawnTimer = 0;
        SpawnEnemy();
    }
}
void EnemyManager::Update(float &dt, const Vector2 &playerPos)
{
    SpawnEnemies(dt);
    for (Enemy &enemy : _enemies)
    {
        enemy.Update(playerPos, dt);
        enemy.Render();
    }
}
