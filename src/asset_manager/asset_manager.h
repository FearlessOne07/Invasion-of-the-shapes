#pragma once
#include "raylib.h"
#include <unordered_map>
#include <string>

class AssetManager
{
private:

	// Audio
	std::unordered_map<std::string, Sound*> _sounds;
	std::unordered_map<std::string, Music*> _music;
	std::unordered_map<std::string, Texture*> _textures;

	//Fonts
	Font* _gameFont;
public:
	void Init();
	void Update();
	void CleanUp();

	//Getters
	Font* GameFont() const;
	Sound* GetSound(const std::string& key);
	Music* GetMusic(const std::string& key);
	Texture* GetTexture(const std::string& key);
};

