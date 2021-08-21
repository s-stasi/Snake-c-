#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <SfmlAPI.hpp>
#include <array>

#include <loguru.hpp>

#include "jsonParser/SavedData.h"

std::array<std::filesystem::path, 4> dirList = { 
	std::filesystem::path("C:/Users") / SfmlAPI::getSystemUser() / "AppData/local/Snake",
	dirList[0] / "img",
	dirList[1] / "heads",
	dirList[0] / "Font"
};


void saveUserName(std::string name)
{
	SavedData::setUsername(name);
	SavedData::setFirstLaunch(false);
}

std::string getUser()
{
	return SavedData::Data::userName;
}

void setUser()
{
	std::string name;

	sf::RenderWindow setUserWindow(sf::VideoMode(200, 75), "", sf::Style::None);

	SfmlAPI::TextBox textbox(15, sf::Color::White, true);
	textbox.setFont(SavedData::Data::Arial);
	textbox.setPosition({ 10, 40 });
	textbox.setLimit(true, (size_t)20);

	sf::Text title;
	title.setFillColor(sf::Color::White);
	title.setCharacterSize(15U);
	title.setFont(SavedData::Data::Arial);
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

void createDirectories()
{
	LOG_F(INFO, "Creating directories:");
	for (auto& i : dirList)
	{
		LOG_F(INFO, i.string().c_str());
		std::filesystem::create_directory(i);
	}
	LOG_F(INFO, "Done");
}

void copyImgs()
{
	LOG_F(INFO, "Copying images:");
	LOG_F(INFO, "img/icon.bmp");
	try
	{
		std::filesystem::copy_file("./img/icon.bmp", dirList[1] / "icon.bmp");
	}
	catch (const std::filesystem::filesystem_error& e)
	{
		LOG_F(WARNING, "Filesystem exception thrown");
		LOG_F(WARNING, e.what());
	}
	LOG_F(INFO, "img/heads/red.bmp");
	try
	{
		std::filesystem::copy_file("./img/heads/red.bmp", dirList[2] / "red.bmp");
	}
	catch (const std::filesystem::filesystem_error& e)
	{
		LOG_F(WARNING, "Filesystem exception thrown");
		LOG_F(WARNING, e.what());
	}
	LOG_F(INFO, "Done");
}

void copyFont()
{
	LOG_F(INFO, "Copying font:");
	LOG_F(INFO, "Font/arial.bmp");
	try
	{
		std::filesystem::copy_file("Font/arial.ttf", dirList[3] / "arial.ttf");
	}
	catch (const std::filesystem::filesystem_error& e)
	{
		LOG_F(WARNING, "Filesystem exception thrown");
		LOG_F(WARNING, e.what());
	}
}

void initializeGame() 
{
	createDirectories();
	copyImgs();
	copyFont();
	setUser();
}