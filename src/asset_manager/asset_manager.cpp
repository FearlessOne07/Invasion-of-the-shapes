#include "asset_manager.h"

void AssetManager::Init()
{
// Load Sounds
	Wave playerShoot = LoadWave("assets/audio/player_shoot.wav");
	_sounds["player_shoot"] = new Sound(LoadSoundFromWave(playerShoot));
	UnloadWave(playerShoot);

	Wave enemyDie = LoadWave("assets/audio/enemy_die.wav");
	_sounds["enemy_die"] = new Sound(LoadSoundFromWave(enemyDie));
	UnloadWave(enemyDie);

	// Load Music
	_music["game_music"] = new Music(LoadMusicStream("assets/audio/game_scene.mp3"));

	// Load Fonts
	_gameFont = new Font(LoadFont("assets/fonts/font1.ttf"));

// Load Textures
	_textures["entities"] = new Texture(LoadTexture("assets/textures/entities.png"));
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

	// Cleanup Sounds
	for (const std::pair<const std::string&, Sound*>& p : _sounds)
	{
		UnloadSound(*(p.second));
		delete p.second;
	}

	// Cleanup Music
	for (const std::pair<const std::string&, Music*>& p : _music)
	{
		UnloadMusicStream(*(p.second));
		delete p.second;
	}
	UnloadFont(*_gameFont);

	// Cleanup Textures
	for (const std::pair<const std::string&, Texture*>& p : _textures)
	{
		UnloadTexture(*p.second);
		delete p.second;
	}

	// Delete Font
	delete _gameFont;
}

Font* AssetManager::GameFont() const
{
	return _gameFont;
}

Sound* AssetManager::GetSound(const std::string& key)
{
	return _sounds[key];
}

Music* AssetManager::GetMusic(const std::string& key)
{
	return _music[key];
}

Texture* AssetManager::GetTexture(const std::string& key)
{
	return _textures[key];
}

