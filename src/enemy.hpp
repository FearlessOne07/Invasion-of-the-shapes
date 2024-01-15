#include "raylib.h"

class Enemy
{
private:
    Color _color{};
    int _sides{};
    int _radius{};

    Vector2 _position{};
    Vector2 _velocity{};
    float _speed{};

public:
    void Update();
    void Render();
};