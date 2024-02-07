#pragma once
#include "raylib.h"
#include "raymath.h"
#include <iostream>
#include "../config/config.h"
#include "json/json.h"

class Player
{
private:
    Vector2 _position{};
    Vector2 _velocity{};
    float _speed{};

    int _sides{};
    Color _color{};

    float _rotationSpeed{};
    float _rotation{};
    bool _isDead;

    Config* _config;

    int _score;
    int _highscore;

    Json::Value _data;

private:
    void GetInput();
    void UpdatePositions(float &dt);
    void UpdateRotaion(float &dt);
    void CheckBounds();

public:
    int radius{};

public:
    Player(Vector2 position, Color color);
    void Update(float &dt);
    void Render();

    Vector2 const GetPos() const;
    void SetPos(const Vector2 &pos);

    const bool GetDead() const;
    void SetDead(const bool &input);
    
    int GetScore() const;
    void SetScore(int score);

    int GetHighScore() const;
    void SetHighScore(int score);
};