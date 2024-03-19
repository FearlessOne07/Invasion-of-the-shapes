#include "title_scene.hpp"
#include "asset_manager/asset_manager.hpp"

TitleScene::TitleScene(std::shared_ptr<AssetManager> assets) : Scene(assets)
{

    _config = Config::GetInstance();
    _clearColor = BLACK;
    _playButton.size = {300, 100};
    _playButton.pos.x = GetScreenWidth() / 2 - _playButton.size.x / 2;
    _playButton.pos.y = (GetScreenHeight() / 2 - _playButton.size.y / 2);
    _playButton.color = WHITE;
    _playButton.fontSize = 45;
    _playButton.font = _assets->GameFont();
    _playButton.rect = {
        _playButton.pos.x,
        _playButton.pos.y,
        _playButton.size.x,
        _playButton.size.y //
    };
    _playButton.SetText("PLAY");
}

void TitleScene::Update(float &dt)
{
    GetInput();
}

void TitleScene::GetInput()
{

    if (CheckCollisionPointRec(GetMousePosition(), _playButton.rect))
    {
        _playButton.color = RED;
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            Notify(Event::TO_GAME);
        }
    }
    else
    {
        _playButton.color = WHITE;
    }

    // Check if Window Should be closed
    if (IsKeyPressed(KEY_ESCAPE))
    {
        Notify(TO_EXIT);
    }
}

void TitleScene::Render()
{
    ClearBackground(_clearColor);
    DrawButtons();
    DrawText(TextFormat("HIGHSCORE:%i", _config->GetData("player_data")["highscore"].asInt()), 10, 10, 30, WHITE);
}

void TitleScene::DrawButtons()
{
    _playButton.Draw();
    DrawRectangleRoundedLines(_playButton.rect, .2, 1, 4, _playButton.color);
}