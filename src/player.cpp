#include "player.hpp"

Player::Player(Vector2 position, Color color) : _position(position), _color(color)
{
    _radius = 50;
    _sides = 6;
    _speed = 500;
    _rotationSpeed = -200;
}

void Player::GetInput()
{
    if (IsKeyDown(KEY_D))
    {
        _velocity.x += 1;
    }
    if (IsKeyDown(KEY_A))
    {
        _velocity.x -= 1;
    }
    if (IsKeyDown(KEY_S))
    {
        _velocity.y += 1;
    }
    if (IsKeyDown(KEY_W))
    {
        _velocity.y -= 1;
    }
}

void Player::UpdatePositions(float &dt)
{
    if (_velocity.x || _velocity.y)
    {
        _velocity = Vector2Normalize(_velocity);
        _velocity = Vector2Scale(_velocity, _speed * dt);
        _position = Vector2Add(_position, _velocity);
        _velocity = Vector2Zero();
    }
}

void Player::UpdateRotaion(float &dt)
{
    _rotation += _rotationSpeed * dt;
}

void Player::Update(float &dt)
{
    GetInput();
    UpdatePositions(dt);
    UpdateRotaion(dt);
}

void Player::Render()
{
    DrawPolyLinesEx(_position, _sides, _radius, _rotation, 7, _color);
}
