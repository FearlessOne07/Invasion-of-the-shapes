#pragma once
#include <memory>
#include <vector>

#include "Bullet/Bullet.hpp"
#include "Core/AssetManager/AssetManager.hpp"
#include "raylib.h"

class BulletManager {
 private:
  std::shared_ptr<Camera2D> _camera;
  std::vector<Bullet> _bullets;
  std::shared_ptr<AssetManager> _assets;
  std::shared_ptr<Sound> _bulletShoot;

 private:
  void CheckBullets();

 public:
  BulletManager(std::shared_ptr<AssetManager> assets, std::shared_ptr<Camera2D> camra);
  void SpawnBullet(const Vector2 &playerPos, const Vector2 &target, Bullet::BulletTag tag,
                   float speed);
  void Update(float &dt);
  void Render();
  void Reset();
  std::vector<Bullet> &GetBullets();
};
