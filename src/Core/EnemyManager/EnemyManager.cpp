#include <algorithm>

#include "Enemy/Enemy.hpp"
#include "Core/EnemyManager/EnemyManager.hpp"
#include "Bullet/Bullet.hpp"
#include "Core/BulletManager/BulletManager.hpp"
#include "Player/Player.hpp"

EnemyManager::EnemyManager(
  std::shared_ptr<AssetManager> assets,
  std::shared_ptr<BulletManager> bulletManager,
  std::shared_ptr<Camera2D> camera
) 
: _assets(assets), _bulMan(bulletManager), _camera(camera)
{	
  _enemies = {};
}

void EnemyManager::CheckBulletColissions(std::vector<Bullet>& bullets, Player& player)
{
  for (Bullet& b : bullets)
  {
    if(b.GetTag() == Bullet::PLAYER_BULLET)
    {
      for (std::shared_ptr<Enemy>& e : _enemies)
      {
        if ((CheckCollisionCircles(e->GetPos(), e->GetRadius(), b.GetPos(), b.GetRad())) && e->GetHp() > 0)
        {
          b.SetIsActive(false);
          e->ReduceHp(player.GetDamage());
        }
        else if (CheckCollisionCircles(e->GetPos(), e->GetRadius(), b.GetPos(), b.GetRad()))
        {
          e->SetIsAlive(false);
          player.SetScore(e->GetScore() + player.GetScore());
        }
      }
    }

  }
}

void EnemyManager::CheckPlayerColission(Player& player)
{
  for (std::shared_ptr<Enemy>& e : _enemies)
  {
    if (CheckCollisionCircles(e->GetPos(), e->GetRadius(), player.GetPos(), player.GetRaduis()))
    {
      player.SetDead(true);
    }
  }
}

void EnemyManager::RemoveDeadEnemies()
{
  auto it = std::remove_if(
    _enemies.begin(), 
    _enemies.end(), 
    [](std::shared_ptr<Enemy>& e) {return !e->isAlive(); }
  );
  _enemies.erase(it, _enemies.end());
}


void EnemyManager::Update(Player& player)
{
  for (std::shared_ptr<Enemy> e : _enemies)
  {
    e->Update(player, _camera);
  }
  Spawn(RUNNER);
  CheckBulletColissions(_bulMan->GetBullets(), player);
  CheckPlayerColission(player);
  RemoveDeadEnemies();	
}

void EnemyManager::Render()
{
  for (std::shared_ptr<Enemy> e : _enemies)
  {
    e->Render();
  }
}

void EnemyManager::Reset()
{
  _enemies.clear();
}

void EnemyManager::Spawn(EnemyType spawner)
{
}

