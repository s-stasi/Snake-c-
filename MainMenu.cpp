#include "MainMenu.h"

MainMenu::MainMenu(float width, float height)
{
	if (font.loadFromFile("Font/arial.ttf"))
	{
		//Error declaration
	}

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 2 - (menu[0].getGlobalBounds().width / 2), height / (MAX_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Options");
	menu[1].setPosition(sf::Vector2f(width / 2 - (menu[1].getGlobalBounds().width / 2), height / (MAX_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(width / 2 - (menu[2].getGlobalBounds().width / 2), height / (MAX_ITEMS + 1) * 3));

	selectedItemIndex = 0;
}

MainMenu::~MainMenu()
{
}


void MainMenu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}


void MainMenu::moveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
	else
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex += MAX_ITEMS - 1;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}


void MainMenu::moveDown()
{
	if (selectedItemIndex + 1 < MAX_ITEMS)
	{
		std::cout << selectedItemIndex << std::endl;
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
	else
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex -= MAX_ITEMS - 1;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

int MainMenu::getPressedItem()
{
	return selectedItemIndex;
}