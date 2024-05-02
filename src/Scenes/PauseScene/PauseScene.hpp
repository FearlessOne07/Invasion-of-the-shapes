#pragma once
#include <memory>

#include "Scenes/Scene.hpp"
#include "Utils/utils.hpp"

class PauseScene : public Scene {
private:
  // Button Colors
  Color _hoverColor{};
  Color _offColor{};

  // Buttons
  Button _continueButton{};
  Button _titleButton{};

  Color _clearColor{};
  Texture2D _fillTexture{};
  void DrawButtons();
  void GetInput() override;

public:
  PauseScene(std::shared_ptr<Game> game, std::shared_ptr<AssetManager> assets);
  void Update(float &dt) override;
  void Render() override;
  void SetFillTexture(Texture2D &texture);
};
