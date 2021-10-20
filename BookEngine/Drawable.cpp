#include "Drawable.h"



void Drawable::initTexture(std::string pathToConfigFile)
{
	m_texture = new sf::Texture;

	std::ifstream inFileStream(pathToConfigFile);

	std::string path = "D:\\CourseProject\\HSECardGame\\HSECardGame\\images\\card_back.png";

	if (inFileStream.is_open())
	{
		std::getline(inFileStream, path);
	}

	inFileStream.close();

	m_texture->loadFromFile(path);
}

void Drawable::initSprite(std::string pathToConfigFile)
{
	m_sprite = new sf::Sprite;

	std::ifstream inFileStream(pathToConfigFile);

	int width = 241;
	int height = 359;

	float x_scale = 1;
	float y_scale = 1;

	if (inFileStream.is_open())
	{
		inFileStream >> width >> height;
		inFileStream >> x_scale >> y_scale;
	}

	inFileStream.close();

	m_sprite->setTexture(*m_texture);
	m_sprite->setTextureRect(sf::IntRect(0, 0, width, height));
	m_sprite->setScale(x_scale, y_scale);
}

sf::Vector2f Drawable::getSpritePosition()
{
	return m_sprite->getPosition();
}

void Drawable::setSpritePosition(float l_x, float l_y)
{
	m_sprite->setPosition(sf::Vector2f(l_x, l_y));
}

void Drawable::setColor(int l_color)
{
	m_sprite->setTextureRect(sf::IntRect(l_color * 18, 0, 18, 18));
}

sf::Vector2f Drawable::getSpriteSize()
{
	return sf::Vector2f(m_sprite->getGlobalBounds().width, m_sprite->getGlobalBounds().height);
}

void Drawable::setSpriteScale(float l_width, float l_height)
{
	m_sprite->setScale(l_width, l_height);
}

sf::Vector2f Drawable::getSpriteScale()
{
	return m_sprite->getScale();
}

sf::Sprite Drawable::getSprite()
{
	return *m_sprite;
}

void Drawable::draw(sf::RenderWindow * l_window)
{
	l_window->draw(*m_sprite);
}

Drawable::Drawable(std::string pathToTextureConfigFile, std::string pathToSpriteConfigFile)
{
	initTexture(pathToTextureConfigFile);
	initSprite(pathToSpriteConfigFile);
}

Drawable::Drawable()
{
	m_texture = new sf::Texture;
	m_sprite = new sf::Sprite;
}

Drawable::Drawable(Drawable * l_copy)
{
	m_sprite = new sf::Sprite(l_copy->getSprite());
	m_texture = new sf::Texture(*m_sprite->getTexture());
}

Drawable::~Drawable()
{
	delete m_sprite;
	delete m_texture;
}
