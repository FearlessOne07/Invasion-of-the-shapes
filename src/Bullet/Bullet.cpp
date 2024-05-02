#include <cmath>

#include "Bullet.hpp"

Bullet::Bullet(Vector2 position, Vector2 direction, std::shared_ptr<Texture> textures, BulletTag tag, float speed) 
  :_texture(textures), _position(position), _direction(direction), _tag(tag), _speed(speed)
{
  // Texture
  //_texture = LoadTexture("")
  _textureSize = 16;
  _textureScale = 3;
  _srcRect = { 0 * _textureSize, 0 * _textureSize, _textureSize, _textureSize };
  _rotation = ((std::atan2(direction.y, direction.x)) * RAD2DEG) + 90.f;
  _radius = 10;
  _isActive = true;

}

void Bullet::CheckActivty(std::shared_ptr<Camera2D> camera)
{ 
  // Check and set status of bullet
  Vector2 checkPosition = GetWorldToScreen2D(_position, *camera);
  if
  (
    !(
    ((checkPosition.x <= GetScreenWidth() + _radius) && (checkPosition.x >= -_radius)) &&
    ((checkPosition.y <= GetScreenHeight() + _radius) && (checkPosition.y  >= -_radius))
  )
  )
  {
    SetIsActive(false);
  }

}

void Bullet::Render()
{
  DrawTexturePro(
    *_texture,
    _srcRect,
    { _position.x, _position.y, _textureSize * _textureScale, _textureSize * _textureScale },
    { (_textureSize * _textureScale) / 2, (_textureSize * _textureScale) / 2 },
    _rotation,
    WHITE
  );

}
void Bullet::Update(float &dt, std::shared_ptr<Camera2D> camera) 
{
  CheckActivty(camera);
  _position = Vector2Add(_position, Vector2Scale(_direction, _speed * dt));
}

Vector2 Bullet::GetPos() const
{
  return _position;
}

int Bullet::GetRad() const
{
  return _radius;
}

bool Bullet::isActive() const
{
  return _isActive;
}

void Bullet::SetIsActive(bool active)
{
  _isActive = active;
}

Bullet::BulletTag Bullet::GetTag() const
{
  return _tag;
}
