#include "Apple.h"

Apple::Apple(sf::RectangleShape rectangle, int dimension, int scale)
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
	rect.setPosition(x * scl, y * scl);
	std::cout << "mela: " << x << ", " << y << std::endl;
}

int Apple::getX()
{
	return x;
}

int Apple::getY()
{
	return y;
}

void Apple::draw(sf::RenderWindow & window)
{
	window.draw(rect);
}
