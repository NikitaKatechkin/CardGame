#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"

class Mouse
{
private:
	sf::Mouse m_mouse;
	sf::Vector2i m_clickedPosition;
public:
	void updateEvent(Window* l_window);

	sf::Vector2i getClickedPosition();

	Mouse();
	~Mouse();
};

