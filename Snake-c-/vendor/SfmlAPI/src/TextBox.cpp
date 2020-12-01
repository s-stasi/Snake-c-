#include "../include/TextBox.hpp"


namespace SfmlAPI{

	TextBox::TextBox()
	{
	}

	TextBox::TextBox(int charSize, sf::Color textColor, bool sel)
	{
		textbox.setCharacterSize(charSize);
		textbox.setFillColor(textColor);
		isSelected = sel;
		if (sel)
		{
			textbox.setString("_");
		}
		else
		{
			textbox.setString("");
		}

	}

	void TextBox::setFont(sf::Font &font)
	{
		textbox.setFont(font);
	}

	void TextBox::setPosition(sf::Vector2f pos)
	{
		textbox.setPosition(pos);
	}

	void TextBox::setLimit(bool tof)
	{
		hasLimit = tof;
	}

	void TextBox::setLimit(bool tof, size_t lim)
	{
		hasLimit = tof;
		limit = lim;
	}

	void TextBox::setSelected(bool sel)
	{
		isSelected = sel;
		if (!sel)
		{
			std::string t = text.str();
			std::string newT = "";
			for (size_t i = 0; i < t.length(); i++)
			{
				newT += t[i];
			}
			textbox.setString(newT);
		}
	}

	std::string TextBox::getText() const
	{
		return text.str();
	}

	void TextBox::typedOn(sf::Event input)
	{
		if (isSelected)
		{
			int charTyped = input.text.unicode;
			if (charTyped < 128)
			{
				if (hasLimit)
				{
					if (text.str().length() <= limit)
					{
						inputManager(charTyped);
					}
					if (text.str().length() > limit && charTyped == DELETE_KEY)
					{
						deleteLastChar();
					}
				}
				else
				{
					inputManager(charTyped);
				}
			}
		}
	}

	void TextBox::draw(sf::RenderWindow &window)
	{
		window.draw(textbox);
	}

	TextBox::~TextBox()
	{
	}

}