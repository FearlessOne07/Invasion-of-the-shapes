#pragma once
#include <iostream>
#include <memory>
#include "raylib.h"
#include "raymath.h"
#include "json/json.h"


class AssetManager;
class Config;
class BulletManager;
class Player
{
private:

    // Assets
    std::shared_ptr<AssetManager> _assets;

    // Bullet Manager
    std::shared_ptr<BulletManager> _bullMan;
    float _bulletTimer;
    float _bulletCooldown;;

    // Movement
    Vector2 _position{};
    Vector2 _velocity{};
    float _speed{};

    // Texture
    std::shared_ptr<Texture> _texture;
    Vector2 _textureCords;
    float _textureSize;
    float _scale;

    // Fizix
    float _radius;

    float _rotationSpeed{};
    float _rotation{};
    bool _isDead;

    std::shared_ptr<Config> _config;

    int _score;
    int _highscore;

    Json::Value _data;

private:
    void GetInput(float& dt);
    void UpdatePositions(float &dt);
    void UpdateRotaion(float &dt);
    void CheckBounds();

public:
    Player (
        Vector2 position, 
        Color color,
        std::shared_ptr<AssetManager> assets,
        std::shared_ptr<BulletManager> bullMan
    );

    void Update(float &dt);
    void Render();
    void Reset();
    void Fire();

    Vector2 const GetPos() const;
    void SetPos(const Vector2 &pos);

    const bool isDead() const;
    void SetDead(const bool &input);
    
    int GetScore() const;
    void SetScore(int score);

    int GetHighScore() const;
    void SetHighScore(int score);

    float GetRaduis() const;
};