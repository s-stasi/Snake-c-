#include "Apple.h"

Apple::Apple(int dimension, int scale)
	: dim(dimension), scl(scale)
{
	rect.setSize({ (float)scale, (float)scale });
	rect.setFillColor(sf::Color::Red);
	changePos();
}

Apple::~Apple()
{
}

void Apple::changePos()
{
	srand(rand());
	x = rand() % dim;
	y = rand() % dim;
	rect.setPosition(x * (float)scl, y * (float)scl);
}

int Apple::getX() const
{
	return x;
}

int Apple::getY() const
{
	return y;
}

void Apple::draw(sf::RenderWindow &window)
{
	window.draw(rect);
}
