#pragma once
#include "raylib.h"
#include "raymath.h"
#include <iostream>
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
    void UpdatePositions(float &dt);
    void UpdateRotaion(float &dt);

public:
    Player(Vector2 position, Color color);
    void Update(float &dt);
    void Render();
    Vector2 const GetPos() const;
};