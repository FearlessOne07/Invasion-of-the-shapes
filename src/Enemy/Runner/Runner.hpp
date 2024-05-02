#pragma once

#include "Enemy/Enemy.hpp"
#include "raymath.h"


class Runner : public Enemy
{

public:
	// Core
	Runner(Vector2 position,std::shared_ptr<Texture> texture,  float speed, int score );
	void Update(Player& player, std::shared_ptr<Camera2D> camera) override;
	void Render() override;
	void FollowPlayer(const Vector2& playerPos);
};

