#pragma once
#include "raylib.h"

class Player
{
private:
    Vector2 _position{};
    Vector2 _velocity{};
    float _speed{};

    int _sides{};
    Color _color{};
    int _radius{};

    float _rotationSpeed{};
    float _rotation{};

private:
    void GetInput();

public:
    Player(Vector2 position, Color color);
    void Update(float &dt);
    void Render();
};