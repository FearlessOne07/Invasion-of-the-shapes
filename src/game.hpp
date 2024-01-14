#pragma once

#include "raylib.h"
#include <string>
#include <memory>
#include "obsever.hpp"
#include "scene.hpp"
#include "title_scene.hpp"
#include "game_scene.hpp"
class Game : public Observer
{
private:
    const Vector2 SIZE{1600, 900};
    const int FPS{60};
    std::shared_ptr<Scene> _gameScene{};
    std::shared_ptr<Scene> _titleScene{};
    std::shared_ptr<Scene> _currentScene{};
private:
    void SetScene(std::shared_ptr<Scene> newScene);

public:
    Game() = default;
    void Init();
    void Run();
    void End();
    void OnNofity(const Event &event) override;
};