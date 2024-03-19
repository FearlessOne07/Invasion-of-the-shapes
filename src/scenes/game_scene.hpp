#pragma once
#include "raylib.h"
#include "scene.hpp"
#include "player/player.hpp"
#include "enemy_manager/enemy_manager.hpp"
#include "bullet_manager/bullet_manager.hpp"


class Config;
class GameScene : public Scene
{
private:
    Camera2D _camera;

    Vector2 _playerStart{};
    Color _playerColor{};
    Player _player;
    EnemyManager _enemMan;

    BulletManager _bulMan;
    float _gameClock{};

    std::shared_ptr<Config> _config;

private:
    void GetInput() override;
    void CheckPlayer();
    void UpdateGameClock(float &dt);

public:
    GameScene(std::shared_ptr<AssetManager> assets);
    void Update(float &dt) override;
    void Render() override;
    void Reset() override;
};