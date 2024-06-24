#include "GameScene.hpp"
#include <iostream>
#include <memory>

#include "Core/AssetManager/AssetManager.hpp"
#include "Core/BulletManager/BulletManager.hpp"
#include "Core/Config/Config.hpp"
#include "Core/Game/Game.hpp"
#include "Player/Player.hpp"
#include "raylib.h"

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
  _camera->zoom = 1.f;

  // Waves
  _waveTimer = 0;
  _waveCount = 0;
}

void GameScene::Update(float &dt) {
  // Update
  GetInput();
  _player->Update(dt);
  _enemMan.Update();
  _bulMan->Update(dt);
  CheckPlayer();
  SpawnEnemies(dt);
  UpdateCamera(dt);
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
  DrawRectangleLines(-GetScreenWidth(), -GetScreenHeight(),
                     GetScreenWidth() * 2, GetScreenHeight() * 2, RED);
  EndMode2D();
}

void GameScene::Reset() {
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
  Vector2 playerPos = _player->GetPos();
  Vector2 cameraTarget = _camera->target;

  // Calculate individual axis distances
  float distanceX = playerPos.x - cameraTarget.x;
  float distanceY = playerPos.y - cameraTarget.y;

  // Define maximum distance and threshold
  float maxDistance = 200.f;
  float threshold = 1.f; // Small threshold to prevent shaking

  // Calculate speed factors for each axis
  float speedFactorX = std::min<float>(std::abs(distanceX) / maxDistance, 1.f);
  float speedFactorY = std::min<float>(std::abs(distanceY) / maxDistance, 1.f);

  // Calculate maximum move speeds for each axis
  float maxMoveX = (30.f + speedFactorX * 400.f) * dt;
  float maxMoveY = (30.f + speedFactorY * 400.f) * dt;

  // Move camera target position towards player position on each axis if beyond
  // threshold
  if (std::abs(distanceX) > threshold) {
    cameraTarget.x += maxMoveX * (distanceX > 0 ? 1 : -1);
  }
  if (std::abs(distanceY) > threshold) {
    cameraTarget.y += maxMoveY * (distanceY > 0 ? 1 : -1);
  }

  // Clamp the camera target to screen bounds
  float screenWidth = static_cast<float>(GetScreenWidth());
  float screenHeight = static_cast<float>(GetScreenHeight());

  Vector2 minCameraBound = {-screenWidth + _camera->offset.x,
                            -screenHeight + _camera->offset.y};
  Vector2 maxCameraBound = {screenWidth - _camera->offset.x,
                            screenHeight - _camera->offset.y};

  cameraTarget.x = Clamp(cameraTarget.x, minCameraBound.x, maxCameraBound.x);
  cameraTarget.y = Clamp(cameraTarget.y, minCameraBound.y, maxCameraBound.y);

  // Update camera target position
  _camera->target = cameraTarget;
}

void GameScene::SpawnEnemies(float dt) {
  if (_enemMan.GetAliveCount() == 0) {
    _waveTimer += dt;
  }

  if (_waveTimer > 5) {
    _enemMan.SpawnWave(5);
    _waveCount++;
    _waveTimer = 0.f;
  }
}
