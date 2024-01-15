#include "enemy.hpp"
Enemy::Enemy(Color &color, int &sides, Vector2 &position, int &radius) : _color(color), _sides(sides), _position(position), _radius(radius)
{
    _speed = 100;
}

void Enemy::FollowPlayer(float &dt, const Vector2 &playePos)
{
    _velocity = Vector2Subtract(playePos, _position);
    _velocity = Vector2Normalize(_velocity);
    _velocity = Vector2Scale(_velocity, _speed * dt);
    _position = Vector2Add(_position, _velocity);
}

void Enemy::Update(const Vector2 &playerPos, float &dt)
{
    FollowPlayer(dt, playerPos);
}

void Enemy::Render()
{
    DrawPoly(_position, _sides, _radius, 0, _color);
    DrawPolyLinesEx(_position, _sides, _radius, 0, 4, WHITE);
}
