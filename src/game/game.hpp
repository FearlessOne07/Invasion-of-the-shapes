#pragma once
#include "raylib.h"
#include <string>
#include <memory>
#include "../utils/obsever.hpp"

class AssetManager;
class Scene;
class Config;

class Game : public Observer
{
private:
    const Vector2 SIZE{1600, 900};
    const int FPS{60};
    std::shared_ptr<Scene> _gameScene{};
    std::shared_ptr<Scene> _titleScene{};
    std::shared_ptr<Scene> _pauseScene{};
    std::shared_ptr<Scene> _gameOverScene{};
    std::shared_ptr<Scene> _currentScene{};

    bool _running{};
    
    // Config
    Config* _config;

    // Assets
    std::shared_ptr<AssetManager> _assets;
    Music* _gameMusic;

private:
    void SetScene(std::shared_ptr<Scene> newScene);

public:
    Game() = default;
    void Init();
    void Run();
    void End();
    void OnNofity(const Event &event) override;
};