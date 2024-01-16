#pragma once
#include "raylib.h"
#include "raymath.h"
class EnemyManager;
class Enemy
{
private:
    Color _color{};
    int _sides{};
    int _radius{};
    float _rotaion{};
    float _roationSpeed{};

    Vector2 _position{};
    Vector2 _velocity{};
    float _speed{};

    bool _isDead{};

private:
    Enemy(Color &color, int &sides, Vector2 &position, int &radius, int &speed);
    void FollowPlayer(float &dt, const Vector2 &playePos);
    void UpdateRotation(float &dt);

public:
    friend class EnemyManager;
    void Update(const Vector2 &playerPos, float &dt);
    void Render();
    bool GetAlive();
};