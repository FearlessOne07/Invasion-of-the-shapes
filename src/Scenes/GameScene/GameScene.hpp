#pragma once
#include <memory>

#include "Core/EnemyManager/EnemyManager.hpp"
#include "Player/Player.hpp"
#include "Scenes/Scene.hpp"
#include "raylib.h"

class Config;
class GameScene : public Scene {
private:
  std::shared_ptr<Camera2D> _camera;

  std::shared_ptr<BulletManager> _bulMan;
  std::shared_ptr<Config> _config;

  std::shared_ptr<Player> _player;
  Vector2 _playerStart{};
  Color _playerColor{};

  EnemyManager _enemMan;
  int _waveCount;
  float _waveTimer;

  float _gameClock{};

private:
  void GetInput() override;
  void CheckPlayer();
  void UpdateGameClock(float &dt);
  void UpdateCamera(float dt);
  void SpawnEnemies(float dt);

public:
  GameScene(std::shared_ptr<Game> game, std::shared_ptr<AssetManager> assets);
  void Update(float &dt) override;
  void Render() override;
  void Reset() override;
};
