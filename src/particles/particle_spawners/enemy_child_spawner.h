#pragma once
#include "../particles/enemy_child.h"
#include "../particle_spawner.h"
#include <cmath>
#include <algorithm>
#include <vector>

class EnemyChildSpawner : ParticleSpawner
{
private:
	std::vector<EnemyChild> _particles;
public:
	EnemyChildSpawner()
	{
		_particles = {};
	}

	void Update() override
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

	void Render() override
	{
		for (EnemyChild& p : _particles)
		{
			p.Render();
		}
	}

	void Spawn(Vector2 position, Color color, int sides) override
	{
		const float interval = 360.f / sides;

		for (int i = 0; i < sides; i++)
		{
			const float deg = i * interval;
			const float x = (position.x + std::cos(deg * DEG2RAD));
			const float y = (position.y + std::sin(deg * DEG2RAD));

			Vector2 velocity = Vector2Subtract({ x,y }, position);
			velocity = Vector2Normalize(velocity);

			_particles.push_back(EnemyChild(velocity, position, color, sides));
		}
	}

	void Reset() override
	{
		_particles.clear();
		_particles.shrink_to_fit();
	}
};