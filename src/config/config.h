#pragma once
#include "json/json.h"

class Config
{
private:
	static Config* _instance;
	Json::Value _config{};

private:
	Config() = default;
public:
	static Config* GetInstance();
	void LoadConfig();
	Json::Value GetData(const char* name);
	~Config();
};

