#include "Core/EnemyManager/EnemyManager.hpp"

#include <algorithm>
#include <climits>
#include <cmath>
#include <memory>
#include <random>

#include "Bullet/Bullet.hpp"
#include "Core/BulletManager/BulletManager.hpp"
#include "Enemy/Enemy.hpp"
#include "Enemy/Runner/Runner.hpp"
#include "Enemy/Shooter/Shooter.hpp"
#include "Player/Player.hpp"
#include "raylib.h"
#include "raymath.h"

EnemyManager::EnemyManager(std::shared_ptr<AssetManager> assets,
                           std::shared_ptr<BulletManager> bulletManager,
                           std::shared_ptr<Camera2D> camera, std::shared_ptr<Player> player)
    : _assets(assets), _bulMan(bulletManager), _camera(camera), _player(player) {
  _enemies = {};
  _spawnPool = {RUNNER, SHOOTER};
}

void EnemyManager::CheckBulletColissions(std::vector<Bullet> &bullets) {
  for (Bullet &b : bullets) {
    if (b.GetTag() == Bullet::PLAYER_BULLET) {
      for (std::shared_ptr<Enemy> &e : _enemies) {
        if ((CheckCollisionCircles(e->GetPos(), e->GetRadius(), b.GetPos(), b.GetRad())) &&
            e->GetHp() > 0) {
          b.SetIsActive(false);
          e->ReduceHp(_player->GetDamage());
        } else if (CheckCollisionCircles(e->GetPos(), e->GetRadius(), b.GetPos(), b.GetRad())) {
          e->SetIsAlive(false);
          _player->SetScore(e->GetScore() + _player->GetScore());
        }
      }
    }
  }
}

void EnemyManager::CheckPlayerColission() {
  for (std::shared_ptr<Enemy> &e : _enemies) {
    if (CheckCollisionCircles(e->GetPos(), e->GetRadius(), _player->GetPos(),
                              _player->GetRaduis())) {
      _player->SetDead(true);
    }
  }
}

void EnemyManager::RemoveDeadEnemies() {
  auto it = std::remove_if(_enemies.begin(), _enemies.end(),
                           [](std::shared_ptr<Enemy> &e) { return !e->isAlive(); });
  _enemies.erase(it, _enemies.end());
}

void EnemyManager::Update() {
  for (std::shared_ptr<Enemy> &e : _enemies) {
    e->Update(_player);
  }
  CheckBulletColissions(_bulMan->GetBullets());
  CheckPlayerColission();
  RemoveDeadEnemies();
}

void EnemyManager::Render() {
  for (std::shared_ptr<Enemy> &e : _enemies) {
    e->Render();
  }
}

void EnemyManager::Reset() { _enemies.clear(); }

void EnemyManager::SpawnWave(int count) {
  std::random_device rd;
  std::mt19937_64 gen(rd());

  // Type
  std::uniform_int_distribution<int> poolDist(0, _spawnPool.size() - 1);

  // Location
  std::uniform_real_distribution<float> angleDist(0, 360);
  std::uniform_real_distribution<float> radiusDist(300.f, 500.f);

  Vector2 position;

  std::uniform_real_distribution<float> speedDist(100.f, 200.f);

  for (int i = 0; i < count; ++i) {
    std::shared_ptr<Enemy> enemy;
    EnemyType type = _spawnPool[poolDist(gen)];

    do {
      position.x = _player->GetPos().x + (std::cos(angleDist(gen)) * radiusDist(gen));
      position.y = _player->GetPos().y + (std::sin(angleDist(gen)) * radiusDist(gen));
    } while (!ValidatePosition(position));

    switch (type) {
      case RUNNER:
        enemy = std::make_shared<Runner>(position, nullptr, _camera, speedDist(gen), 300);
        break;
      case SHOOTER:
        enemy = std::make_shared<Shooter>(position, _assets->GetTexture("shooter"),
                                          _assets->GetTexture("bullet"), _camera, _bulMan);
    }
    _enemies.push_back(enemy);
  }
}

bool EnemyManager::ValidatePosition(Vector2 position) {
  for (auto &e : _enemies) {
    float distance = Vector2Distance(e->GetPos(), _player->GetPos());

    if (distance < e->GetRadius() * 2) {
      return false;
    }
  }

  return true;
}
