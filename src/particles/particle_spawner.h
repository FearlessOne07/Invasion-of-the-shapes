#pragma once
#include "raylib.h"

class ParticleSpawner
{
public:
	virtual ~ParticleSpawner() {};

	virtual void Spawn(Vector2 position, Color color, int sides) = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Reset() = 0;
};
