#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>

class Apple
{
public:
	Apple(int dimension, int scale);
	~Apple();
	void changePos();
	int getX() const;
	int getY() const;
	void draw(sf::RenderWindow &window);

private:
	sf::RectangleShape rect;
	int x, y;
	int dim;
	int scl;
};