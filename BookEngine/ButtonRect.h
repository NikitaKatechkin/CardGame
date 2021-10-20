#pragma once
#include <SFML/Graphics.hpp>
#include "Text.h"
#include <time.h>
#include <iostream>
#include <fstream>
#include <sstream>

class ButtonRect
{
protected:
	sf::RectangleShape m_rects;
	sf::Text m_text;
public:
	sf::Vector2f GetPosition();
	void SetPosition(sf::Vector2f l_position);

	sf::Vector2f GetSize();
	void SetSize(sf::Vector2f l_size);

	void SetRectOrigin(sf::Vector2f l_origin);

	sf::Text* GetText();
	sf::RectangleShape* GetRectShape();

	void SetFillColor(sf::Color l_color);
	sf::Color getFillColor();

	ButtonRect();
	~ButtonRect();
};

