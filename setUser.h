#pragma once
#include <iostream>
#include <fstream>
#include <experimental/filesystem>
#include <filesystem>
#include "SfmlAPI.hpp"

void saveUserName(std::string name)
{
	std::experimental::filesystem::path userName(username_file);
	std::ofstream out(userName, std::ios::trunc);
	out << name;
	out.close();
}

void setUser()
{
	std::string name;

	sf::RenderWindow setUserWindow(sf::VideoMode(200, 75), "", sf::Style::None);
	sf::Font arial;
	arial.loadFromFile("Font/arial.ttf");

	SfmlAPI::TextBox textbox(15, sf::Color::White, true);
	textbox.setFont(arial);
	textbox.setPosition({ 10, 40 });
	textbox.setLimit(true, (size_t)20);

	sf::Text title;
	title.setFillColor(sf::Color::White);
	title.setCharacterSize(15U);
	title.setFont(arial);
	title.setString("Insert you username");
	title.setPosition((setUserWindow.getSize().x / 2) - (title.getGlobalBounds().width / 2), 5);


	sf::Event e;
	while (setUserWindow.isOpen())
	{
		while (setUserWindow.pollEvent(e))
		{
			switch (e.type)
			{
			case sf::Event::Closed:
				setUserWindow.close();
				break;
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
		setUserWindow.draw(title);
		setUserWindow.display();
	}
}