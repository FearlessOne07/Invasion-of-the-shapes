#pragma once

#include "Scenes/Scene.hpp"
#include "Utils/utils.hpp"

class Config;
class TitleScene : public Scene {
private:
  // Buttons
  Color _hoverColor{};
  Color _offColor{};
  Button _playButton{};

  std::shared_ptr<Config> _config;

private:
  void GetInput() override;
  void DrawButtons();

public:
  TitleScene(std::shared_ptr<Game> game, std::shared_ptr<AssetManager> assets);
  void Update(float &dt) override;
  void Render() override;
};
