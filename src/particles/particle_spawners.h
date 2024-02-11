#pragma once
#include "particles.h"
#include <cmath>
#include <algorithm>
#include <vector>

class EnemyChildSpawner
{
private:
	std::vector<EnemyChild> _particles;
public:
	void Update()
	{
		for (EnemyChild& p : _particles)
		{
			p.Update();
		}

		printf("%i\n", _particles.size());

		auto it = std::remove_if(
			_particles.begin(),
			_particles.end(),
			[](EnemyChild& p) {return !p.isAlive(); }
		);

		_particles.erase(it, _particles.end());

	}

	void Render()
	{
		for (EnemyChild& p : _particles)
		{
			p.Render();
		}
	}

	void Spawn(Vector2 position, Color color, int sides)
	{
		float interval = 360.f / sides;

		for (int i = 0; i < sides; i++)
		{
			float deg = i * interval;
			float x = (position.x + std::cos(deg * DEG2RAD) * 10);
			float y = (position.y + std::sin(deg * DEG2RAD) * 10);

			Vector2 velocity = Vector2Subtract({x,y}, position);
			velocity = Vector2Normalize(velocity);

			_particles.emplace_back(EnemyChild(velocity, position, color, sides));
		}
	}
};