#include "AssetManager.hpp"

void AssetManager::Init()
{
	// Load Sounds
	Wave playerShoot = LoadWave("assets/audio/player_shoot.wav");
	_sounds["player_shoot"] = std::make_shared<Sound>(LoadSoundFromWave(playerShoot));
	UnloadWave(playerShoot);
  
	Wave enemyDie = LoadWave("assets/audio/enemy_die.wav");
	_sounds["enemy_die"] = std::make_shared<Sound>(LoadSoundFromWave(enemyDie));
	UnloadWave(enemyDie);

	// Load Music
	_music["game_music"] = std::make_shared<Music>(LoadMusicStream("assets/audio/game_scene.mp3"));

	// Load Fonts
	_gameFont = std::make_shared<Font>(LoadFont("assets/fonts/font1.ttf"));

	/* Load Textures*/

	// Entites
	_textures["player"] = std::make_shared<Texture>(LoadTexture("assets/textures/player/player.png"));
	_textures["shooter"] = std::make_shared<Texture>(LoadTexture("assets/textures/enemies/shooter/shooter.png"));

	// Projectiles
	_textures["bullet"] = std::make_shared<Texture>(LoadTexture("assets/textures/projectiles/bullet/bullet.png"));
	_textures["projectiles"] = std::make_shared<Texture>(LoadTexture("assets/textures/projectiles.png"));
}

void AssetManager::Update()
{
	for (auto &p : _music)
	{
		UpdateMusicStream(*(p.second));
	}
}

void AssetManager::CleanUp()
{
	// Cleanup Sounds
	for(auto it = _sounds.begin(); it != _sounds.end(); it++)
	{
		UnloadSound(*(it->second));
	}

	// Cleanup Music
	for(auto it = _music.begin(); it != _music.end(); it++)
	{
		UnloadMusicStream(*(it->second));
	}

	// Cleanup Textures
	for(auto it = _textures.begin(); it != _textures.end(); it++)
	{
		UnloadTexture(*(it->second));
	}

	UnloadFont(*_gameFont);
}

std::shared_ptr<Font> AssetManager::GameFont() const
{
	return _gameFont;
}

std::shared_ptr<Sound> AssetManager::GetSound(const std::string &key)
{
	return _sounds[key];
}

std::shared_ptr<Music> AssetManager::GetMusic(const std::string &key)
{
	return _music[key];
}

std::shared_ptr<Texture> AssetManager::GetTexture(const std::string &key)
{
	return _textures[key];
}
