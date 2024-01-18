#pragma once
#include "raylib.h"
#include "raymath.h"

class Bullet
{
private:
    int _radius;
    unsigned char _opacityChange;
    unsigned char _opacity;
    bool _isActive;

    Vector2 _position;
    Vector2 _direction; 
    int _speed;

private:
    void CheckActivty();

public:
public:
    Bullet( Vector2 position, Vector2 direction);
    void Render();
    void Update(float &dt);
    Vector2 GetPos() const;
    int GetRad() const;
    bool isActive() const;
    void SetIsActive(bool active);
};