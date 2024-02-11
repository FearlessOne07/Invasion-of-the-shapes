#pragma once
#include "raymath.h"

class EnemyChild
{
private:
	Color _color;
	int _sides;
	int _radius;
	float _speed;

	float _rotationSpeed;
	float _rotation;

	float _opacity;
	float _opacityChange;

	Vector2 _velocity;
	Vector2 _position;

	bool _alive;

public:
	EnemyChild(Vector2 velocity, Vector2 position, Color color, int sides) 
		: _velocity(velocity), _position(position), _color(color), _sides(sides)
	{
		_alive = true;
		_radius = 20;
		_speed = 100.f;

		// Rotaion
		_rotation = 0;
		_rotationSpeed = 200;

		// Opacity

		_opacity = 255.f;
		_opacityChange = 200;
	}

	void Update()
	{
		float dt = GetFrameTime();

		// Opacity
		_opacity -= _opacityChange * dt;
		_opacity = std::max(_opacity, 0.f);
		if (_opacity <= 0)
		{
			_alive = false;
		}

		// Rotation
		_rotation += _rotationSpeed * dt;

		// Position
		_position = Vector2Add(_position, Vector2Scale(_velocity, _speed * dt));
	}

	void Render()
	{
		DrawPoly(_position, _sides, _radius, _rotation, {_color.r, _color.g, _color.b, (unsigned char)_opacity});
		DrawPolyLines(_position, _sides, _radius, _rotation, {255,255,255,(unsigned char)_opacity});
	}

	bool isAlive() const
	{
		return _alive;
	}
};