#include "Apple.h"

Apple::Apple(sf::RectangleShape &rectangle, int dimension, int scale)
	: rect(rectangle), dim(dimension), scl(scale)
{
	changePos();
}

Apple::~Apple()
{
}

void Apple::changePos()
{
	srand(time(NULL));
	x = rand() % dim;
	y = rand() % dim;
	rect.setPosition(x * scl_f, y * scl_f);
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
