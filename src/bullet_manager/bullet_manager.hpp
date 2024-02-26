#pragma once
#include "raylib.h"
#include <vector>
#include "bullet.hpp"
#include <algorithm>
#include "../asset_manager/asset_manager.h"
#include <memory>

class BulletManager
{
private:
    std::vector<Bullet> _bullets;
    float _cooldown;
    float _cooldownTimer;

    std::shared_ptr<AssetManager> _assets;
    Sound* _bulletShoot;

private:
    void CheckBullets();

public:
    BulletManager(std::shared_ptr<AssetManager> assets);
    void SpawnBullet(const Vector2 &playerPos, const Vector2 &mousePos);
    void Update(float &dt);
    void Reset();
    std::vector<Bullet> &GetBullets();
};