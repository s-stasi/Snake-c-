#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#include "Points.h"
#include "net/connection.h"
#include "RenderHead.h"
#include "Apple.h"
#include "user.h"

class Snake
{
public:
	Snake();
	~Snake();
	void eventDispatcher(sf::Event &e);
	void move(Apple &apple, Points &points, renderHead &head, net::Connection *connect);
	void draw(sf::Window &window);
	void death(Points &points, net::Connection *connect);
private:
	struct Int2
	{
		int x, y;
	};
	std::vector<Int2> s;
	float scl = 20.0;
	sf::RectangleShape rectangle;
	int fps = 6;
	int dim = 30;
	int dir, num = 1;
	float timer = 0, delay;
	int gameStatus = 0;
	bool clearEvent = false;
	bool close, isOn = false;
	int gameMode;
};

