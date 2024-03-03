#pragma once
#include "../enemy.h"
class Runner : public Enemy
{

public:
	// Core
	Runner(Vector2 position, float speed);
	void Update(Player& player) override;
	void Render() override;
	void FollowPlayer(const Vector2& playerPos);
};

