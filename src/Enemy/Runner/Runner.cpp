#include "Runner.hpp"

#include "Player/Player.hpp"
#include "raylib.h"

Runner::Runner(Vector2 position, std::shared_ptr<Texture> texture, std::shared_ptr<Camera2D> camera,
               float speed, int score)
    : Enemy(position, score, texture, camera) {
  _radius = 30;
  _speed = speed;

  _velocity = {0};
  _hp = 30;
}

void Runner::Update(std::shared_ptr<Player> player) {
  float dt = GetFrameTime();

  if (!_hasSpawned) {
    Spawn(dt);
    return;
  }
  FollowPlayer(player->GetPos());
}

void Runner::Render() {
  if (!_hasSpawned) {
    DrawCircleV(_position, _radius, YELLOW);
    return;
  }

  DrawPoly(_position, 3, _radius, 0, YELLOW);
  DrawPolyLines(_position, 3, _radius, 0, WHITE);
}

void Runner::FollowPlayer(const Vector2 &playerPos) {
  float dt = GetFrameTime();
  _velocity = Vector2Subtract(playerPos, _position);
  _velocity = Vector2Normalize(_velocity);
  _velocity = Vector2Scale(_velocity, _speed * dt);
  _position = Vector2Add(_position, _velocity);
}

void Runner::Spawn(float dt) {
  _spawnTimer += dt;
  if (_spawnTimer >= _spawnDuration) {
    _hasSpawned = true;
  }
}
