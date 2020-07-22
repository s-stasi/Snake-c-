#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#define MAX_ITEMS 3

class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow &window);
	void moveUp();
	void moveDown();
	int getPressedItem();
private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_ITEMS];

};