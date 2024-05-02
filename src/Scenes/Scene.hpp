#pragma once
#include <memory>

#include "raylib.h"

class Game;
class AssetManager;
class Scene {
protected:
  std::shared_ptr<Game> _game;
  std::shared_ptr<AssetManager> _assets;

  Color _clearColor{};

protected:
  virtual void GetInput() = 0;

public:
  Scene(std::shared_ptr<Game> game, std::shared_ptr<AssetManager> assets)
      : _game(game), _assets(assets) {}

  virtual ~Scene(){};
  virtual void Update(float &dt) = 0;
  virtual void Render() = 0;
  virtual void Reset() {};
};
