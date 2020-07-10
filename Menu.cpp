#include "Menu.h"

Menu::Menu(float width, float height)
{
	if (font.loadFromFile("Font/arial.ttf"))
	{
		//Error declaration
	}

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Play");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Play");
	menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 3));

	selectedItemIndex = 0;
}

Menu::~Menu()
{
}


void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		window.draw(menu[i]);
		std::cout << "elemento " << i << " creato" << std::endl;
	}
}


void Menu::moveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}


void Menu::moveDown()
{
	std::cout << "md--" << std::endl;
	if (selectedItemIndex + 1 < MAX_ITEMS)
	{
		std::cout << selectedItemIndex << std::endl;
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}