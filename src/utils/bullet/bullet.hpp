#pragma once
#include <memory>
#include "raylib.h"
#include "raymath.h"

enum BulletTag : short unsigned int
{
    PLAYER_BULLET = 0,
    ENEMY_BULLET
};
class Bullet
{
private:
    float _textureSize;
    std::shared_ptr<Texture> _texture;
    Rectangle _srcRect;
    float _textureScale;
    float _rotation;
    float _opacityChange;
    float _opacity;
    int _radius;

    bool _isActive;
    Vector2 _position;
    Vector2 _direction; 
    int _speed;

    BulletTag _tag;
private:
    void CheckActivty();

public:
public:
    Bullet(
        Vector2 position, 
        Vector2 direction, 
        std::shared_ptr<Texture> _texture, 
        BulletTag tag
    );
    void Render();
    void Update(float &dt);
    Vector2 GetPos() const;
    int GetRad() const;
    bool isActive() const;
    void SetIsActive(bool active);
    BulletTag GetTag() const;
};