#include "dasher.h"
#include "raymath.h"
#include "../../player/player.hpp"

Dasher::Dasher(Vector2 position,  int score) : Enemy(position, score)
{
	_rushSpeed = 2000;
	_orbitSpeed = 100;
	_distance = 0;
	_orbitDistance = 200;
	_orbitRotation = 0;
	_speed = 200;
}


void Dasher::RushPlayer(Vector2 playerPos, float& dt)
{
}

void Dasher::OrbitPlayer(Vector2 playerPos, float& dt)
{
	_orbitRotation += dt;
	_position.x = playerPos.x + (std::cos(_orbitRotation) * _orbitDistance);
	_position.y = playerPos.y + (std::sin(_orbitRotation) * _orbitDistance);
}

void Dasher::ApproachPlayer(Vector2 playerPos, float& dt)
{
	_velocity = Vector2Subtract(playerPos, _position);
	_velocity = Vector2Normalize(_velocity);
	_velocity = Vector2Scale(_velocity, _speed * dt);
	_position = Vector2Add(_velocity, _position);
}


void Dasher::Update(Player& player)
{
	float dt = GetFrameTime();
	_distance = Vector2Distance(player.GetPos(), _position);

	if (_distance <= _orbitDistance)
	{
		OrbitPlayer(player.GetPos(), dt);
	}
	else if (_distance > _orbitDistance)
	{
		ApproachPlayer(player.GetPos(), dt);
	}
}

void Dasher::Render()
{
	DrawPoly(_position, 5, 20, 0, PURPLE);
}


