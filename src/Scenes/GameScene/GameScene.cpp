#include "GameScene.hpp"
#include "Core/AssetManager/AssetManager.hpp"
#include "Core/BulletManager/BulletManager.hpp"
#include "Core/Config/Config.hpp"
#include "Core/Game/Game.hpp"
#include <memory>

GameScene::GameScene(std::shared_ptr<Game> game,
                     std::shared_ptr<AssetManager> assets)
    : Scene(game, assets), _camera(std::make_shared<Camera2D>()),
      _playerStart({0, 0}), _playerColor(BEIGE),
      _bulMan(std::make_shared<BulletManager>(_assets, _camera)),
      _enemMan(_assets, _bulMan, _camera, _player),
      _player(std::make_shared<Player>(_playerStart, _playerColor, _assets,
                                       _bulMan, _camera)) {

  _clearColor = {14, 15, 25, 255};
  _config = Config::GetInstance();

  // Camera
  _camera->target = _player->GetPos();
  _camera->offset = {static_cast<float>(GetScreenWidth() / 2.f),
                     static_cast<float>(GetScreenHeight() / 2.f)};
  _camera->zoom = 0.8f;
}

void GameScene::Update(float &dt) {
  // Update
  GetInput();
  UpdateGameClock(dt);
  if (_gameClock > 5) {
    _enemMan.SpawnWave(5);
    _gameClock = -23542543543.f;
  }
  _player->Update(dt);
  _enemMan.Update();
  _bulMan->Update(dt);
  UpdateCamera(dt);
  CheckPlayer();
}

void GameScene::GetInput() {
  if (IsKeyPressed(KEY_ESCAPE)) {
    _game->ChangeScene(Game::PAUSE_SCENE, false);
  }
}

void GameScene::Render() {
  ClearBackground(_clearColor);
  DrawTextEx(*(_assets->GameFont()),
             TextFormat("Score:%i", _player->GetScore()), {10, 10}, 24, 1,
             WHITE);
  DrawText(TextFormat("Camera Target:(%f, %f)", _camera->target.x,
                      _camera->target.y),
           0, 50, 24, WHITE);
  BeginMode2D(*_camera);
  _enemMan.Render();
  _player->Render();
  _bulMan->Render();
  EndMode2D();
}

void GameScene::UpdateGameClock(float &dt) { _gameClock += dt; }

void GameScene::Reset() {
  _gameClock = 0;
  _enemMan.Reset();
  _bulMan->Reset();
  _player->Reset();
  _camera->target = _player->GetPos();
}

void GameScene::CheckPlayer() {
  if (_player->isDead()) {
    _game->ChangeScene(Game::GAME_OVER_SCENE, true);
  }
}

void GameScene::UpdateCamera(float dt) {
  // Update the camera Position
  float distanceFromPlayer =
      Vector2Distance(_player->GetPos(), _camera->target);

  float maxDistance = 200.f;
  float speedFactor = std::min<float>(distanceFromPlayer / maxDistance, 1.f);
  float maxMove = 30.f + (speedFactor * 500.f);

  _camera->target = Vector2MoveTowards(_camera->target, _player->GetPos(),
                                       static_cast<int>(maxMove * dt));

  if (_camera->target.x <= -GetScreenWidth() + _camera->offset.x) {
    _camera->target.x = -GetScreenWidth() + _camera->offset.x;
  } else if (_camera->target.x >= GetScreenWidth() - _camera->offset.x) {
    _camera->target.x = GetScreenWidth() - _camera->offset.x;
  }

  if (_camera->target.y <= -GetScreenHeight() + _camera->offset.y) {
    _camera->target.y = -GetScreenHeight() + _camera->offset.y;
  } else if (_camera->target.y >= GetScreenHeight() - _camera->offset.y) {
    _camera->target.y = GetScreenHeight() - _camera->offset.y;
  }
}
