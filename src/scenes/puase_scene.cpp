#include "puase_scene.hpp"
#include "asset_manager.h"

PauseScene::PauseScene(std::shared_ptr<AssetManager> assets) : Scene(assets)
{
    //Assets
    std::shared_ptr<Font> font = _assets->GameFont();

    // Initialize Buttons
    _clearColor = {0, 0, 0, 10};
    _continueButton.size = {300, 100};
    _continueButton.pos.x = GetScreenWidth() / 2 - _continueButton.size.x / 2;
    _continueButton.pos.y = (GetScreenHeight() / 2 - _continueButton.size.y);
    _continueButton.fontSize = 25;
    _continueButton.color = WHITE;
    _continueButton.font = font;
    _continueButton.rect = {
        _continueButton.pos.x,
        _continueButton.pos.y, 
        _continueButton.size.x,
        _continueButton.size.y //
    };

    _titleButton.size = {300, 100};
    _titleButton.pos.x = GetScreenWidth() / 2 - _titleButton.size.x / 2;
    _titleButton.pos.y = (GetScreenHeight() / 2 + _titleButton.size.y);
    _titleButton.fontSize = 20;
    _titleButton.color = WHITE;
    _titleButton.font = font;
    _titleButton.rect = {
        _titleButton.pos.x,
        _titleButton.pos.y,
        _titleButton.size.x,
        _titleButton.size.y //
    };


    _titleButton.SetText("TITLE SCREEN");
    _continueButton.SetText("CONTINUE");
}

void PauseScene::Update(float &dt)
{
    GetInput();
}

void PauseScene::Render()
{
    ClearBackground(_clearColor);
    DrawButtons();
}

void PauseScene::SetFillTexture(Texture2D &texture)
{
    _fillTexture = texture;
}

void PauseScene::DrawButtons()
{
    _continueButton.Draw();
    _titleButton.Draw();
}

void PauseScene::GetInput()
{
    if (CheckCollisionPointRec(GetMousePosition(), _continueButton.rect))
    {
        _continueButton.color = RED;
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            Notify(Event::TO_GAME);
        }
    }
    else
    {
        _continueButton.color = WHITE;
    }

    if (CheckCollisionPointRec(GetMousePosition(), _titleButton.rect))
    {
        _titleButton.color = RED;
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            Notify(Event::TO_TITLE);
        }
    }
    else
    {
        _titleButton.color = WHITE;
    }
}
