#pragma once
#include "raylib.h"

#include "Scenes/Scene.hpp"
#include "Player/Player.hpp"
#include "Core/EnemyManager/EnemyManager.hpp"
#include <memory>


class Config;
class GameScene : public Scene
{
private:
  std::shared_ptr<Camera2D> _camera;

  std::shared_ptr<BulletManager> _bulMan;
  std::shared_ptr<Config> _config;

  std::shared_ptr<Player> _player;
  Vector2 _playerStart{};
  Color _playerColor{};


  EnemyManager _enemMan;

  float _gameClock{};

private:
  void GetInput() override;
  void CheckPlayer();
  void UpdateGameClock(float &dt);
  void UpdateCamera(float dt);
public:
  GameScene(std::shared_ptr<Game> game, std::shared_ptr<AssetManager> assets);
  void Update(float &dt) override;
  void Render() override;
  void Reset() override;
};
