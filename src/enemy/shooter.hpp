#pragma once
#include <vector>
#include "raylib.h"
#include "enemy.hpp"
#include "utils/bullet/bullet.hpp"

class Shooter : public Enemy
{
private:
    Vector2 _target;
    float _shootInterval;
    float _shootTimer;

    std::shared_ptr<Texture> _bulletTexture;
    std::vector<Bullet> _bullets;
    float _bulletSpeed;

private:
    void Shoot();
    void ApproachPlayer(const Vector2& playerPos, float dt);
public:
    Shooter(Vector2 position, std::shared_ptr<Texture> bulletTexture);
    void Update(Player& player) override;
    void Render() override;
};