#pragma once

#include "raylib.h"
#include "scene.hpp"

class GameScene : public Scene
{
private:
public:
    void Update() override;
    void GetInput() override;
    void Render() override;
};