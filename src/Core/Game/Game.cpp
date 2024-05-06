#include "Game.hpp"
#include "Core/AssetManager/AssetManager.hpp"
#include "Core/Config/Config.hpp"
#include "Scenes/GameOverScene/GameOverScene.hpp"
#include "Scenes/GameScene/GameScene.hpp"
#include "Scenes/PauseScene/PauseScene.hpp"
#include "Scenes/TitleScene/TitleScene.hpp"

void Game::Init() {

  // Initialize Window
  SetConfigFlags(FLAG_MSAA_4X_HINT);
  InitWindow(SIZE.x, SIZE.y, "Invasion of the Shapes");
  InitAudioDevice();
  SetTargetFPS(FPS);
  SetExitKey(0);

  ToggleFullscreen();
  _running = true;

  // Assets
  _assets = std::make_shared<AssetManager>();
  _assets->Init();

  // Config
  _config = Config::GetInstance();
  _config->LoadConfig();

  // Initialize Scenes
  _scenes[TITLE_SCENE] =
      std::make_shared<TitleScene>(shared_from_this(), _assets);
  _scenes[GAME_SCENE] =
      std::make_shared<GameScene>(shared_from_this(), _assets);
  _scenes[PAUSE_SCENE] =
      std::make_shared<PauseScene>(shared_from_this(), _assets);
  _scenes[GAME_OVER_SCENE] =
      std::make_shared<GameOverScene>(shared_from_this(), _assets);

  _currentScene = _scenes[TITLE_SCENE];

  // Game Music
  _gameMusic = _assets->GetMusic("game_music");
}

void Game::Run() {
  // Game Loop
  while (_running && !WindowShouldClose()) {
    float dt = GetFrameTime();
    BeginDrawing();
    _assets->Update();
    // PlayMusicStream(*_gameMusic);
    _currentScene->Update(dt);
    _currentScene->Render();
    DrawText(TextFormat("FPS: %i", GetFPS()), 0, 850, 32, WHITE);
    EndDrawing();
  }
  End();
}

void Game::End() {
  _assets->CleanUp();
  CloseAudioDevice();
  CloseWindow();
}

void Game::ChangeScene(SceneName scene, bool reset) {
  _currentScene = _scenes[scene];
  if (reset) {
    _currentScene->Reset();
  }
}

void Game::SetRunningState(bool state) { _running = false; }
