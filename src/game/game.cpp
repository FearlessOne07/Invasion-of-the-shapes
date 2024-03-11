#include "game.hpp"

#include "../scenes/scene.hpp"
#include "../scenes/title_scene.hpp"
#include "../scenes/game_scene.hpp"
#include "../scenes/puase_scene.hpp"
#include "../scenes/game_over_scene.hpp"
#include "../asset_manager/asset_manager.h"
#include "../config/config.h"
#include <fstream>

void Game::Init()
{

	// Initialize Window
	SetConfigFlags(FLAG_MSAA_4X_HINT);
	InitWindow(SIZE.x, SIZE.y, "Invasion of the Shapes");
	InitAudioDevice();
	SetTraceLogLevel(LOG_NONE);
	SetTargetFPS(FPS);
	SetExitKey(0);

	//ToggleFullscreen();
	_running = true;

	//Assets
	_assets = std::make_shared<AssetManager>();
	_assets->Init();

	// Config
	_config = Config::GetInstance();
	_config->LoadConfig();

	// Initialize Scenes
	_titleScene = std::make_shared<TitleScene>(_assets);
	_gameScene = std::make_shared<GameScene>(_assets);
	_pauseScene = std::make_shared<PauseScene>(_assets);
	_gameOverScene = std::make_shared<GameOverScene>(_assets);
	_titleScene->AddObserver(this);
	_gameScene->AddObserver(this);
	_pauseScene->AddObserver(this);
	_gameOverScene->AddObserver(this);
	SetScene(_titleScene);

	// Game Music
	_gameMusic = _assets->GetMusic("game_music");

}

void Game::Run()
{
	// Game Loop
	while (_running && !WindowShouldClose())
	{
		float dt = GetFrameTime();
		BeginDrawing();
		_assets->Update();
		//PlayMusicStream(*_gameMusic);
		_currentScene->Update(dt);
		_currentScene->Render();

		DrawText(TextFormat("FPS: %i", GetFPS()), 0, 850, 32, WHITE);
		EndDrawing();
	}
	End();
}

void Game::End()
{
	_assets->CleanUp();
	CloseAudioDevice();
	CloseWindow();

}

void Game::OnNofity(const Event& event)
{
	if (event == Event::TO_GAME)
	{
		SetScene(_gameScene);
	}
	else if (event == Event::TO_TITLE)
	{
		_gameScene->Reset();
		SetScene(_titleScene);
	}
	else if (event == Event::TO_PAUSE)
	{
		SetScene(_pauseScene);
	}
	else if (event == Event::TO_GAME_NEW)
	{
		_gameScene->Reset();
		SetScene(_gameScene);
	}
	else if (event == TO_GAME_OVER)
	{
		SetScene(_gameOverScene);
	}
	else if (event == TO_EXIT)
	{
		_running = false;
	}
}

void Game::SetScene(std::shared_ptr<Scene> newScene)
{
	_currentScene = newScene;
}
