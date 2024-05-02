#include "raylib.h"
#include "Scenes/Scene.hpp"

class GameOverScene : public Scene
{
private:
	int _textSize;

	float _deathTextX;
	const char* _deathText;


	float _playTextX;
	const char* _playText;

	float _inputTimer;
	int _inputLimit;

	int _opacity;
	int _opacityPulse;

	std::shared_ptr<Font> _font;

public:
	GameOverScene(std::shared_ptr<AssetManager> assets);
	void Update(float& dt) override;
	void Render() override;
	void GetInput() override;
	void Reset() override;
};
