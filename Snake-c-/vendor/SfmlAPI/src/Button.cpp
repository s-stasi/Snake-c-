#include "../include/Button.hpp"
namespace SfmlAPI {

	Button::Button()
	{
	}

	Button::Button(std::string string, sf::Vector2f size, sf::Color bgColor, sf::Color textColor, sf::Font &font)
	{
		text.setString(string);
		text.setFillColor(textColor);
		text.setFont(font);

		rect.setSize(size);
		rect.setFillColor(bgColor);
	}

	Button::~Button()
	{
	}

	void Button::setBgColor(sf::Color bgColor)
	{
		rect.setFillColor(bgColor);
	}

	void Button::setTextColor(sf::Color textColor)
	{
		text.setFillColor(textColor);
	}

	void Button::setPosition(sf::Vector2f pos)
	{
		rect.setPosition(pos);
		text.setPosition(pos.x + (text.getGlobalBounds().width / 3), pos.y + (text.getGlobalBounds().height / 3));
	}

	void Button::setPosition(float x, float y)
	{
		rect.setPosition(x, y);
		text.setPosition(x + (rect.getGlobalBounds().width / 3), y + (rect.getGlobalBounds().height / 3));
	}

	void Button::draw(sf::RenderWindow & window)
	{
		window.draw(rect);
		window.draw(text);
	}
}