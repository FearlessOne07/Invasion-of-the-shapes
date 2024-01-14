#include "game_scene.hpp"

void GameScene::Update()
{
    GetInput();
}

void GameScene::GetInput()
{
    if (IsKeyPressed(KEY_ESCAPE))
    {
        Notify(Event::TO_TITLE);
    }
}

void GameScene::Render()
{
    DrawText("GameScreen!", 100, 100, 64, GREEN);
}
