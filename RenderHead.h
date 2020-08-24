#pragma once
class renderHead
{
public:
	renderHead();
	renderHead(sf::Color &color, std::string colName);
	~renderHead();

	void setPosition(float x, float y);
	void setPosition(sf::Vector2f pos);
	void setRotation(float angle);

	void draw(sf::RenderWindow &window);
private:
	std::string		m_path;
	sf::Image		m_head;
	sf::Texture		m_textureHead;
	sf::Sprite		m_spriteHead;
	sf::Color		m_color;

	void createImage();
	void saveImage();
	void loadImg();
};

