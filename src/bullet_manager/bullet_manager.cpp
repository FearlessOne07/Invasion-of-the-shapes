#include "bullet_manager.hpp"

BulletManager::BulletManager()
{
    // Initialize Bullet cooldown
    _cooldownTimer = 0;
    _cooldown = .5;

    Wave bulletShoot = LoadWave("assets/audio/player_shoot.wav");
    _bulletShoot = LoadSoundFromWave(bulletShoot);
    UnloadWave(bulletShoot);
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


void BulletManager::SpawnBullet(const Vector2 &playerPos, const Vector2 &mousePos)
{
    // Spawn a bullet if cooldown timer allows it
    if (_cooldownTimer >= _cooldown)
    {
        _cooldownTimer = 0;
        Vector2 direction = Vector2Subtract(mousePos, playerPos);
        direction = Vector2Normalize(direction);
        _bullets.emplace_back(Bullet(playerPos, direction));
        PlaySound(_bulletShoot);
    }
}

void BulletManager::Update(float &dt)
{
    // Cooldown
    if (_cooldownTimer < _cooldown)
    {
        _cooldownTimer += dt;
    }

    // Bullets
    for (Bullet &b : _bullets)
    {
        b.Update(dt);
        b.Render();
    }
    CheckBullets();
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

BulletManager::~BulletManager()
{
    UnloadSound(_bulletShoot);
}