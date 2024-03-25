#include <algorithm>
#include <cmath>
#include "bullet.hpp"

Bullet::Bullet(Vector2 position, Vector2 direction, std::shared_ptr<Texture> textures, BulletTag tag) 
    :_texture(textures), _position(position), _direction(direction), _tag(tag)
{
    // Texture
    //_texture = LoadTexture("")
    _textureSize = 16;
    _textureScale = 3;
    _srcRect = { 0 * _textureSize, 0 * _textureSize, _textureSize, _textureSize };
    _rotation = ((std::atan2(direction.y, direction.x)) * RAD2DEG) + 90.f;
    _opacity = 255;
    _opacityChange = 250;
    _radius = 10;
    _speed = 800;
    _isActive = true;

}

void Bullet::CheckActivty()
{ 
    // Check and set status of bullet
    if (_opacity <= 0)
    {
        SetIsActive(false);
    }
}

void Bullet::Render()
{
    DrawTexturePro(
        *_texture,
        _srcRect,
        { _position.x, _position.y, _textureSize * _textureScale, _textureSize * _textureScale },
        { (_textureSize * _textureScale) / 2, (_textureSize * _textureScale) / 2 },
        _rotation,
        { 255,255,255, static_cast<unsigned char>(_opacity) }
    );
}
void Bullet::Update(float &dt) 
{
    _opacity -= _opacityChange * dt;
    _opacity = std::max(_opacity, 0.f);

    CheckActivty();
    _position = Vector2Add(_position, Vector2Scale(_direction, _speed * dt));
}

Vector2 Bullet::GetPos() const
{
    return _position;
}

int Bullet::GetRad() const
{
    return _radius;
}

bool Bullet::isActive() const
{
    return _isActive;
}

void Bullet::SetIsActive(bool active)
{
    _isActive = active;
}

BulletTag Bullet::GetTag() const
{
    return _tag;
}