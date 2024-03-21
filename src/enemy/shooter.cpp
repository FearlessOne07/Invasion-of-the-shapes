#include "shooter.hpp"
#include "player/player.hpp"

Shooter::Shooter(Vector2 position, std::shared_ptr<Texture> bulletTexture) 
    : Enemy(position, 200),_bulletTexture(bulletTexture) 
{
    _speed = 300;
    _shootInterval = 4.f;
    _shootTimer = 0.f;
}

void Shooter::Update(Player & player)
{
    float dt = GetFrameTime();
    _target = player.GetPos();
    for (auto& bullet : _bullets)
    {
        bullet.Update(dt);
    }
    ApproachPlayer(player.GetPos(), dt);
}

void Shooter::Render()
{
    for (auto& bullet : _bullets)
    {
        bullet.Render();
    }
    DrawPoly(_position, 3, _radius, 0, GREEN);
}

void Shooter::Shoot()
{   
    Vector2 direction = Vector2Subtract(_target, _position);
    direction = Vector2Normalize(direction);
    _bullets.emplace_back(Bullet(_position, _target, _bulletTexture));
}

void Shooter::ApproachPlayer(const Vector2& playerPos,float dt)
{
    _velocity = Vector2Subtract(playerPos, _position);
	_velocity = Vector2Normalize(_velocity);
	_velocity = Vector2Scale(_velocity, _speed * dt);
	_position = Vector2Add(_position, _velocity);
}