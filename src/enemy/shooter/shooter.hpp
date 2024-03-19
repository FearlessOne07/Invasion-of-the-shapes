#pragma once
#include "raylib.h"
#include "enemy.hpp"
#include "bullet/bullet.hpp"
#include <vector>

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
public:
    Shooter(Vector2 position, std::shared_ptr<Texture> bulletTexture);
    void Update(Player& player) override;
    void Render() override;
};