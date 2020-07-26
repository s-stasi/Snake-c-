#include "ModMenu.h"

ModMenu::ModMenu(float width, float height)
{
	if (font.loadFromFile("Font/arial.ttf"))
	{
		//Error declaration
	}

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Normal mode");
	menu[0].setPosition(sf::Vector2f(width / 2 - (menu[0].getGlobalBounds().width / 2), height / (MAX_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Progressive speed mode");
	menu[1].setPosition(sf::Vector2f(width / 2 - (menu[1].getGlobalBounds().width / 2), height / (MAX_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(width / 2 - (menu[2].getGlobalBounds().width / 2), height / (MAX_ITEMS + 1) * 3));

	selectedItemIndex = 0;
}

ModMenu::~ModMenu()
{
}


void ModMenu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}


void ModMenu::moveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		std::cout << "Voce menu selezionata: " << selectedItemIndex << std::endl;
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}


void ModMenu::moveDown()
{
	if (selectedItemIndex + 1 < MAX_ITEMS)
	{
		std::cout << "Voce menu selezionata: " << selectedItemIndex << std::endl;
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);

		std::cout << "Selecteditemindex: " << selectedItemIndex << std::endl;
	}
}

int ModMenu::getPressedItem()
{
	return selectedItemIndex;
	std::cout << "Getpresseditem: " << selectedItemIndex << std::endl;
}
