#include "player.hpp"

Player::Player(Vector2 position, Color color) : _position(position), _color(color)
{
    _radius = 50;
    _sides = 6;
    _speed = 1000;
}

void Player::GetInput()
{
}

void Player::Update(float &dt)
{
}

void Player::Render()
{
    DrawPolyLinesEx(_position, _sides, _radius, _rotation, 7, _color);
}
