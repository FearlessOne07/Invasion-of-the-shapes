#pragma once
#include "raylib.h"
#include <unordered_map>
#include <string>
#include <memory>

class AssetManager
{
private:

	// Audio
	std::unordered_map<std::string, std::shared_ptr<Sound>> _sounds;
	std::unordered_map<std::string, std::shared_ptr<Music>> _music;
	std::unordered_map<std::string, std::shared_ptr<Texture>> _textures;

	//Fonts
	std::shared_ptr<Font> _gameFont;
public:
	void Init();
	void Update();
	void CleanUp();

	//Getters
	std::shared_ptr<Font> GameFont() const;
	std::shared_ptr<Sound> GetSound(const std::string& key);
	std::shared_ptr<Music> GetMusic(const std::string& key);
	std::shared_ptr<Texture> GetTexture(const std::string& key);
};

