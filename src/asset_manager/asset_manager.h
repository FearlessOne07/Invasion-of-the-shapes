#pragma once
#include "raylib.h"

class AssetManager
{
private:
//Sounds
	Sound _playerShoot;
	Sound _enemyDeath;
	Music _gameMusic;
//Fonts
	Font _gameFont;
public:
	void Init();
	void Update();
	void CleanUp();

//Getters
	const Font& GameFont() const;
	const Music& GameMusic() const;
	const Sound& Shoot() const;
	const Sound& Death() const;

};

