#include "asset_manager.h"

void AssetManager::Init()
{
	// Load Sounds
	Wave shoot = LoadWave("assets/audio/player_shoot.wav");
	_playerShoot = LoadSoundFromWave(shoot);
	UnloadWave(shoot);

	Wave die = LoadWave("assets/audio/enemy_die.wav");
	_enemyDeath = LoadSoundFromWave(die);
	UnloadWave(die);

	_gameMusic = LoadMusicStream("assets/audio/game_scene.mp3");

	// Load Fonts
	_gameFont = LoadFont("assets/fonts/font1.otf");
}

void AssetManager::Update()
{
	UpdateMusicStream(_gameMusic);
}

void AssetManager::CleanUp()
{
	UnloadSound(_playerShoot);
	UnloadSound(_enemyDeath);
	UnloadMusicStream(_gameMusic);
	UnloadFont(_gameFont);
}

const Font& AssetManager::GameFont() const
{
	return _gameFont;
}

const Music& AssetManager::GameMusic() const
{
	return _gameMusic;
}

const Sound& AssetManager::Shoot() const
{
	return _playerShoot;
}

const Sound& AssetManager::Death() const
{
	return _enemyDeath;
}
