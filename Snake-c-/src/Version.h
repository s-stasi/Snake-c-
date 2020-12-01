#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "jsonParser/SavedData.h"

class Version
{
public:
	Version(std::string text, float width_f, float height_f);
	~Version();

	void draw(sf::RenderWindow &window);
private:
	sf::Text version;
};

