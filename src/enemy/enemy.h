#pragma once
#include "raylib.h"
class Player;
class Enemy
{
protected:
	Texture _texture{};
	float _radius{};


	Vector2 _position{};
	Vector2 _velocity{};
	float _speed{};
public:
	virtual ~Enemy() {};
	Enemy(Vector2 position) :_position(position) {
	};
	virtual void Update(Player& player) = 0;
	virtual void Render() = 0;

	// Member Access Functions
	float GetRadius() const { return _radius; };
};