#pragma once
#include <iostream>
#include <fstream>
#include <experimental/filesystem>
#include <filesystem>
#include "SfmlAPI.hpp"

bool isFirstLaunch()
{
	std::experimental::filesystem::path firstAccess("src\\firstAccess.confirm");
	if (!std::experimental::filesystem::exists(firstAccess))
	{
		std::cout << "vero" << std::endl;
		std::ofstream out(firstAccess);
		out << "not first access";
		out.close();
		return true;
	}
	else
	{
		std::cout << "falso" << std::endl;
		return false;
	}
}

void saveUserName(std::string name)
{
	std::experimental::filesystem::path userName("src\\username");
	std::ofstream out(userName, std::ios::trunc);
	out << name;
	out.close();
}

bool setUser()
{
	if (isFirstLaunch())
	{
		std::string name;

		sf::RenderWindow setUserWindow(sf::VideoMode(200, 50), "", sf::Style::None);
		sf::Font arial;
		arial.loadFromFile("Font/arial.ttf");

		SfmlAPI::TextBox textbox(10, sf::Color::White, true);
		textbox.setFont(arial);
		textbox.setPosition({ 10, 20 });
		textbox.setLimit(true, (size_t)20);

		sf::Event e;
		while (setUserWindow.isOpen())
		{
			while (setUserWindow.pollEvent(e))
			{
				switch (e.type)
				{
				case sf::Event::TextEntered:
					textbox.typedOn(e);
					break;
				case sf::Event::KeyReleased:
					switch (e.key.code)
					{
					case sf::Keyboard::Enter:
						name = textbox.getText();
						setUserWindow.close();
						saveUserName(name);
						break;
					}
				}
			}
			setUserWindow.clear(sf::Color(10, 10, 10, 255));
			textbox.draw(setUserWindow);
			setUserWindow.display();
		}
	}
	return false;
}