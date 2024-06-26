#pragma once
#include <memory>
#include <vector>

#include "Enemy/Enemy.hpp"
#include "Player/Player.hpp"
#include "raylib.h"

class BulletManager;
class Shooter : public Enemy {
private:
  Vector2 _target;
  float _attackDistance;

  float _shootInterval;
  float _shootTimer;
  bool _isTracking;

  std::shared_ptr<Texture> _bulletTexture;
  std::shared_ptr<BulletManager> _bulMan;
  float _bulletSpeed;

  float _rotation;
  float _rotationSpeed;

private:
  void Spawn(float dt) override;
  void Shoot();
  void ApproachPlayer(const Vector2 &playerPos, float dt);
  void Attack(const Vector2 &playerPos, float dt);

public:
  Shooter(unsigned long id, EnemyType type, Vector2 position, float speed,
          std::shared_ptr<Texture> texture,
          std::shared_ptr<Texture> bulletTexture,
          std::shared_ptr<Camera2D> camera,
          std::shared_ptr<BulletManager> bulMan);

  void Update(std::shared_ptr<Player> player,
              const std::vector<std::shared_ptr<Enemy>> &enemies) override;
  void Render() override;
};
