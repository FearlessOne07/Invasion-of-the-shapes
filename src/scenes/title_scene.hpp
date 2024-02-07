#pragma once
#include "scene.hpp"

class TitleScene : public Scene
{
private:
    // Buttons
    Color _hoverColor{};
    Color _offColor{};
    Button _playButton{};

private:
    void GetInput() override;
    void DrawButtons();

public:
    TitleScene(AssetManager& assets);
    void Update(float& dt) override;
    void Render() override;
};