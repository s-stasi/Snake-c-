#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <string>

class Version
{
public:
	Version(std::string text, int width, int height);
	~Version();

	void draw(sf::RenderWindow &window);
private:
	sf::Font font;
	sf::Text version;
};

