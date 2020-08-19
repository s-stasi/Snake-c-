#pragma once
using namespace sf;
using std::string;

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
void move(Apple &apple) {
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

	if (dir == 0) { s[0].y += 1; }
	if (dir == 1) { s[0].x -= 1; }
	if (dir == 2) { s[0].x += 1; }
	if (dir == 3) { s[0].y -= 1; }

	// Controllo se il bruco ha mangiato la mela e
	// creazione della nuova mela
	if (s[0].x == apple.getX() && s[0].y == apple.getY())
	{
		//std::cout << apple.getX() << " " << apple.getY() << std::endl;
		num++;
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
	RenderWindow window(VideoMode(width, height), "Snake", sf::Style::Close | sf::Style::Titlebar);

	// Icona applicazione
	Image icon;
	if (!icon.loadFromFile("icon.bmp"))
	{
		std::cout << "failed to load image" << std::endl;
	}
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	// Creazione quadrati della mela e del bruco
	RectangleShape rectangle(Vector2f(scl, scl));
	rectangle.setFillColor(Color::Green);
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
	Clock clock;

	// Menu
	MainMenu menu(width_f, height_f);

	// Menu modalità
	ModMenu modMenu(width_f, height_f);

	// loop del gioco
	while (window.isOpen())
	{
		if (close == true) window.close();
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		Event e;


		if (gameStatus == 0)
		{
			while (window.pollEvent(e))
			{
				switch (e.type)
				{
				case Event::Closed:
					window.close();
					break;
				case Event::KeyReleased:
					switch (e.key.code)
					{
					case Keyboard::Up:
						std::cout << "pressed up arrow" << std::endl;
						menu.moveUp();
						break;
					case Keyboard::Down:
						std::cout << "pressed down arrow" << std::endl;
						menu.moveDown();
						break;
					case Keyboard::Return:
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
			window.clear(Color::Black);
			menu.draw(window);
		}

		else if (gameStatus == 1)
		{
			if (Keyboard::isKeyPressed(Keyboard::Left) && dir != 2) dir = 1;
			if (Keyboard::isKeyPressed(Keyboard::Right) && dir != 1) dir = 2;
			if (Keyboard::isKeyPressed(Keyboard::Up) && dir != 0) dir = 3;
			if (Keyboard::isKeyPressed(Keyboard::Down) && dir != 3) dir = 0;
			if (timer>delay)
			{
				timer = 0;
				move(apple);
			}
			window.clear(Color::Black);

			for (int i = 0; i<num; i++)
			{
				rectangle.setPosition(s[i].x*scl, s[i].y*scl);
				window.draw(rectangle);
			}
			apple.draw(window);
		}

		else if (gameStatus == 2)
		{
			while (window.pollEvent(e))
			{
				switch (e.type)
				{
				case Event::Closed:
					window.close();
					break;
				case Event::KeyReleased:
					switch (e.key.code)
					{
					case Keyboard::Up:
						std::cout << "pressed up arrow" << std::endl;
						modMenu.moveUp();
						break;
					case Keyboard::Down:
						std::cout << "pressed down arrow" << std::endl;
						modMenu.moveDown();
						break;
					case Keyboard::Return:


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
			window.clear(Color::Black);
			modMenu.draw(window);
		}

		version.draw(window);
		window.display();
	}
	return 0;
}
