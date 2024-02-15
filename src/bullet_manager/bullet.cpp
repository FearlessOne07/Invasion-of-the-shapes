#include "bullet.hpp"
#include <algorithm>

Bullet::Bullet(Vector2 position, Vector2 direction) : _position(position), _direction(direction)
{
    _opacity = 255;
    _opacityChange = 250;
    _radius = 20;
    _speed = 1000;
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
    DrawCircle(_position.x, _position.y, _radius, {255, 255, 255, static_cast<unsigned char>(_opacity)});
}

void Bullet::Update(float &dt) 
{
    _opacity -= _opacityChange * dt;
    _opacity = std::max(_opacity, 0.f);

    CheckActivty();
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
