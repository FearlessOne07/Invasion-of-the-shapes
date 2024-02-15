#pragma once
#include "enemy_child.h"
#include <cmath>
#include <algorithm>
#include <vector>

class EnemyChildSpawner
{
private:
	std::vector<EnemyChild> _particles;
public:
	EnemyChildSpawner() noexcept
	{
		_particles = {};
	}

	void Update()
	{
		for (EnemyChild& p : _particles)
		{
			p.Update();
		}

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
		const float interval = 360.f / sides;

		for (int i = 0; i < sides; i++)
		{
			const float deg = i * interval;
			const float x = (position.x + std::cos(deg * DEG2RAD) * 10);
			const float y = (position.y + std::sin(deg * DEG2RAD) * 10);

			Vector2 velocity = Vector2Subtract({ x,y }, position);
			velocity = Vector2Normalize(velocity);

			_particles.push_back(EnemyChild(velocity, position, color, sides));
		}
	}

	void Reset()
	{
		_particles.clear();
		_particles.shrink_to_fit();
	}
};