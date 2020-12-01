#pragma once
#include <sstream>
#include <SFML/Graphics.hpp>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

namespace SfmlAPI {
	class TextBox
	{
	public:
		TextBox();
		TextBox(int charSize, sf::Color textColor, bool sel);

		void setFont(sf::Font &font);

		void setPosition(sf::Vector2f pos);

		void setLimit(bool tof);
		void setLimit(bool tof, size_t lim);

		void setSelected(bool sel);

		std::string getText() const;

		void typedOn(sf::Event input);

		void draw(sf::RenderWindow &window);

		~TextBox();
	private:
		sf::Text textbox;
		std::ostringstream text;
		bool isSelected = false;
		bool hasLimit = false;
		size_t limit;

		void inputManager(int charTyped)
		{
			if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY)
			{
				text << static_cast<char>(charTyped);
			}
			else if (charTyped == DELETE_KEY)
			{
				if (text.str().length() > 0) deleteLastChar();
			}
			textbox.setString(text.str() += "_");
		}

		void deleteLastChar()
		{
			std::string t = text.str();
			std::string newT = "";
			for (size_t i = 0; i < t.length() -1; i++)
			{
				newT += t[i];
			}
			text.str("");
			text << newT;

			textbox.setString(text.str());
		}
	};
}