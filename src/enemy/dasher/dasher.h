#pragma once
#include "../enemy.h"
class Dasher : public  Enemy
{
private:
	float _rushSpeed;
	float _orbitSpeed;
	float _distance;
	float _orbitDistance;
	float _orbitRotation;
private:
	void RushPlayer(Vector2 playerPos, float& dt);
	void OrbitPlayer(Vector2 playerPos, float& dt);
	void ApproachPlayer(Vector2 playerPos, float& dt);
public:
	Dasher(Vector2 position, int score);
	void Update(Player& player) override;
	void Render() override;
};

