#include "game_scene.hpp"
#include "asset_manager/asset_manager.hpp"
#include "bullet_manager/bullet_manager.hpp"
#include "config/config.hpp"

GameScene::GameScene(std::shared_ptr<AssetManager> assets)
  : Scene(assets),
  _camera(std::make_shared<Camera2D>()),
  _playerStart({0, 0}),
  _playerColor(BEIGE),
  _bulMan(std::make_shared<BulletManager>(_assets, _camera)),
  _enemMan(_assets, _bulMan, _camera) ,
  _player(_playerStart, _playerColor, _assets, _bulMan, _camera)
{
  _clearColor = {14, 15, 25, 255};
  _config = Config::GetInstance();

  // Camera
  _camera->target = _player.GetPos();
  _camera->offset = {static_cast<float>(GetScreenWidth()/2.f), static_cast<float>(GetScreenHeight()/2.f)};
  _camera->zoom = 0.8f;

}

void GameScene::Update(float &dt)
{
  // Update
  GetInput();
  UpdateGameClock(dt);

  _player.Update(dt);
  _enemMan.Update(_player);
  _bulMan->Update(dt);
  UpdateCamera(dt);
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
  ClearBackground(_clearColor);
  DrawTextEx(*(_assets->GameFont()), TextFormat("Score:%i", _player.GetScore()), { 10,10 }, 24, 1, WHITE);
  DrawText(TextFormat("Camera Target:(%f, %f)", _camera->target.x, _camera->target.y), 0, 50, 24, WHITE);
  BeginMode2D(*_camera);
  _enemMan.Render();
  _player.Render();
  _bulMan->Render();
  EndMode2D();
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
  _camera->target = _player.GetPos();
}

void GameScene::CheckPlayer()
{
  if (_player.isDead())
  {
    Notify(Event::TO_GAME_OVER);
  }
}

void GameScene::UpdateCamera(float dt)
{
  // Update the camera Position
  float distanceFromPlayer = Vector2Distance(_player.GetPos(), _camera->target);
  float maxDistance = 200.f;
  float speedFactor = std::min<float>( distanceFromPlayer / maxDistance, 1.f);
  float maxMove = 100.f + (speedFactor * 400.f);
  _camera->target = Vector2MoveTowards(
    _camera->target, _player.GetPos(), 
    static_cast<int>(maxMove * dt)
  );

  if(_camera->target.x <= -GetScreenWidth() + _camera->offset.x)
  {
    _camera->target.x = -GetScreenWidth() + _camera->offset.x;
  }
  else if(_camera->target.x >= GetScreenWidth() - _camera->offset.x)
  {
    _camera->target.x = GetScreenWidth() - _camera->offset.x;
  }

  if(_camera->target.y <= -GetScreenHeight() + _camera->offset.y)
  {
    _camera->target.y = -GetScreenHeight() + _camera->offset.y;
  }
  else if(_camera->target.y >= GetScreenHeight() - _camera->offset.y)
  {
    _camera->target.y = GetScreenHeight() - _camera->offset.y;
  }
}
