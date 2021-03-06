#pragma once
#include <SFML/Graphics.hpp>
#include <SfmlAPI.hpp>
#include "strings.h"
#include "jsonParser/SavedData.h"

class Points
{
public:
	Points(unsigned int points = 0U);
	Points(sf::Vector2f pos, const sf::Font &font, unsigned int size);
	~Points();
	void setPosition(sf::Vector2f pos);
	void setPosition(float x, float y);
	void setFont(const sf::Font &font);
	void setCharSize(unsigned int size);
	void save();
	void reset();
	void add(unsigned int p);
	void draw(sf::RenderWindow &window);

	unsigned int getPoints() const;
	unsigned int getMaxPoints() const;

private:
	unsigned int							m_points;
	sf::Text								m_text;
};