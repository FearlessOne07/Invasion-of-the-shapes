#include "Shooter.hpp"

#include <algorithm>

#include "Core/BulletManager/BulletManager.hpp"
#include "Player/Player.hpp"
#include "raylib.h"

Shooter::Shooter(Vector2 position, float speed, std::shared_ptr<Texture> texture,
                 std::shared_ptr<Texture> bulletTexture, std::shared_ptr<Camera2D> camera,
                 std::shared_ptr<BulletManager> bulMan)
    : Enemy(position, 200, texture, camera),
      _bulletTexture(bulletTexture),
      _bulMan(bulMan) {
  _textureSize = _texture->width;
  _textureScale = 6;
  _radius = 50;

  _speed = speed;

  _shootInterval = 4.f;
  _shootTimer = 0.f;
  _attackDistance = 700.f;

  _rotationSpeed = 50.f;
  _rotation = 0;

  _isTracking = true;
  _bulletSpeed = 300.f;

  _hp = 50;
}

void Shooter::Update(std::shared_ptr<Player> player) {
  float dt = GetFrameTime();

  if (!_hasSpawned) {
    Spawn(dt);
    return;
  }

  Vector2 screenCords = GetWorldToScreen2D(_position, *_camera);
  _target = player->GetPos();
  float distance = Vector2Distance(_position, _target);

  if ((distance < _attackDistance) &&
      ((screenCords.x >= (_radius + 50)) && (screenCords.y >= (_radius + 50)) &&
       (screenCords.x <= GetScreenWidth() - (_radius + 50)) &&
       (screenCords.y <= GetScreenHeight() - (_radius + 50)))) {
    _isTracking = false;
  } else {
    _isTracking = true;
  }

  if (_isTracking) {
    ApproachPlayer(player->GetPos(), dt);
  } else {
    Attack(player->GetPos(), dt);
  }
  _rotation += _rotationSpeed * dt;
}

void Shooter::Render() {
  if (!_hasSpawned) {
    DrawCircleV(_position, _radius, PURPLE);
    return;
  }

  DrawTexturePro(*_texture, {0, 0, _textureSize, _textureSize},
                 {_position.x, _position.y, _textureSize * _textureScale,
                  _textureSize * _textureScale},
                 {(_textureSize * _textureScale) / 2, (_textureSize * _textureScale) / 2},
                 _rotation, WHITE);
}

void Shooter::Shoot() {
  _bulMan->SpawnBullet(_position, _target, Bullet::ENEMY_BULLET, _bulletSpeed);
}

void Shooter::ApproachPlayer(const Vector2 &playerPos, float dt) {
  _rotationSpeed -= 90.f * dt;
  _rotationSpeed = std::max<float>(_rotationSpeed, 50.f);

  _velocity = Vector2Subtract(playerPos, _position);
  _velocity = Vector2Normalize(_velocity);
  _velocity = Vector2Scale(_velocity, _speed * dt);
  _position = Vector2Add(_position, _velocity);
}

void Shooter::Attack(const Vector2 &playerPos, float dt) {
  _shootTimer += dt;
  _rotationSpeed += 150.f * dt;
  _rotationSpeed = std::min<float>(_rotationSpeed, 300.f);
  if (_shootTimer >= _shootInterval) {
    _shootTimer = 0;
    Shoot();
  }
}

void Shooter::Spawn(float dt) {
  _spawnTimer += dt;
  if (_spawnTimer > _spawnDuration) {
    _hasSpawned = true;
  }
}
