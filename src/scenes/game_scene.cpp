#include "game_scene.hpp"
#include "asset_manager/asset_manager.hpp"
#include "bullet_manager/bullet_manager.hpp"
#include "config/config.hpp"

GameScene::GameScene(std::shared_ptr<AssetManager> assets)
    : Scene(assets),
    _playerStart({ (float)(GetScreenWidth() / 2), (float)(GetScreenHeight() / 2) }),
    _playerColor(BEIGE),
    _bulMan(std::make_shared<BulletManager>(_assets)),
    _enemMan(_assets) ,
    _player(_playerStart, _playerColor, _assets, _bulMan)
{
    _clearColor = {14, 15, 25, 255};
    _config = Config::GetInstance();

    _camera.target = _player.GetPos();
    _camera.zoom = 0;
}

void GameScene::Update(float &dt)
{
    // Update
    GetInput();
    UpdateGameClock(dt);
    _player.Update(dt);
    _enemMan.Update(_player, _bulMan);
    _bulMan->Update(dt);
    CheckPlayer();

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
    
    DrawTextEx(*(_assets->GameFont()), TextFormat("Score:%i", _player.GetScore()), { 10,10 }, 24, 1, WHITE);
    ClearBackground(_clearColor);
    _enemMan.Render();
    _player.Render();
    
}

void GameScene::UpdateGameClock(float &dt)
{
    _gameClock += dt;
}

void GameScene::Reset()
{
    _gameClock = 0;
    _enemMan.Reset();
    _bulMan->Reset();
    _player.Reset();
}

void GameScene::CheckPlayer()
{
    if (_player.isDead())
    {
        Notify(Event::TO_GAME_OVER);
    }
}