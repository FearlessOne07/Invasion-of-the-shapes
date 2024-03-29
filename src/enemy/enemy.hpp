#pragma once
#include <memory>
#include "raylib.h"

class Player;
class Enemy
{
protected:
	std::shared_ptr<Texture> _texture;
	float _radius;

	Vector2 _position;
	Vector2 _velocity;
	float _speed;

	bool _isAlive;
	int _score;

public:
	virtual ~Enemy(){};
	Enemy(Vector2 position, int score) : _position(position), _score(score)
	{
		_isAlive = true;
	};
	virtual void Update(Player &player) = 0;
	virtual void Render() = 0;

	// Member Access Functions
	float GetRadius() const { return _radius; };
	Vector2 GetPos() const { return _position; }
	bool isAlive() const { return _isAlive; };
	int GetScore() const { return _score; }

	// Memeber Mutation Functions
	void SetIsAlive(const bool &isAlive) { _isAlive = isAlive; };
	void SetPos(const Vector2 &pos) { _position = pos; };
};