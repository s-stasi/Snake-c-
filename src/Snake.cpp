#include "Snake.h"

Snake::Snake()
{
}

void Snake::eventDispatcher(sf::Event &e)
{
}

void Snake::move(Apple &apple, Points &points, renderHead &head, net::Connection *connect)
{
	for (int i = num; i > 0; i--)
	{
		// Spostamento del bruco
		s[i].x = s[i - 1].x;
		s[i].y = s[i - 1].y;
	}

	// Controllo se il bruco è fuori dal campo di gioco
	if (s[0].x == dim || s[0].y == dim || s[0].x == 0 - 1 || s[0].y == 0 - 1)
	{
		death(points, connect);
		return;
	}

	if (dir == 0)
	{
		s[0].y += 1;
		head.setRotation(180.f);
		head.setPosition((s[1].x * 20) + scl, (s[1].y * 20) + scl * 2);
	}
	if (dir == 1)
	{
		s[0].x -= 1;
		head.setRotation(270.f);
		head.setPosition((s[1].x * 20) - scl, (s[1].y * 20) + scl);
	}
	if (dir == 2)
	{
		s[0].x += 1;
		head.setRotation(90.f);
		head.setPosition((static_cast<float>(s[1].x) * 20.f) + scl * 2.f, static_cast<float>(s[1].y) * 20.f);
	}
	if (dir == 3)
	{
		s[0].y -= 1;
		head.setRotation(0.f);
		head.setPosition(static_cast<float>(s[1].x) * 20, (static_cast<float>(s[1].y) * 20) - scl);
	}


	// Controllo se il bruco ha mangiato la mela e
	// creazione della nuova mela
	if (s[0].x == apple.getX() && s[0].y == apple.getY())
	{
		num++;
		s.push_back(Int2());
		points.add(10U);
		std::cout << points.getPoints() << std::endl;
		if (gameMode == 1 && fps <= 10)
		{
			fps += 1;
		}
		apple.getX();
		apple.getY();
		apple.changePos();

	}
	for (int i = 1; i < num; i++)
	{
		if (s[i].x == s[0].x && s[i].y == s[0].y) death(points, connect);
	}

	isOn = true;
	// Controllo se la mela è sopra al bruco
	do
	{
		isOn = false;
		for (int i = 0; i < num; i++)
		{
			if (s[i].x == apple.getX() && s[i].y == apple.getY())
			{
				apple.changePos();
				isOn = true;
			}
		}
	} while (isOn == true);
}

void Snake::death(Points &points, net::Connection *connect)
{
	fps = (gameMode == 1) ? 2 : 6;
	num = 1;
	s.erase(s.begin() + 2, s.end());
	s[0].x = 0;
	s[0].y = 0;
	dir = 0;
	delay = SfmlAPI::fpsAsSecs(fps);
	points.save();
	points.reset();
	connect->sendScore(points.getMaxPoints(), getUser());
	clearEvent = true;
	gameStatus = 0;
}