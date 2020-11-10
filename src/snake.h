#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <stdexcept>

#include "Points.h"
#include "net/connection.h"
#include "RenderHead.h"
#include "Apple.h"
#include "jsonParser/SavedData.h"

typedef __int8 ultrashort_t;

class Snake
{
public:
	Snake(sf::RenderWindow *w, net::Connection *cnn, float *del, int *gSt);
	~Snake();

	void eventDispatcher(sf::Event &e);
	void move();
	void draw();
	void death();
	void setMode(int mode);
	bool toDelete();

public:
	enum mode : ultrashort_t
	{
		normal,
		progressive
	};

public:
	static int fps;

private:
	struct Int2
	{
		int x, y;
	};

private:
	Points* points;
	Apple* apple;
	renderHead* head;
	sf::RenderWindow* window;
	std::vector<Int2> s;
	net::Connection* connection;
	float scl = 20.f;
	sf::RectangleShape rectangle;
	int dim = 30;
	int dir, num = 1;
	int* gameStatus;
	float timer = 0, *delay;
	bool clearEvent = false;
	bool close, isOn = false;
	static ultrashort_t gameMode;
	bool isDeletable = false;
};

