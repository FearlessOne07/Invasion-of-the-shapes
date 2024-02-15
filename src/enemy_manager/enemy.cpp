#include "enemy.hpp"

Enemy::Enemy(Color &color, int &sides, Vector2 &position, int &radius, float &speed, std::shared_ptr<EnemyChildSpawner> spawner) noexcept
    : _color(color), _sides(sides), _position(position), _radius(radius), _speed(speed), _particleSpawner(spawner)
{
    _roationSpeed = -100;
}

void Enemy::FollowPlayer(float &dt, const Vector2 &playePos)
{   
    // Update enemy velocity based on player's location
    _velocity = Vector2Subtract(playePos, _position);
    _velocity = Vector2Normalize(_velocity);
    _velocity = Vector2Scale(_velocity, _speed * dt);
    _position = Vector2Add(_position, _velocity);
}

void Enemy::UpdateRotation(float &dt) noexcept
{
    _rotaion += _roationSpeed * dt;
}
void Enemy::Update(const Vector2 &playerPos, float &dt)
{
    FollowPlayer(dt, playerPos);
    UpdateRotation(dt);
}

void Enemy::Render()
{
    DrawPoly(_position, _sides, _radius, _rotaion, _color);
    DrawPolyLinesEx(_position, _sides, _radius, _rotaion, 4, WHITE);
}

void Enemy::Die()
{
    _particleSpawner->Spawn(_position, _color, _sides);
}

void Enemy::SetDead(bool input)
{
    _isDead = true;
}

Vector2 Enemy::GetPos() const
{
    return _position;
}

bool Enemy::GetDead() const
{
    return _isDead;
}
