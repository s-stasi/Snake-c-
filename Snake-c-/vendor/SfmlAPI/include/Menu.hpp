#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

namespace SfmlAPI {

	class Menu
	{
	public:
		Menu();
		Menu(std::vector<std::string>& elem, sf::Font &font);
		~Menu();
		void setFont(sf::Font &font);
		void draw(sf::RenderWindow &window);
		void moveUp();
		void moveDown();
		int getPressedItem();
		bool isMouseOver();

	private:
		int selectedItemIndex;
		size_t count;
		std::vector<sf::Text> text;
	};
}