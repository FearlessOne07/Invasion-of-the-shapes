#pragma once
#include <memory>
#include "raylib.h"

class Player;
class Enemy
{
protected:
	std::shared_ptr<Texture> _texture;
	float _textureSize;
	float _textureScale;
	float _radius;

	Vector2 _position;
	Vector2 _velocity;
	float _speed;

	bool _isAlive;
	int _score;

	int _hp;
public:
	virtual ~Enemy(){};
	Enemy(Vector2 position, int score, std::shared_ptr<Texture> texture) : 
		_position(position), _score(score), _texture(texture)
	{
		_isAlive = true;
	};
	virtual void Update(Player &player, std::shared_ptr<Camera2D> camera) = 0;
	virtual void Render() = 0;

	// Member Access Functions
	inline float GetRadius() const { return _radius; };
	inline Vector2 GetPos() const { return _position; }
	inline bool isAlive() const { return _isAlive; };
	inline int GetScore() const { return _score; }
  inline int GetHp() const { return _hp; }
	// Memeber Mutation Functions
	inline void SetIsAlive(const bool &isAlive) { _isAlive = isAlive; };
	inline void SetPos(const Vector2 &pos) { _position = pos; };
  inline void ReduceHp(int value) { _hp -= value; };

};
