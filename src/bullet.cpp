#include "bullet.hpp"

Bullet::Bullet(Vector2 position, Vector2 direction) : _position(position), _direction(direction)
{
    _opacity = 255;
    _opacityChange = 200;
    _radius = 20;
    _speed = 10;
    _direction = Vector2Scale(_direction, _speed);
    _isActive = true;
}

void Bullet::CheckActivty()
{
    // Check and set status of bullet
    if (_opacity <= 0)
    {
        SetIsActive(false);
    }
}

void Bullet::Render()
{
    DrawCircle(_position.x, _position.y, _radius, {255, 255, 255, _opacity});
}

void Bullet::Update(float &dt)
{
    if (_opacity > 0)
    {
        _opacity -= _opacityChange * dt;
    }
    CheckActivty();
    _position = Vector2Add(_position, _direction);
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
