#pragma once
#include "raylib.h"
#include "scene.hpp"
#include "player.hpp"
#include "enemy_manager.hpp"

class GameScene : public Scene
{
private:
    Vector2 _playerStart{};
    Color _playerColor{};
    Player _player;
    EnemyManager _enemMan = EnemyManager();

private:
    void GetInput() override;

public:
    GameScene();
    void Update(float &dt) override;
    void Render() override;
};