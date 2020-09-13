#include "Points.h"



Points::Points(unsigned int points)
	: m_points(points), m_path("C:/Users/" + SfmlAPI::getSystemUser() + "/AppData/Local/Snake/src/points")
{
}

Points::Points(sf::Vector2f pos, const sf::Font & font, unsigned int size)
	: m_points(0U), m_path("C:/Users/" + SfmlAPI::getSystemUser() + "/AppData/Local/Snake/src/points")
{
	m_text.setPosition(pos);
	m_text.setFont(font);
	m_text.setCharacterSize(size);
}

Points::~Points()
{
}

void Points::setPosition(sf::Vector2f pos)
{
	m_text.setPosition(pos);
}

void Points::setPosition(float x, float y)
{
	m_text.setPosition(x, y);
}

void Points::setFont(const sf::Font & font)
{
	m_text.setFont(font);
}

void Points::setCharSize(unsigned int size)
{
	m_text.setCharacterSize(size);
}

void Points::save()
{
	std::ofstream out(m_path, std::ios::trunc);
	out << m_points;
}

void Points::reset()
{
	m_points = 0;
}

void Points::add(unsigned int p)
{
	m_points += p;
}

void Points::draw(sf::RenderWindow &window)
{
	m_text.setString(std::to_string(m_points));
	window.draw(m_text);
}

unsigned int Points::getPoints() const
{
	return m_points;
}
