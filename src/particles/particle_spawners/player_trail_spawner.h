#pragma once
#include "../particle_spawner.h"
class PlayerTrailSpawner : public ParticleSpawner
{
	// Inherited via ParticleSpawner
	void Spawn(Vector2 position, Color color, int sides) override;
	void Update() override;
	void Render() override;
	void Reset() override;
};
