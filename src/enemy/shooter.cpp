#include "shooter.hpp"
#include "player/player.hpp"

Shooter::Shooter(Vector2 position, std::shared_ptr<Texture> bulletTexture) 
    : Enemy(position, 200),_bulletTexture(bulletTexture) 
{
    _speed = 300; 
}

void Shooter::Update(Player & player)
{
    float dt = GetFrameTime();
    for (auto& bullet : _bullets)
    {
        bullet.Update(dt);
    }
}

void Shooter::Render()
{
}

void Shooter::Shoot()
{
    _bullets.emplace_back(Bullet(_position, _target, _bulletTexture));
}