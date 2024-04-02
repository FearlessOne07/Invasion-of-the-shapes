#include "config.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <ios>


std::shared_ptr<Config> Config::_instance = nullptr;

std::shared_ptr<Config> Config::GetInstance()
{

	if (!Config::_instance)
	{
		Config::_instance = std::shared_ptr<Config>(new Config());
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

	std::fstream file;
	file.exceptions(std::ios::badbit | std::ios::failbit);
	try
	{
		file.open("config.json", std::ios::in);
	}
	catch (const std::ios::failure& e)
	{
		std::string _baseData = R"(
			{ 
				"player_data" : { 
					"highscore" : 0 
				}
			}
		)";

		file.clear();
		file.open("config.json", std::ios::out | std::ios::app);
		file << _baseData;
		file.close();
		file.open("config.json", std::ios::in);
	}

	file >> _config;
	file.close();
}

Json::Value Config::GetData(const char* name)
{
	return _config[name];
}

void Config::SetData(Json::Value value, const char* key)
{
	_config[key] = value;
}

Config::~Config()
{
	std::ofstream file;
	file.open("config.json", std::ios::out);
	file << _config;
	file.close();

}


