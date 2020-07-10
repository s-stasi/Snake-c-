#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Apple
{
public:
	Apple();
	~Apple();

	void newPos();
	void draw(sf::RenderWindow &window);
private:
	int x, y;
	sf::RectangleShape rect(sf::Vector2f(20, 20));
	rect.setFillColor(sf::Color::Red);
};