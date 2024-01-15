#include "game.hpp"

void Game::Init()
{
    // Initialize Window
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(SIZE.x, SIZE.y, "Invasion of the Shapes");
    SetTargetFPS(FPS);
    SetExitKey(0);

    // Initialize Scenes
    _titleScene = std::make_shared<TitleScene>();
    _gameScene = std::make_shared<GameScene>();
    _titleScene->AddObserver(this);
    _gameScene->AddObserver(this);

    SetScene(_titleScene);
}

void Game::Run()
{

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();
        BeginDrawing();
        ClearBackground(BLACK);
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
        SetScene(_titleScene);
    }
}

void Game::SetScene(std::shared_ptr<Scene> newScene)
{
    _currentScene = newScene;
}
