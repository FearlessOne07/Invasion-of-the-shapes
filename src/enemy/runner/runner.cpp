#include "runner.h"
#include "../../player/player.hpp"
Runner::Runner(Vector2 position, float speed) : Enemy(position)
{
	_radius = 20;
	_speed = speed;
}

void Runner::Update(Player& player)
{
	FollowPlayer(player.GetPos());
}

void Runner::Render()
{
	DrawPoly(_position, 3, _radius, 0, YELLOW);
}

void Runner::FollowPlayer(const Vector2& playerPos)
{
	float dt = GetFrameTime();
	_velocity = Vector2Subtract(playerPos, _position);
	_velocity = Vector2Normalize(_velocity);
	_velocity = Vector2Scale(_velocity, _speed * dt);
	_position = Vector2Add(_position, _velocity);
}

