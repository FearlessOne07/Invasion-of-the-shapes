#include "asset_manager.h"

void AssetManager::Init()
{
	// Load Sounds
	Wave shoot = LoadWave("assets/audio/player_shoot.wav");
	Sound* playershoot = new Sound;

	*playershoot = LoadSoundFromWave(shoot);
	_sounds["player_shoot"] = playershoot;
	UnloadWave(shoot);

	Wave die = LoadWave("assets/audio/enemy_die.wav");
	Sound* enemyDie = new Sound;
	*enemyDie = LoadSoundFromWave(die);
	_sounds["enemy_die"] = enemyDie;
	UnloadWave(die);

	// Load Music
	Music* gameMusic = new Music;
	*gameMusic = LoadMusicStream("assets/audio/game_scene.mp3");
	_music["game_music"] = gameMusic;

	// Load Fonts
	_gameFont = new Font;
	*_gameFont = LoadFont("assets/fonts/font1.ttf");
}

void AssetManager::Update()
{
	for (auto& p : _music)
	{
		UpdateMusicStream(*(p.second));
	}
}

void AssetManager::CleanUp()
{
	for (const std::pair<const char*, Sound*>& p : _sounds)
	{
		UnloadSound(*(p.second));
		delete p.second;
	}

	for (const std::pair<const char*, Music*>& p : _music)
	{
		UnloadMusicStream(*(p.second));
		delete p.second;
	}
	UnloadFont(*_gameFont);
	delete _gameFont;
}

Font* AssetManager::GameFont() const
{
	return _gameFont;
}

Sound* AssetManager::GetSound(const char* key)
{
	return _sounds[key];
}

Music* AssetManager::GetMusic(const char* key)
{
	return _music[key];
}

