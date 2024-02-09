#include "game_scene.hpp"
#include "../asset_manager/asset_manager.h"

GameScene::GameScene(AssetManager& assets) 
    : Scene(assets), 
    _playerStart({(float)(GetScreenWidth() / 2), (float)(GetScreenHeight() / 2)}), 
    _playerColor(BEIGE), 
    _player(_playerStart, _playerColor), 
    _enemMan(_assets), 
    _bulMan(_assets)
{
    _clearColor = BLACK;
    _config = Config::GetInstance();
}

void GameScene::Update(float &dt)
{

    GetInput();
    UpdateGameClock(dt);
    _player.Update(dt);
    _enemMan.Update(dt, _player, _bulMan.GetBullets());
    _bulMan.Update(dt);
    CheckPlayer();
}

void GameScene::GetInput()
{
    if (IsKeyPressed(KEY_ESCAPE))
    {
        Notify(Event::TO_PAUSE);
    }

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        _bulMan.SpawnBullet(_player.GetPos(), GetMousePosition());
    }
}

void GameScene::Render()
{
    ClearBackground(_clearColor);
    DrawTextEx(*(_assets.GameFont()), TextFormat("Score:%i", _player.GetScore()), { 10,10 }, 24, 1, WHITE);
    _player.Render();


}

void GameScene::UpdateGameClock(float &dt)
{
    _gameClock += dt;
    if (_gameClock >= 20 && _gameClock < 35)
    {
        _enemMan.SetInterval(3);
    }
    else if (_gameClock >= 35 && _gameClock < 50)
    {
        _enemMan.SetInterval(2);
    }
    else if (_gameClock >= 50)
    {
        _enemMan.SetInterval(1);
    }
}

void GameScene::Reset()
{
    _gameClock = 0;
    _enemMan.Reset();
    _bulMan.Reset();
    _player.Reset();
}

void GameScene::CheckPlayer()
{
    if (_player.GetDead())
    {
        Notify(Event::TO_GAME_OVER);
    }
}