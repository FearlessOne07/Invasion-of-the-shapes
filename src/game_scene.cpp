#include "game_scene.hpp"

GameScene::GameScene() : _playerStart({(float)(GetScreenWidth() / 2), (float)(GetScreenHeight() / 2)}), _playerColor(BEIGE), _player(_playerStart, _playerColor)
{
    _clearColor = BLACK;
}

void GameScene::Update(float &dt)
{
    GetInput();
    _player.Update(dt);
    _enemMan.Update(dt, _player.GetPos());
}

void GameScene::GetInput()
{
    if (IsKeyPressed(KEY_ESCAPE))
    {
        Notify(Event::TO_PAUSE);
    }
}

void GameScene::Render()
{
    ClearBackground(_clearColor);
    _player.Render();
}
