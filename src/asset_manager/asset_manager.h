#pragma once
#include "raylib.h"
#include <unordered_map>

class AssetManager
{
private:

// Audio
	std::unordered_map<const char*, Sound*> _sounds;
	std::unordered_map<const char*, Music*> _music;

//Fonts
	Font* _gameFont;
public:
	void Init();
	void Update();
	void CleanUp();

//Getters
	Font* GameFont() const;
	Sound* GetSound(const char* key);
	Music* GetMusic(const char* key);

};

