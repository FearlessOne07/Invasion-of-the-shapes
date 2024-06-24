#pragma once
#include <memory>
#include <vector>

#include "Enemy/Enemy.hpp"
#include "raylib.h"

class Player;
class AssetManager;
class Bullet;
class BulletManager;
class EnemyManager {
public:
private:
  std::shared_ptr<Camera2D> _camera;
  std::shared_ptr<AssetManager> _assets;
  std::shared_ptr<BulletManager> _bulMan;
  std::shared_ptr<Player> _player;

  std::vector<std::shared_ptr<Enemy>> _enemies;
  unsigned long _currentID;

  std::vector<Enemy::EnemyType> _spawnPool;

  float _enemyRadius = 50;

private:
  void CheckBulletColissions(std::vector<Bullet> &bullets);
  void CheckPlayerColission();
  void RemoveDeadEnemies();
  bool ValidatePosition(Vector2 position);
  void CheckEnemySeparation();

public:
  EnemyManager(std::shared_ptr<AssetManager> assets,
               std::shared_ptr<BulletManager> bulletManager,
               std::shared_ptr<Camera2D> camera,
               std::shared_ptr<Player> player);
  void Update();
  void Render();
  void Reset();
  void SpawnWave(int count);

  int GetAliveCount();
};
