#pragma once

#include <memory>
#include <vector>

#include "Enemy/Enemy.hpp"

class Runner : public Enemy {
private:
  void Spawn(float dt) override;

public:
  // Core
  Runner(unsigned long id, EnemyType type, Vector2 position,
         std::shared_ptr<Texture> texture, std::shared_ptr<Camera2D> camera,
         float speed, int score);
  void Update(std::shared_ptr<Player> player,
              const std::vector<std::shared_ptr<Enemy>> &enemies) override;
  void Render() override;
  void FollowPlayer(const Vector2 &playerPos);
};
