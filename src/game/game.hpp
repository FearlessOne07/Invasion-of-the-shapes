#pragma once
#include "raylib.h"
#include "scenes/scene.hpp"
#include "utils/obsever.hpp"
#include <memory>

class AssetManager;
class Config;

class Game : public Observer
{
private:
    const Vector2 SIZE{1920, 1080};
    const int FPS{60};
    std::shared_ptr<Scene> _gameScene{};
    std::shared_ptr<Scene> _titleScene{};
    std::shared_ptr<Scene> _pauseScene{};
    std::shared_ptr<Scene> _gameOverScene{};
    std::shared_ptr<Scene> _currentScene{};

    bool _running{};

    // Config
    std::shared_ptr<Config> _config;

    // Assets
    std::shared_ptr<AssetManager> _assets;
    std::shared_ptr<Music> _gameMusic;

private:
    void SetScene(std::shared_ptr<Scene> newScene);

public:
    Game() = default;
    void Init();
    void Run();
    void End();
    void OnNofity(const Event &event) override;
};
