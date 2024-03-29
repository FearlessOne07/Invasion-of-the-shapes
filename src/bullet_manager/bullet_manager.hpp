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

    std::shared_ptr<Camera2D> _camera;
    std::vector<Bullet> _bullets;
    std::shared_ptr<AssetManager> _assets;
    std::shared_ptr<Sound> _bulletShoot;

private:
    void CheckBullets();

public:
    BulletManager(std::shared_ptr<AssetManager> assets, std::shared_ptr<Camera2D> camra);
    void SpawnBullet(
        const Vector2 &playerPos, 
        const Vector2 &target, 
        Bullet::BulletTag tag, 
        float speed
    );
    void Update(float &dt);
    void Render();
    void Reset();
    std::vector<Bullet> &GetBullets();
};