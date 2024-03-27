#include <algorithm>
#include "shooter.hpp"
#include "player/player.hpp"
#include "bullet_manager/bullet_manager.hpp"

Shooter::Shooter(
    Vector2 position, 
    std::shared_ptr<Texture> bulletTexture, 
    std::shared_ptr<BulletManager> bulMan
) 
    : Enemy(position, 200),_bulletTexture(bulletTexture), _bulMan(bulMan)
{
    _radius = 50;
    _speed = 100;

    _shootInterval = 4.f;
    _shootTimer = 0.f;
    _attackDistance = 700.f;

    _rotationSpeed = 50.f;
    _rotation = 0;

    _isTracking = true;
    _bulletSpeed = 300.f;
}

void Shooter::Update(Player & player)
{
    float dt = GetFrameTime();
    _target = player.GetPos();
    float distance = Vector2Distance(_position, _target);
    
    if(
        (distance < _attackDistance) && 
        (
            (_position.x >= (_radius + 50)) && 
            (_position.y >= (_radius + 50)) && 
            (_position.x <= GetScreenWidth() - (_radius + 50)) && 
            (_position.y <= GetScreenHeight() - (_radius + 50))
        )
    )
    {
        _isTracking = false;
    } else
    {
        _isTracking = true;
    }

    if(_isTracking)
    {
        ApproachPlayer(player.GetPos(), dt);
    }else{
        Attack(player.GetPos(), dt);
    }
    _rotation += _rotationSpeed * dt;

}

void Shooter::Render()
{
    DrawPoly(_position, 5, _radius, _rotation, GREEN);
}

void Shooter::Shoot()
{   
    _bulMan->SpawnBullet(_position, _target, Bullet::ENEMY_BULLET, _bulletSpeed);
}

void Shooter::ApproachPlayer(const Vector2& playerPos,float dt)
{   

    _rotationSpeed -= 90.f * dt;
    _rotationSpeed = std::max<float>(_rotationSpeed, 50.f);

    _velocity = Vector2Subtract(playerPos, _position);
	_velocity = Vector2Normalize(_velocity);
	_velocity = Vector2Scale(_velocity, _speed * dt);
	_position = Vector2Add(_position, _velocity);
}


void Shooter::Attack(const Vector2 & playerPos, float dt)
{
    _shootTimer += dt;
    _rotationSpeed += 150.f * dt;
    _rotationSpeed = std::min<float>(_rotationSpeed, 300.f);
    if (_shootTimer >= _shootInterval)
    {
        _shootTimer = 0;
        Shoot();
    }
}
