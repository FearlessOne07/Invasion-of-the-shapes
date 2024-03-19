#pragma once
#include <vector>
#include <algorithm>
#include <memory>
#include "raylib.h"
#include "utils/bullet/bullet.hpp"
#include "asset_manager/asset_manager.hpp"

class BulletManager
{
private:
    std::vector<Bullet> _bullets;
    float _cooldown;
    float _cooldownTimer;

    std::shared_ptr<AssetManager> _assets;
    std::shared_ptr<Sound> _bulletShoot;

private:
    void CheckBullets();

public:
    BulletManager(std::shared_ptr<AssetManager> assets);
    void SpawnBullet(const Vector2 &playerPos, const Vector2 &mousePos);
    void Update(float &dt);
    void Reset();
    std::vector<Bullet> &GetBullets();
};