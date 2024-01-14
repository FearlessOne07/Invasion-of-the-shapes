#pragma once
#include "scene.hpp"

class TitleScene : public Scene
{
private:
    Vector2 _buttonSize{};
    Color _color{};
    Color _hoverColor{};
    Color _offColor{};

public:
    void Update() override;
    void GetInput() override;
    void Render() override;
};
