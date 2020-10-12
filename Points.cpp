#include "Points.h"



Points::Points(unsigned int points)
	: m_points(points), m_path(points_file)
{
	std::ifstream maxPFile(m_path);
	std::string str;
	std::getline(maxPFile, str);
	maxPFile.close();
	m_maxPoints = static_cast<unsigned int>(std::stoi(str));
}

Points::Points(sf::Vector2f pos, const sf::Font & font, unsigned int size)
	: m_points(0U), m_path(points_file)
{
	m_text.setPosition(pos);
	m_text.setFont(font);
	m_text.setCharacterSize(size);
	std::ifstream maxPFile(m_path);
	std::string str;
	std::getline(maxPFile, str);
	maxPFile.close();
	m_maxPoints = static_cast<unsigned int>(std::stoi(str));
	std::cout << m_maxPoints << std::endl;
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

unsigned int Points::getMaxPoints() const
{
	return m_maxPoints;
}
