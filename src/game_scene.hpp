#pragma once
#include "raylib.h"
#include "scene.hpp"
#include "player.hpp"
#include "enemy_manager.hpp"
#include "bullet_manager.hpp"

class GameScene : public Scene
{
private:
    Vector2 _playerStart{};
    Color _playerColor{};
    Player _player;
    EnemyManager _enemMan = EnemyManager();
    BulletManager _bulMan = BulletManager();
    float _gameClock{};

private:
    void GetInput() override;
    void CheckPlayer();
    void UpdateGameClock(float &dt);

public:
    GameScene();
    void Update(float &dt) override;
    void Render() override;
    void Reset() override;
};