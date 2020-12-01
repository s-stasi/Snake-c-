#include "../include/Menu.hpp"

namespace SfmlAPI {

	Menu::Menu()
	{
	}

	Menu::Menu(std::vector<std::string>& elem, sf::Font &font)
		: selectedItemIndex(0)
	{
		count = elem.size();
		for (unsigned int i = 0; i < count; i++)
		{
			text.push_back(sf::Text());
			text[i].setString(elem[i]);
			text[i].setFont(font);
			if (i != selectedItemIndex)
			{
				text[i].setFillColor(sf::Color::White);
			}
			else
			{
				text[i].setFillColor(sf::Color::Red);
			}
		}
	}


	Menu::~Menu()
	{
	}

	void Menu::setFont(sf::Font & font)
	{
		for (sf::Text elem : text)
		{
			elem.setFont(font);
		}
	}

	void Menu::draw(sf::RenderWindow & window)
	{
		for (unsigned int i = 0; i < count; i++)
		{
			text[i].setPosition(static_cast<float>(window.getSize().x) / 2.f - (text[i].getGlobalBounds().width / 2.f), (static_cast<float>(window.getSize().y) / (count + 1)) * (i + 1));
			window.draw(text[i]);
		}
	}

	void Menu::moveUp()
	{
		if (selectedItemIndex - 1 >= 0)
		{
			text[selectedItemIndex].setFillColor(sf::Color::White);
			selectedItemIndex--;
			text[selectedItemIndex].setFillColor(sf::Color::Red);
		}
		else
		{
			text[selectedItemIndex].setFillColor(sf::Color::White);
			selectedItemIndex += count - 1U;
			text[selectedItemIndex].setFillColor(sf::Color::Red);
		}
	}

	void Menu::moveDown()
	{
		if (selectedItemIndex + 1 < (int)count)
		{
			text[selectedItemIndex].setFillColor(sf::Color::White);
			selectedItemIndex++;
			text[selectedItemIndex].setFillColor(sf::Color::Red);
		}
		else
		{
			text[selectedItemIndex].setFillColor(sf::Color::White);
			selectedItemIndex -= count - 1U;
			text[selectedItemIndex].setFillColor(sf::Color::Red);
		}
	}

	int Menu::getPressedItem()
	{
		return selectedItemIndex;
	}
}