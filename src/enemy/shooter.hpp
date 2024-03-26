#pragma once
#include <vector>
#include "raylib.h"
#include "enemy.hpp"
#include "utils/bullet/bullet.hpp"

class BulletManager;
class Shooter : public Enemy
{
private:
    Vector2 _target;
    float _attackDistance;
    

    float _shootInterval;
    float _shootTimer;
    bool _isTracking;

    std::shared_ptr<Texture> _bulletTexture;
    std::shared_ptr<BulletManager> _bulMan;
    float _bulletSpeed;


    float _rotation;
    float _rotationSpeed;

private:
    void Shoot();
    void ApproachPlayer(const Vector2& playerPos, float dt);
    void Attack(const Vector2& playerPos, float dt);
public:
    Shooter(
        Vector2 position, 
        std::shared_ptr<Texture> bulletTexture,
        std::shared_ptr<BulletManager> bulMan
    );
    void Update(Player& player) override;
    void Render() override;
};