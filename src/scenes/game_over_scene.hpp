#include "raylib.h"
#include "scene.hpp"

class GameOverScene : public Scene
{
private:
    int _textSize;

    float _deathTextX;
    const char *_deathText;


    float _playTextX;
    const char *_playText;

    float _inputTimer;
    int _inputLimit;

    unsigned char _opacity;
    unsigned char _opacityPulse;

    Font _font;

public:
    GameOverScene(AssetManager& assets);
    void Update(float &dt) override;
    void Render() override;
    void GetInput() override;
    void Reset() override;
};