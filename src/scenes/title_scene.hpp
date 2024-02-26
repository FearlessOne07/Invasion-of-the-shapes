#pragma once
#include "scene.hpp"
#include "../config/config.h"

class TitleScene : public Scene
{
private:
    // Buttons
    Color _hoverColor{};
    Color _offColor{};
    Button _playButton{};

    Config* _config;
private:
    void GetInput() override;
    void DrawButtons();

public:
    TitleScene(std::shared_ptr<AssetManager> assets);
    void Update(float& dt) override;
    void Render() override;
};
