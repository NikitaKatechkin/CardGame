#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <fstream>
#include <sstream>

class Drawable
{
protected:
	sf::Texture* m_texture;
	sf::Sprite* m_sprite;
public:
	void initTexture(std::string pathToConfigFile);
	void initSprite(std::string pathToConfigFile);

	sf::Vector2f getSpritePosition();
	void setSpritePosition(float l_x, float l_y);

	void setColor(int l_color);

	sf::Vector2f getSpriteSize();

	void setSpriteScale(float l_width, float l_height);
	sf::Vector2f getSpriteScale();

	sf::Sprite getSprite();

	//Подлежит удалению в силу ФИЛОСОФСКОЙ НЕЛОГИЧНОСТИ
	void draw(sf::RenderWindow* l_window);

	Drawable(std::string pathToTextureConfigFile, std::string pathToSpriteConfigFile);
	Drawable();
	Drawable(Drawable* l_copy);

	~Drawable();
};

