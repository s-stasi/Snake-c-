#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <ctime>

class Apple
{
public:
	Apple(sf::RectangleShape rectangle, int dimension, int scale);
	~Apple();
	void changePos();
	int getX();
	int getY();
	void draw(sf::RenderWindow &window);

private:
	sf::RectangleShape rect;
	int x, y;
	int dim;
	int scl;
	float scl_f = 20.0f;
};