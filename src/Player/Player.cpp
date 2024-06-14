#include "Player.hpp"

#include "raylib.h"
#include "raymath.h"

#include "Core/AssetManager/AssetManager.hpp"
#include "Core/BulletManager/BulletManager.hpp"
#include "Core/Config/Config.hpp"
#include "Utils/utils.hpp"

Player::Player(Vector2 position, Color color,
               std::shared_ptr<AssetManager> assets,
               std::shared_ptr<BulletManager> bullMan,
               std::shared_ptr<Camera2D> camera)
    : _assets(assets), _position(position), _bullMan(bullMan), _camera(camera) {
  //--------Initialize Player--------
  // Texture
  _texture = _assets->GetTexture("player");
  _textureSize = _texture->width;
  _scale = 4;
  _rotation = 0.f;

  // Movement
  _speed = 600.f;
  _rotationSpeed = -200;
  _isDead = false;
  _velocity = {0};
  _velocityTarget = {0};

  // Fizix
  _radius = ((_textureSize / 2) * _scale);

  // Config
  _config = Config::GetInstance();
  if (_config) {
    _data = _config->GetData("player_data");
  }

  _score = 0;
  _highscore = _data["highscore"].asInt();

  // Bullets
  _bulletCooldown = .5f;
  _bulletTimer = 0.f;
  _bulletSpeed = 1000.f;
  _bulletDamage = 5;
}

void Player::GetInput(float &dt) {
  // Get Player Input X
  if (IsKeyDown(KEY_A) && IsKeyDown(KEY_D)) {
    _velocityTarget.x = 0;
  } else if (IsKeyDown(KEY_D)) {
    _velocityTarget.x = 1;
  } else if (IsKeyDown(KEY_A)) {
    _velocityTarget.x = -1;
  } else {
    _velocityTarget.x = {0};
  }

  // Get Player Input Y
  if (IsKeyDown(KEY_S) && IsKeyDown(KEY_W)) {
    _velocityTarget.y = 0;
  } else if (IsKeyDown(KEY_S)) {
    _velocityTarget.y = 1;
  } else if (IsKeyDown(KEY_W)) {
    _velocityTarget.y = -1;
  } else {
    _velocityTarget.y = {0};
  }

  // Bullets
  _bulletTimer += dt;
  if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
    Fire();
  }
}

void Player::UpdatePositions(float &dt) {

  if (Vector2Length(_velocityTarget) > 0) {
    _velocityTarget = Vector2Normalize(_velocityTarget);
  }

  // Update Player Positions
  _velocity.x = Utils::Approach(_velocity.x, _velocityTarget.x,
                                (1.f / (_speed * .1f)) * 2.f);
  _velocity.y = Utils::Approach(_velocity.y, _velocityTarget.y,
                                (1.f / (_speed * .1f)) * 2.f);

  _position = Vector2Add(_position, Vector2Scale(_velocity, _speed * dt));
}

void Player::UpdateRotaion(float &dt) { _rotation += 300.f * dt; }

void Player::CheckBounds() {
  // Check Player Collisions With Window
  if (_position.x <= -GetScreenWidth() + _radius) {
    _position.x = -GetScreenWidth() + _radius;
    _velocity.x = 0;
    _velocityTarget.x = 0;
  } else if (_position.x >= GetScreenWidth() - _radius) {
    _position.x = GetScreenWidth() - _radius;
    _velocity.x = 0;
    _velocityTarget.x = 0;
  }

  if (_position.y <= -GetScreenHeight() + _radius) {
    _position.y = -GetScreenHeight() + _radius;
    _velocity.y = 0;
    _velocityTarget.y = 0;
  } else if (_position.y >= GetScreenHeight() - _radius) {
    _position.y = GetScreenHeight() - _radius;
    _velocity.y = 0;
    _velocityTarget.y = 0;
  }
}

void Player::Update(float &dt) {
  GetInput(dt);
  UpdatePositions(dt);
  CheckBounds();
  UpdateRotaion(dt);
}

void Player::Render() {
  DrawTexturePro(
      *_texture, {0, 0, _textureSize, _textureSize},
      {_position.x, _position.y, _textureSize * _scale, _textureSize * _scale},
      {(_textureSize * _scale) / 2, (_textureSize * _scale) / 2}, _rotation,
      WHITE);
  DrawCircleLinesV(_position, _radius, RED);
}

void Player::Fire() {
  if (_bulletTimer >= _bulletCooldown) {
    _bullMan->SpawnBullet(_position,
                          GetScreenToWorld2D(GetMousePosition(), *_camera),
                          Bullet::BulletTag::PLAYER_BULLET, _bulletSpeed);
    _bulletTimer = 0.f;
  }
}

void Player::Reset() {
  SetPos({0, 0});

  SetDead(false);
  if (_score > _highscore) {
    _highscore = _score;
  }
  _data["highscore"] = _highscore;
  _config->SetData(_data, "player_data");
  _score = 0;
}

Vector2 const Player::GetPos() const { return _position; }

const bool Player::isDead() const { return _isDead; }

void Player::SetDead(const bool &input) { _isDead = input; }

int Player::GetScore() const { return _score; }

void Player::SetScore(int score) { _score = score; }

int Player::GetHighScore() const { return _highscore; }

void Player::SetHighScore(int score) { _highscore = score; }

float Player::GetRaduis() const { return _radius; }

void Player::SetPos(const Vector2 &pos) { _position = pos; }

int Player::GetDamage() const { return _bulletDamage; }

void Player::SetDamage(int value) { _bulletDamage = value; }
