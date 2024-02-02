#include "game.hpp"

void Game::Init()
{
    // Initialize Window
    InitWindow(SIZE.x, SIZE.y, "Invasion of the Shapes");
    InitAudioDevice();
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    SetTargetFPS(FPS);
    SetExitKey(0);
    _running = true;

    // Initialize Scenes
    _titleScene = std::make_shared<TitleScene>();
    _gameScene = std::make_shared<GameScene>();
    _pauseScene = std::make_shared<PauseScene>();
    _gameOverScene = std::make_shared<GameOverScene>();
    _titleScene->AddObserver(this);
    _gameScene->AddObserver(this);
    _pauseScene->AddObserver(this);
    _gameOverScene->AddObserver(this);
    SetScene(_titleScene);

    // Game Music
    _gameMusic = LoadMusicStream("assets/game_scene.mp3");
    _gameMusic.looping = true;
    PlayMusicStream(_gameMusic);
}

void Game::Run()
{
    // Game Loop
    while (_running && !WindowShouldClose())
    {
        // Update Music Stream
        UpdateMusicStream(_gameMusic);
        float dt = GetFrameTime();
        BeginDrawing();
        _currentScene->Update(dt);
        _currentScene->Render();
        EndDrawing();
    }

    End();
}

void Game::End()
{
    if (!WindowShouldClose())
    {
        UnloadMusicStream(_gameMusic);
        CloseAudioDevice();
        CloseWindow();
    }
}

void Game::OnNofity(const Event &event)
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
