#pragma once
#include <memory>

#include "raylib.h"
#include "raymath.h"

class Bullet {
 public:
  enum BulletTag : short unsigned int { PLAYER_BULLET = 0, ENEMY_BULLET };

 private:
  std::shared_ptr<Camera2D> _camera;

  float _textureSize;
  std::shared_ptr<Texture> _texture;
  Rectangle _srcRect;
  float _textureScale;
  float _rotation;
  int _radius;

  bool _isActive;
  Vector2 _position;
  Vector2 _direction;
  int _speed;

  BulletTag _tag;

 private:
  void CheckActivty();

 public:
 public:
  Bullet(Vector2 position, Vector2 direction, std::shared_ptr<Texture> _texture,
         std::shared_ptr<Camera2D> camera, BulletTag tag, float speed);
  void Render();
  void Update(float &dt);
  Vector2 GetPos() const;
  int GetRad() const;
  bool isActive() const;
  void SetIsActive(bool active);
  BulletTag GetTag() const;
};
