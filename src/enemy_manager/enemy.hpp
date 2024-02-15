#pragma once
#include <memory>
#include "raylib.h"
#include "raymath.h"
#include "../particles/enemy_child_spawner.h"

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

    // Particles
    std::shared_ptr<EnemyChildSpawner> _particleSpawner;

private:
    Enemy(Color &color, int &sides, Vector2 &position, int &radius, float &speed, std::shared_ptr<EnemyChildSpawner> spawner) noexcept;
    void FollowPlayer(float &dt, const Vector2 &playePos);
    void UpdateRotation(float &dt) noexcept;

public:
    friend class EnemyManager;
    void Update(const Vector2 &playerPos, float &dt);
    void Render();
    void Die();
    bool GetDead() const;
    void SetDead(bool input);
    Vector2 GetPos() const;
};