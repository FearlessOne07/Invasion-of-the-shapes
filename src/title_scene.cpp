#include "title_scene.hpp"

TitleScene::TitleScene()
{
    _playButton.size = {300, 100};
    _playButton.pos.x = GetScreenWidth() / 2 - _playButton.size.x / 2;
    _playButton.pos.y = GetScreenHeight() / 2 - _playButton.size.y / 2;
    _playButton.color = WHITE;
    _playButton.rect = {
        _playButton.pos.x,
        _playButton.pos.y,
        _playButton.size.x,
        _playButton.size.y //
    };
    _playButton.SetText("Play");
}

void TitleScene::Update(float& dt)
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
}

void TitleScene::Render()
{
    DrawButtons();
}

void TitleScene::DrawButtons()
{
    _playButton.DrawBtnText();
    DrawRectangleRoundedLines(_playButton.rect, .2, 1, 4, _playButton.color);
}
