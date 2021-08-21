#pragma once

// Game version declaration
#define VERSION "0.0.4 beta"

// Defining global variables
static bool isGameWindowOpen = false;

#include "Apple.h"
#include "Version.h"
#include "RenderHead.h"
#include "firstLaunch.h"
#include "Points.h"
#include "Snake.h"


int width = 600;
int height = 600;
int dim = 30;
bool close, isOn = false;
float timer = 0, delay;
bool clearEvent = false;
int gameStatus = 0;


int main_window(net::Connection *connect)
{

	// Creazione fnestra
	sf::RenderWindow window(sf::VideoMode(width, height), "Snake", sf::Style::Close | sf::Style::Titlebar);

	renderHead head(sf::Color::Green, (std::string)"green");
	

	// Icona applicazione
	sf::Image icon;
	if (!icon.loadFromFile(icon_img))
	{
		LOG_F(ERROR, "Failed to load icon");
	}
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	// Creazione quadrati della mela e del bruco
	sf::RectangleShape rectangle(sf::Vector2f( (float)Snake::fps, (float)Snake::fps));
	rectangle.setFillColor(sf::Color::Green);

	// Creazione prima mela
	Apple apple(dim, static_cast<int>(Snake::fps));
	apple.changePos();
	apple.draw(window);

	// Versione
	Version version(VERSION, static_cast<float>(width), static_cast<float>(height));

	// Oggetti per il framerate
	sf::Clock clock;

	// Menu
	std::vector<std::string> mainMenu_str;
	mainMenu_str.push_back("Play");
	mainMenu_str.push_back("Settings");
	mainMenu_str.push_back("Exit");
	SfmlAPI::Menu mainMenu(mainMenu_str, SavedData::Data::Arial);

	// Menu modalità
	std::vector<std::string> modMenu_str;
	modMenu_str.push_back("Normal mode");
	modMenu_str.push_back("Progressive speed mode");
	modMenu_str.push_back("Exit");
	SfmlAPI::Menu modMenu(modMenu_str, SavedData::Data::Arial);


	Points points({static_cast<float>(window.getSize().x) / 2, 20.f}, SavedData::Data::Arial, 20U);

	sf::Clock fpsock;
	float lastTime = 0;

	sf::Event e;

	Snake* sn = nullptr;

	// loop del gioco
	while (window.isOpen())
	{
		isGameWindowOpen = true;
		if (close == true) window.close();
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;
		delay = SfmlAPI::fpsAsSecs(Snake::fps);

		if (gameStatus == 0)
		{
			if (clearEvent)
			{
				while (window.pollEvent(e));
				clearEvent = false;
			}

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
						mainMenu.moveUp();
						break;
					case sf::Keyboard::Down:
						mainMenu.moveDown();
						break;
					case sf::Keyboard::Return:
						switch (mainMenu.getPressedItem())
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
			mainMenu.draw(window);
		}

		else if (gameStatus == 1)
		{
			if (sn == nullptr)
				sn = new Snake(&window, connect, &delay, &gameStatus);
			
			sn->eventDispatcher(e);
			if (timer>delay)
			{
				timer = 0;
				sn->move();
			}
			if (sn->toDelete())
			{
				delete(sn);
				std::cout << "sn: " << sn << std::endl;
				sn = nullptr;
			}
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
							Snake::fps = 6;
							sn->setMode(Snake::mode::normal);
							break;
						case 1:
							std::cout << "veloce" << std::endl;
							Snake::fps = 2;
							sn->setMode(Snake::mode::progressive);
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
