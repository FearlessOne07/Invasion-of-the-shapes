#pragma once
#include <cstdlib>
#include <memory>
#include <vector>

#include "raylib.h"
#include "raymath.h"

class Player;
class Enemy {
public:
  typedef enum EnemyType : short unsigned int {
    RUNNER = 0,
    DASHER,
    SHOOTER
  } EnemyType;

protected:
  unsigned long _id;
  EnemyType _type;
  std::shared_ptr<Camera2D> _camera;

  std::shared_ptr<Texture> _texture;
  float _textureSize;
  float _textureScale;
  float _radius;

  Vector2 _position;
  Vector2 _velocity;
  float _speed;
  float _perceptionRadius;

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
  Enemy(unsigned long id, EnemyType type, Vector2 position, int score,
        std::shared_ptr<Texture> texture, std::shared_ptr<Camera2D> camera)
      : _id(id), _camera(camera), _position(position), _score(score),
        _texture(texture) {
    _isAlive = true;
    _hasSpawned = false;

    _spawnDuration = 5.f;
    _spawnTimer = 0;
  };

protected:
  void Separate(const std::vector<std::shared_ptr<Enemy>> &enemies) {

    Vector2 totalVel = {0};
    Vector2 avrgVel = {0};
    float count = 0;
    for (const std::shared_ptr<Enemy> &other : enemies) {
      if (other.get() != this) {
        if (other->GetType() != _type) {
          Vector2 diff = Vector2Subtract(_position, other->GetPos());
          float dist = Vector2Length(diff);
          if (dist < _perceptionRadius) {
            totalVel = Vector2Add(diff, totalVel);
            count++;
          }
        }
      }
    }
    if (count > 0) {
      avrgVel = Vector2Scale(totalVel, 1.f / count);
    }
    _velocity = Vector2Add(_velocity, avrgVel);
  }

public:
  virtual void Render() = 0;
  virtual void Update(std::shared_ptr<Player> player,
                      const std::vector<std::shared_ptr<Enemy>> &enemies) = 0;

  // Member Access Functions
  inline float GetRadius() const { return _radius; };

  inline Vector2 GetPos() const { return _position; }
  inline bool isAlive() const { return _isAlive; };
  inline int GetScore() const { return _score; }
  inline int GetHp() const { return _hp; }
  inline bool HasSpawned() const { return _hasSpawned; }
  inline Vector2 GetVelocity() const { return _velocity; }
  inline unsigned long GetId() const { return _id; }
  inline EnemyType GetType() const { return _type; }

  // Memeber Mutation Functions
  inline void SetIsAlive(const bool &isAlive) { _isAlive = isAlive; };
  inline void SetPos(const Vector2 &pos) { _position = pos; };
  inline void SetVelocity(const Vector2 &velocity) { _velocity = velocity; }
  inline void ReduceHp(int value) { _hp -= value; };
};
