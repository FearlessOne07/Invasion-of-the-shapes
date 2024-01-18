#include "player.hpp"

Player::Player(Vector2 position, Color color) : _position(position), _color(color)
{
    // Initialize Player
    radius = 50;
    _sides = 6;
    _speed = 500;
    _rotationSpeed = -200;
    _isDead = false;
}

void Player::GetInput()
{
    // Get Player Input
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
    // Update Player Positions
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

void Player::CheckBounds()
{
    // Check Player Collisions With Window
    if (_position.x <= radius)
    {
        _position.x = radius;
    }
    if (_position.y <= radius)
    {
        _position.y = radius;
    }
    if (_position.y >= GetScreenHeight() - radius)
    {
        _position.y = GetScreenHeight() - radius;
    }
    if (_position.x >= GetScreenWidth() - radius)
    {
        _position.x = GetScreenWidth() - radius;
    }
}

void Player::Update(float &dt)
{
    GetInput();
    UpdatePositions(dt);
    CheckBounds();
    UpdateRotaion(dt);
}

void Player::Render()
{
    DrawPolyLinesEx(_position, _sides, radius, _rotation, 7, _color);
}

Vector2 const Player::GetPos() const
{
    return _position;
}

const bool Player::GetDead() const
{
    return _isDead;
}

void Player::SetDead(const bool &input)
{
    _isDead = input;
}

void Player::SetPos(const Vector2 &pos)
{
    _position = pos;
}
