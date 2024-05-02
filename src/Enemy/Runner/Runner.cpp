#include "Runner.hpp"
#include "Player/Player.hpp"

Runner::Runner(Vector2 position, std::shared_ptr<Texture> texture, float speed, int score) : 
	Enemy(position,score, texture)
{
	_radius = 30;
	_speed = speed;

	_velocity = { 0 };
	_hp = 30;
}

void Runner::Update(Player& player, std::shared_ptr<Camera2D> camera)
{
	FollowPlayer(player.GetPos());
}

void Runner::Render()
{
	DrawPoly(_position, 3, _radius, 0, YELLOW);
	DrawPolyLines(_position, 3, _radius, 0,WHITE);
}

void Runner::FollowPlayer(const Vector2& playerPos)
{
	float dt = GetFrameTime();
	_velocity = Vector2Subtract(playerPos, _position);
	_velocity = Vector2Normalize(_velocity);
	_velocity = Vector2Scale(_velocity, _speed * dt);
	_position = Vector2Add(_position, _velocity);
}
