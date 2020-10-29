#pragma once
#include <string>
#include <fstream>
#include <jsoncpp/json.h>
#include <SFML/Graphics/Font.hpp>
#include <SfmlAPI.hpp>

class SavedData
{
public:
	struct Data
	{
		static unsigned int bestScore;
		static std::string userName;
		static int lastMod;
		static bool firstLaunch;
		static sf::Font Arial;
	};
public:
	static bool initData();
	static void setBestScore(unsigned int bestScore);
	static void setUsername(const char* userName);
	static void setUsername(std::string userName);
	static void setLastMod(int lastMod);
	static void setFirstLaunch(bool firstLaunch);
		
private:
	static void writeData();
	static void fillStruct();
	static void loadFont(std::string path);

private:
	static bool m_parse;
	static Json::Value m_obj;
	static Json::CharReaderBuilder m_builder;
	static int m_instances;
};