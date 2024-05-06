#pragma once
#include "raylib.h"
#include <memory>
#include <vector>

class Enemy;
class Player;
class AssetManager;
class Bullet;
class BulletManager;
class EnemyManager {
public:
  typedef enum EnemyType : short unsigned int {
    RUNNER = 0,
    DASHER,
    SHOOTER
  } EnemyType;

private:
  std::shared_ptr<Camera2D> _camera;
  std::shared_ptr<AssetManager> _assets;
  std::shared_ptr<BulletManager> _bulMan;
  std::shared_ptr<Player> _player;

  std::vector<std::shared_ptr<Enemy>> _enemies;

  std::vector<EnemyType> _spawnPool;

private:
  void CheckBulletColissions(std::vector<Bullet> &bullets);
  void CheckPlayerColission();
  void RemoveDeadEnemies();
  bool ValidatePosition(Vector2 position);

public:
  EnemyManager(std::shared_ptr<AssetManager> assets,
               std::shared_ptr<BulletManager> bulletManager,
               std::shared_ptr<Camera2D> camera,
               std::shared_ptr<Player> player);
  void Update();
  void Render();
  void Reset();
  void SpawnWave(int count);
};
