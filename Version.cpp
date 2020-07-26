#include "Version.h"



Version::Version(std::string text, float width_f, float height_f)
{
	if (font.loadFromFile("Font/arial.ttf"))
	{
		//Error declaration
	}

	version.setFont(font);
	version.setFillColor(sf::Color::White);
	version.setString((std::string)"Version: " + text);
	version.setCharacterSize(12);
	version.setPosition(sf::Vector2f(width_f - 585, height_f - 20));
}


Version::~Version()
{
}

void Version::draw(sf::RenderWindow &window)
{
	window.draw(version);
}
