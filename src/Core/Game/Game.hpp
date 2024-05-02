#pragma once
#include <memory>
#include <unordered_map>

#include "Scenes/TitleScene/TitleScene.hpp"
#include "raylib.h"

#include "Scenes/Scene.hpp"

class AssetManager;
class Config;

class Game : public std::enable_shared_from_this<Game> {
public:
  enum SceneName { TITLE_SCENE = 0, GAME_SCENE, PAUSE_SCENE, GAME_OVER_SCENE };

private:
  const Vector2 SIZE{1920, 1080};
  const int FPS{60}; 
  bool _running{};

  // Config
  std::shared_ptr<Config> _config;

  // Assets
  std::shared_ptr<AssetManager> _assets;
  std::shared_ptr<Music> _gameMusic;

  // Scenes
  std::unordered_map<SceneName, std::shared_ptr<Scene>> _scenes; 
  std::shared_ptr<Scene> _currentScene;
  
public:
  Game() = default;
  void ChangeScene(SceneName scene, bool reset);
  void Init();
  void Run();
  void End();

  // Mutation
  void SetRunningState(bool state);
};
