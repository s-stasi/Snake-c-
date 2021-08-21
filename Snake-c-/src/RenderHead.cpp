#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <filesystem>
#include <SfmlAPI.hpp>
#include "RenderHead.h"


renderHead::renderHead()
{
}

renderHead::renderHead(const sf::Color color, std::string colName)
	:m_color(color)
{
	
	m_path = head_dir;
	m_path += colName + ".bmp";
	std::filesystem::path controlPath(m_path);
	if (!std::filesystem::exists(controlPath))
	{
		createImage();
		saveImage();
	}
	loadImg();
}

renderHead::~renderHead()
{
}

void renderHead::setPosition(float x, float y)
{
	m_spriteHead.setPosition(x, y);
}

void renderHead::setPosition(sf::Vector2f pos)
{
	m_spriteHead.setPosition(pos);
}

void renderHead::setRotation(float angle)
{
	m_spriteHead.setRotation(angle);
}

void renderHead::draw(sf::RenderWindow & window)
{
	window.draw(m_spriteHead);
}

void renderHead::createImage()
{
	m_head.create(20U, 20U);

	for (int i = 0; i <= 1; i++)
	{
		for (int j = 0; j <= 19; j++)
		{
			m_head.setPixel(i, j, m_color);
		}
	}

	for (int i = 2; i <= 5; i++)
	{
		m_head.setPixel(i, 0, m_color);
		m_head.setPixel(i, 1, m_color);
		for (int j = 2; j < 8; j++)
		{
			m_head.setPixel(i, j, sf::Color::Black);
		}
		m_head.setPixel(i, 8, m_color);
		m_head.setPixel(i, 9, m_color);
		m_head.setPixel(i, 10, m_color);
		m_head.setPixel(i, 11, m_color);
		for (int j = 12; j < 18; j++)
		{
			m_head.setPixel(i, j, sf::Color::Black);
		}
		m_head.setPixel(i, 18, m_color);
		m_head.setPixel(i, 19, m_color);
	}

	for (int i = 6; i <= 13; i++)
	{
		for (int j = 0; j <= 19; j++)
		{
			m_head.setPixel(i, j, m_color);
		}
	}

	m_head.setPixel(14, 0, m_color);
	m_head.setPixel(14, 1, m_color);
	m_head.setPixel(14, 2, m_color);
	m_head.setPixel(14, 3, m_color);
	m_head.setPixel(14, 4, sf::Color::Black);
	m_head.setPixel(14, 5, sf::Color::Black);
	m_head.setPixel(14, 6, sf::Color::Black);
	m_head.setPixel(14, 7, m_color);
	m_head.setPixel(14, 8, m_color);
	m_head.setPixel(14, 9, m_color);
	m_head.setPixel(14, 10, m_color);
	m_head.setPixel(14, 11, m_color);
	m_head.setPixel(14, 12, m_color);
	m_head.setPixel(14, 13, sf::Color::Black);
	m_head.setPixel(14, 14, sf::Color::Black);
	m_head.setPixel(14, 15, sf::Color::Black);
	m_head.setPixel(14, 16, m_color);
	m_head.setPixel(14, 17, m_color);
	m_head.setPixel(14, 18, m_color);
	m_head.setPixel(14, 19, m_color);

	m_head.setPixel(15, 0, m_color);
	m_head.setPixel(15, 1, m_color);
	m_head.setPixel(15, 2, m_color);
	m_head.setPixel(15, 3, m_color);
	for (int i = 4; i < 16; i++)
	{
		m_head.setPixel(15, i, sf::Color::Black);
	}
	m_head.setPixel(15, 16, m_color);
	m_head.setPixel(15, 17, m_color);
	m_head.setPixel(15, 18, m_color);
	m_head.setPixel(15, 19, m_color);

	m_head.setPixel(16, 0, m_color);
	m_head.setPixel(16, 1, m_color);
	m_head.setPixel(16, 2, m_color);
	m_head.setPixel(16, 3, m_color);
	m_head.setPixel(16, 4, m_color);
	m_head.setPixel(16, 5, m_color);
	m_head.setPixel(16, 6, m_color);
	for (int i = 7; i < 13; i++)
	{
		m_head.setPixel(16, i, sf::Color::Black);
	}
	m_head.setPixel(16, 13, m_color);
	m_head.setPixel(16, 14, m_color);
	m_head.setPixel(16, 15, m_color);
	m_head.setPixel(16, 16, m_color);
	m_head.setPixel(16, 17, m_color);
	m_head.setPixel(16, 18, m_color);
	m_head.setPixel(16, 19, m_color);

	for (int i = 17; i <= 19; i++)
	{
		for (int j = 0; j <= 19; j++)
		{
			m_head.setPixel(i, j, m_color);
		}
	}
}

void renderHead::saveImage()
{
	m_head.saveToFile(m_path);
}

void renderHead::loadImg()
{
	m_textureHead.loadFromFile(m_path);
	m_spriteHead.setTexture(m_textureHead);
}
