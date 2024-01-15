#include "game_scene.hpp"

GameScene::GameScene() : _playerStart({(float)(GetScreenWidth() / 2), (float)(GetScreenHeight() / 2)}), _playerColor(BEIGE), _player(_playerStart, _playerColor)
{
}

void GameScene::Update(float &dt)
{
    GetInput();
    _player.Update(dt);
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
    _player.Render();
}
