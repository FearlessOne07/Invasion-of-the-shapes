#pragma once
#include <cstdlib>
#include <memory>

#include "raylib.h"

class Player;
class Enemy {
protected:
  std::shared_ptr<Camera2D> _camera;

  std::shared_ptr<Texture> _texture;
  float _textureSize;
  float _textureScale;
  float _radius;

  Vector2 _position;
  Vector2 _velocity;
  float _speed;

  bool _isAlive;
  int _score;

  bool _hasSpawned;
  float _spawnTimer;
  float _spawnDuration;

  int _hp;

protected:
  virtual void Spawn(float dt) = 0;

public:
  virtual ~Enemy(){};
  Enemy(Vector2 position, int score, std::shared_ptr<Texture> texture,
        std::shared_ptr<Camera2D> camera)
      : _camera(camera), _position(position), _score(score), _texture(texture) {
    _isAlive = true;
    _hasSpawned = false;

    _spawnDuration = 5.f;
    _spawnTimer = 0;
  };

  virtual void Update(std::shared_ptr<Player> player) = 0;
  virtual void Render() = 0;

  // Member Access Functions
  inline float GetRadius() const { return _radius; };

  inline Vector2 GetPos() const { return _position; }
  inline bool isAlive() const { return _isAlive; };
  inline int GetScore() const { return _score; }
  inline int GetHp() const { return _hp; }
  inline bool HasSpawned() const { return _hasSpawned; }
  inline Vector2 GetVelocity() const { return _velocity; }

  // Memeber Mutation Functions
  inline void SetIsAlive(const bool &isAlive) { _isAlive = isAlive; };
  inline void SetPos(const Vector2 &pos) { _position = pos; };
  inline void SetVelocity(const Vector2 &velocity) { _velocity = velocity; }
  inline void ReduceHp(int value) { _hp -= value; };
};
