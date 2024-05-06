#pragma once

#include "Enemy/Enemy.hpp"
#include "raymath.h"
#include <memory>


class Runner : public Enemy
{

private:
  void Spawn(float dt) override;
public:
	// Core
	Runner(Vector2 position,std::shared_ptr<Texture> texture, std::shared_ptr<Camera2D> camera, float speed, int score );
	void Update(std::shared_ptr<Player> player) override;
	void Render() override;
	void FollowPlayer(const Vector2& playerPos);
};

