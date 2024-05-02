#include <algorithm>

#include "BulletManager.hpp"


BulletManager::BulletManager(
  std::shared_ptr<AssetManager> assets,
  std::shared_ptr<Camera2D> camera
): _assets(assets), _camera(camera)
{
  _bulletShoot = _assets->GetSound("player_shoot");
}


void BulletManager::CheckBullets()
{
  // Check if a bullet is active and remove kill it if it isn't
  auto it = std::remove_if(
    _bullets.begin(),
    _bullets.end(), [](Bullet &b)
    { return !b.isActive(); } //
  );

  _bullets.erase(it, _bullets.end());
}


void BulletManager::SpawnBullet(
  const Vector2 &playerPos, 
  const Vector2 &target, 
  Bullet::BulletTag tag,
  float speed
)
{
  Vector2 direction = Vector2Subtract(target, playerPos);
  direction = Vector2Normalize(direction);
  _bullets.emplace_back(Bullet(playerPos, direction, _assets->GetTexture("bullet"), tag, speed));
  PlaySound(*_bulletShoot);
}

void BulletManager::Update(float &dt)
{
  // Bullets
  for (Bullet &b : _bullets)
  {
    b.Update(dt, _camera);
  }
  CheckBullets();
}

void BulletManager::Render()
{
  for(auto& b : _bullets)
  {
    b.Render();
  }
}

void BulletManager::Reset()
{   
  // "Reset" Bullet Manager
  _bullets.clear();
}

std::vector<Bullet> &BulletManager::GetBullets()
{
  // Return a reference to the bullet vector
  return _bullets;
}
