#include <algorithm>
#include <memory>

#include "raylib.h"

#include "GameOverScene.hpp"
#include "Core/Game/Game.hpp"
#include "Core/AssetManager/AssetManager.hpp"

GameOverScene::GameOverScene(
  std::shared_ptr<Game> game, 
  std::shared_ptr<AssetManager> assets
) 
  : Scene(game, assets)
{

	_font = _assets->GameFont();
	_clearColor = BLACK;
	_deathText = "YOU DIED!";
	_playText = "PRESS SPACE TO PLAY AGAIN OR ESC TO QUIT";

	_textSize = 64;
	_opacity = 0;
	_opacityPulse = 200;
	_inputLimit = 2;
	_inputTimer = 0;


	_deathTextX = (float)GetScreenWidth() / 2 - MeasureTextEx(*_font, _deathText, _textSize, 1).x / 2;
	_playTextX = (float)GetScreenWidth() / 2 - MeasureTextEx(*_font, _playText, 30, 1).x / 2;
}
void GameOverScene::Reset()
{
	_inputTimer = 0;
	_opacity = 0;
	_opacityPulse = 200;
}

void GameOverScene::Update(float& dt)
{
	if (_inputTimer >= _inputLimit)
	{
		GetInput();

		_opacity += _opacityPulse * dt;
		_opacity = std::clamp<int>(_opacity, 0, 255);

		if (_opacity <= 0 || _opacity >= 255)
		{
			_opacityPulse *= -1;
		}
	}
	else
	{
		_inputTimer += dt;
	}

}

void GameOverScene::GetInput() {
	// Check for input and notify the Game class if neccessary
	if (IsKeyPressed(KEY_SPACE))
	{
    _game->ChangeScene(Game::GAME_SCENE, true);
	}
	if (IsKeyPressed(KEY_ESCAPE))
	{
    _game->ChangeScene(Game::TITLE_SCENE, false);
	}
}

void GameOverScene::Render()
{
	
	ClearBackground(_clearColor);
	DrawTextEx(*_font, _deathText, { _deathTextX, 400 }, _textSize, 1, RED);
	if (_inputTimer >= _inputLimit)
	{
		DrawTextEx(*_font, _playText, { _playTextX, 600 }, 30, 1, { 255, 0, 0, static_cast<unsigned char>(_opacity) });
	}
}
