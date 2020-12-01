#pragma once
#include <SFML/Graphics.hpp>
#include <string>

namespace SfmlAPI {
	class Button
	{
	public:

		Button();
		Button(std::string string, sf::Vector2f size, sf::Color bgColor, sf::Color textColor, sf::Font &font);
		
		~Button();
		
		void setBgColor(sf::Color bgColor);

		void setCharacterSize(int size) {};
		
		void setTextColor(sf::Color textColor);

		void setPosition(sf::Vector2f pos);
		void setPosition(float x, float y);

		void draw(sf::RenderWindow &window);

	private:

		sf::RectangleShape	rect;
		sf::Text			text;
	};
}