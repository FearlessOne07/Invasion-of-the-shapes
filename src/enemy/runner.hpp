#pragma once
#include "enemy.hpp"
class Runner : public Enemy
{

public:
	// Core
	Runner(Vector2 position, float speed, int score);
	void Update(Player& player) override;
	void Render() override;
	void FollowPlayer(const Vector2& playerPos);
};

