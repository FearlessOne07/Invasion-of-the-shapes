#include "config.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

Config* Config::_instance = nullptr;

Config* Config::GetInstance()
{

	if (!Config::_instance)
	{
		Config::_instance = new Config;
	}
	return Config::_instance;
}

void Config::LoadConfig()
{

	if (!_instance)
	{
		std::cerr << "Config instance not valid, CONFIG FILE HASN'T BEEN LOADED!! First call Config::GetInstance()\n";
		return;
	}
	std::ifstream file("src/game_files/config.json");
	file >> _config;
	file.close();
}

Json::Value Config::GetData(const char* name)
{
	return _config[name];
}

Config::~Config()
{
	std::ofstream file;
	file.open("src/game_files/config.json", std::ios::out);
	file << _config;
	file.close();
}

