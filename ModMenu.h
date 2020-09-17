#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#define MAX_ITEMS 3

class ModMenu
{
public:
	ModMenu(float width, float height);
	~ModMenu();

	void draw(sf::RenderWindow &window);
	void moveUp();
	void moveDown();
	int getPressedItem();
private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_ITEMS];

};