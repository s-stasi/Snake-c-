#pragma once

int width = 600;
int height = 600;
float width_f = 600.0f;
float height_f = 600.0f;
float scl = 20.0;
int scl_i = 20;
int dim = 30;
int dir, num = 1;
int gameStatus = 0;
int gameMode;
bool close, isOn = false;
float timer = 0, delay = 0.15f;


// Creazione del bruco
struct Snake
{
	int x, y;
}  s[900];

void death()
{
	num = 1;
	s[0].x = 0;
	s[0].y = 0;
	dir = 0;
	delay = 0.15f;
	gameStatus = 0;
}

// Funzione gestione dei movimenti del bruco e posizionamento della mela
void move(Apple &apple, Points &points, sf::Sprite &head) {
	// Controllo se il bruco è fuori dal campo di gioco
	if (s[0].x == dim || s[0].y == dim || s[0].x == 0 - 1 || s[0].y == 0 - 1)
	{
		death();
	}
	for (int i = num; i > 0; i--)
	{
		// Spostamento del bruco
		s[i].x = s[i - 1].x;
		s[i].y = s[i - 1].y;
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
		head.setPosition((s[1].x * 20) + scl * 2, s[1].y * 20);
	}
	if (dir == 3)
	{
		s[0].y -= 1;
		head.setRotation(0.f);
		head.setPosition(s[1].x * 20, (s[1].y * 20) - scl);
	}

	// Controllo se il bruco ha mangiato la mela e
	// creazione della nuova mela
	if (s[0].x == apple.getX() && s[0].y == apple.getY())
	{
		num++;
		points.add(10U);
		std::cout << points.getPoints() << std::endl;
		std::cout << "Gamemode: " << gameMode << std::endl;
		if (gameMode == 1 && delay > 0.25f)
		{
			delay -= 0.04f;
		}
		apple.getX();
		apple.getY();
		apple.changePos();

	}
	for (int i = 1; i < num; i++)
	{
		if (s[i].x == s[0].x && s[i].y == s[0].y) death();
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

int snake()
{
	// Creazione fnestra
	sf::RenderWindow window(sf::VideoMode(width, height), "Snake", sf::Style::Close | sf::Style::Titlebar);

	sf::Texture head;
	if (!head.loadFromFile("img/head.bmp"))
	{
		std::cout << "failed to load head image" << std::endl;
	}
	sf::Sprite spriteHead;
	spriteHead.setTexture(head);

	// Icona applicazione
	sf::Image icon;
	if (!icon.loadFromFile("img/icon.bmp"))
	{
		std::cout << "failed to load icon image" << std::endl;
	}
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	// Creazione quadrati della mela e del bruco
	sf::RectangleShape rectangle(sf::Vector2f(scl, scl));
	rectangle.setFillColor(sf::Color::Green);
	sf::RectangleShape rectapple(sf::Vector2f(20, 20));
	rectapple.setFillColor(sf::Color::Red);

	// Creazione prima mela
	std::cout << "Inizializzazione mela" << std::endl;
	Apple apple(rectapple, dim, scl_i);
	apple.changePos();
	apple.draw(window);

	// Versione
	Version version(VERSION, width_f, height_f);

	// Oggetti per il framerate
	sf::Clock clock;

	// Menu
	MainMenu menu(width_f, height_f);

	// Menu modalità
	ModMenu modMenu(width_f, height_f);

	Points points;

	// loop del gioco
	while (window.isOpen())
	{
		isGameWindowOpen = true;
		if (close == true) window.close();
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		sf::Event e;


		if (gameStatus == 0)
		{
			while (window.pollEvent(e))
			{
				switch (e.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyReleased:
					switch (e.key.code)
					{
					case sf::Keyboard::Up:
						std::cout << "pressed up arrow" << std::endl;
						menu.moveUp();
						break;
					case sf::Keyboard::Down:
						std::cout << "pressed down arrow" << std::endl;
						menu.moveDown();
						break;
					case sf::Keyboard::Return:
						switch (menu.getPressedItem())
						{
						case 0:
							gameStatus = 1;
							break;
						case 1:
							gameStatus = 2;
							break;
						case 2:
							window.close();
						}
						break;
					}
					break;
				}
			}
			window.clear(sf::Color::Black);
			menu.draw(window);
		}

		else if (gameStatus == 1)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && dir != 2) dir = 1;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && dir != 1) dir = 2;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && dir != 0) dir = 3;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && dir != 3) dir = 0;
			if (timer>delay)
			{
				timer = 0;
				move(apple, points, spriteHead);
			}
			window.clear(sf::Color::Black);

			for (int i = 1; i<num; i++)
			{
				rectangle.setPosition(s[i].x*scl, s[i].y*scl);
				window.draw(rectangle);
			}
			window.draw(spriteHead);
			apple.draw(window);
		}

		else if (gameStatus == 2)
		{
			while (window.pollEvent(e))
			{
				switch (e.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyReleased:
					switch (e.key.code)
					{
					case sf::Keyboard::Up:
						std::cout << "pressed up arrow" << std::endl;
						modMenu.moveUp();
						break;
					case sf::Keyboard::Down:
						std::cout << "pressed down arrow" << std::endl;
						modMenu.moveDown();
						break;
					case sf::Keyboard::Return:


						switch (modMenu.getPressedItem())
						{
						case 0:
							std::cout << "normale" << std::endl;
							gameMode = 0;
							break;
						case 1:
							std::cout << "veloce" << std::endl;
							gameMode = 1;
							break;
						case 2:
							std::cout << "exit" << std::endl;
							gameStatus = 0;
							std::cout << gameStatus << std::endl;
							break;
						}
						std::cout << "Item: " << modMenu.getPressedItem() << std::endl;
						break;
					}
					break;
				}
			}
			window.clear(sf::Color::Black);
			modMenu.draw(window);
		}


		version.draw(window);
		window.display();
	}
	return 0;
}
