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
	std::cout << "Disegnata a: " << x << ", " << y << std::endl;
}

int Apple::getX()
{
	std::cout << "Rect x location: " << rect.getPosition().x << std::endl;
	return x;
}

int Apple::getY()
{
	std::cout << "Rect y location: " << rect.getPosition().x << std::endl;
	return y;
}

void Apple::draw(sf::RenderWindow &window)
{
	window.draw(rect);
}
