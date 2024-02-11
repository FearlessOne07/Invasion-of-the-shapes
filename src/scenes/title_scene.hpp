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
    int _highscore;

private:
    void GetInput() override;
    void DrawButtons();

public:
    TitleScene(AssetManager& assets);
    void Update(float& dt) override;
    void Render() override;
};
