#include "Snake.h"

Snake::Snake(sf::RenderWindow *w, net::Connection *cnn, float *del, int *gSt)
	: window(w), connection(cnn), delay(del), gameStatus(gSt)
{
	rectangle.setSize({ scl, scl });
	rectangle.setFillColor(sf::Color::Green);
	head = new renderHead(sf::Color::Green, (std::string)"green");
	apple = new Apple(dim, static_cast<int>(scl));
	points = new Points({ static_cast<float>(window->getSize().x) / 2, 20.f }, SavedData::Data::Arial, 20U);
	s.push_back(Int2());
	s.push_back(Int2());
}

Snake::~Snake()
{
}

void Snake::eventDispatcher(sf::Event &e)
{
	while (window->pollEvent(e))
	{
		switch (e.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && dir != 2) dir = 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && dir != 1) dir = 2;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && dir != 0) dir = 3;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && dir != 3) dir = 0;
	window->clear(sf::Color::Black);

	for (int i = 1; i<num; i++)
	{
		rectangle.setPosition(s[i].x*scl, s[i].y*scl);
		window->draw(rectangle);
	}
	draw();
}

void Snake::move()
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
		death();
		return;
	}

	if (dir == 0)
	{
		s[0].y += 1;
		head->setRotation(180.f);
		head->setPosition((s[1].x * 20) + scl, (s[1].y * 20) + scl * 2);
	}
	if (dir == 1)
	{
		s[0].x -= 1;
		head->setRotation(270.f);
		head->setPosition((s[1].x * 20) - scl, (s[1].y * 20) + scl);
	}
	if (dir == 2)
	{
		s[0].x += 1;
		head->setRotation(90.f);
		head->setPosition((static_cast<float>(s[1].x) * 20.f) + scl * 2.f, static_cast<float>(s[1].y) * 20.f);
	}
	if (dir == 3)
	{
		s[0].y -= 1;
		head->setRotation(0.f);
		head->setPosition(static_cast<float>(s[1].x) * 20, (static_cast<float>(s[1].y) * 20) - scl);
	}


	// Controllo se il bruco ha mangiato la mela e
	// creazione della nuova mela
	if (s[0].x == apple->getX() && s[0].y == apple->getY())
	{
		num++;
		s.push_back(Int2());
		points->add(10U);
		std::cout << points->getPoints() << std::endl;
		if (gameMode == 1 && fps <= 10)
		{
			fps += 1;
			*delay = SfmlAPI::fpsAsSecs(fps);
		}
		apple->getX();
		apple->getY();
		apple->changePos();

	}
	for (int i = 1; i < num; i++)
	{
		if (s[i].x == s[0].x && s[i].y == s[0].y) death();
	}
	for (int i = 1; i<num; i++)
	{
		rectangle.setPosition(s[i].x*scl, s[i].y*scl);
		window->draw(rectangle);
	}

	isOn = true;
	// Controllo se la mela è sopra al bruco
	do
	{
		isOn = false;
		for (int i = 0; i < num; i++)
		{
			if (s[i].x == apple->getX() && s[i].y == apple->getY())
			{
				apple->changePos();
				isOn = true;
			}
		}
	} while (isOn == true);
}

void Snake::draw()
{
	points->draw(*window);
	head->draw(*window);
	apple->draw(*window);
}

void Snake::death()
{
	fps = (gameMode == 1) ? 2 : 6;
	num = 1;
	s.erase(s.begin() + 2, s.end());
	s[0].x = 0;
	s[0].y = 0;
	dir = 0;
	*delay = SfmlAPI::fpsAsSecs(fps);
	points->save();
	points->reset();
	connection->sendScore(points->getMaxPoints(), SavedData::Data::userName);
	clearEvent = true;
	*gameStatus = 0;
	isDeletable = true;
}

void Snake::setMode(int mode)
{
	gameMode = mode;
}

bool Snake::toDelete()
{
	if (isDeletable)
	{
		isDeletable = false;
		return true;
	}
	else
		return false;
}

ultrashort_t Snake::gameMode = Snake::mode::normal;
int Snake::fps = 6;