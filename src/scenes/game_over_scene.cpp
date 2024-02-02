#include "game_over_scene.hpp"

GameOverScene::GameOverScene()
{
    _clearColor = BLACK;
    _deathText = "YOU DIED!";
    _playText = "PRESS SPACE TO PLAY AGAIN OR ESC TO QUIT";

    _textSize = 64;
    _deathTextX = (float)GetScreenWidth() / 2 - (float)MeasureText(_deathText, _textSize) / 2;
    _playTextX = (float)GetScreenWidth() / 2 - (float)MeasureText(_playText, 48) / 2;

    _opacity = 255;
    _opacityPulse = -3;
    _inputLimit = 2;
    _inputTimer = 0;
}
void GameOverScene::Reset()
{
    _inputTimer = 0;
    _opacity = 255;
    _opacityPulse = -3;
}

void GameOverScene::Update(float &dt)
{
    if (_inputTimer >= _inputLimit)
    {
        GetInput();
    }
    else
    {
        _inputTimer += dt;
    }

    _opacity += _opacityPulse;
    if (_opacity <= 0 || _opacity >= 255)
    {
        _opacityPulse *= -1;
    }
}

void GameOverScene::GetInput()
{
    // Check for input and notify the Game class if neccessary
    if (IsKeyPressed(KEY_SPACE))
    {
        Notify(TO_GAME_NEW);
        Reset();
    }
    if (IsKeyPressed(KEY_ESCAPE))
    {
        Notify(TO_TITLE);
        Reset();
    }
}

void GameOverScene::Render()
{
    ClearBackground(_clearColor);
    DrawText(_deathText, _deathTextX, 400, _textSize, RED);
    if (_inputTimer >= _inputLimit)
    {
        DrawText(_playText, _playTextX, 600, 48, {255, 0, 0, _opacity});
    }
}
