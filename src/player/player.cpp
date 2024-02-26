#include "player.hpp"
#include <iostream>
#include "../asset_manager/asset_manager.h"

Player::Player(Vector2 position, Color color, std::shared_ptr<AssetManager> assets) :_assets(assets), _position(position)
{
	//--------Initialize Player--------

	// Texture
	_textureSize = 8.f;
	_texture = _assets->GetTexture("entities");
	_textureCords = { 1,0 };
	_scale = 7;

	// Movement
	_speed = 500;
	_rotationSpeed = -200;
	_isDead = false;

	// Fizix
	_radius = (_textureSize / 2 * _scale);

	_config = Config::GetInstance();
	if (_config)
	{
		_data = _config->GetData("player_data");
	}

	_score = 0;
	_highscore = _data["highscore"].asInt();

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

void Player::UpdatePositions(float& dt)
{
	// Update Player Positions
	if (_velocity.x || _velocity.y)
	{
		_velocity = Vector2Normalize(_velocity);
		_velocity = Vector2Scale(_velocity, _speed * dt);
		_position = Vector2Add(_position, _velocity);
		_velocity = { 0 };
	}
}

void Player::UpdateRotaion(float& dt)
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

void Player::Update(float& dt)
{
	GetInput();
	UpdatePositions(dt);
	CheckBounds();
	//UpdateRotaion(dt);
}

void Player::Render()
{


	DrawTexturePro(
		*_texture,
		{ _textureCords.x * _textureSize, _textureCords.y * _textureSize, _textureSize, _textureSize },
		{ _position.x, _position.y,_textureSize * _scale, _textureSize * _scale },
		{ (_textureSize * _scale) / 2, (_textureSize * _scale) / 2 },
		_rotation,
		WHITE
	);
	DrawCircleLines(_position.x , _position.y ,_radius, RED);
}

void Player::Reset()
{
	SetPos({ (float)(GetScreenWidth() / 2), (float)(GetScreenHeight() / 2) });

	SetDead(false);
	if (_score > _highscore)
	{
		_highscore = _score;
	}
	_data["highscore"] = _highscore;
	_config->SetData(_data, "player_data");
	_score = 0;
}

Vector2 const Player::GetPos() const
{
	return _position;
}

const bool Player::GetDead() const
{
	return _isDead;
}

void Player::SetDead(const bool& input)
{
	_isDead = input;
}

int Player::GetScore() const
{
	return _score;
}

void Player::SetScore(int score)
{
	_score = score;
}

int Player::GetHighScore() const
{
	return _highscore;
}

void Player::SetHighScore(int score)
{
	_highscore = score;
}

void Player::SetPos(const Vector2& pos)
{
	_position = pos;
}


