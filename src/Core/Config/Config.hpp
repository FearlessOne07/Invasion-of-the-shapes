#pragma once
#include <memory>

#include "json/json.h"
class Config {
private:
  static std::shared_ptr<Config> _instance;
  Json::Value _config{};

private:
  Config() = default;

public:
  static std::shared_ptr<Config> GetInstance();
  Json::Value GetData(const char *name);

public:
  ~Config();
  void LoadConfig();
  void SetData(Json::Value value, const char *key);
};
