#include "Mouse.h"



void Mouse::updateEvent(Window * l_window)
{
	sf::Event event = *(l_window->getEvent());
	m_clickedPosition = sf::Vector2i(0, 0);
	if (event.type == sf::Event::MouseButtonPressed)
	{
		switch (event.mouseButton.button)
		{
		case sf::Mouse::Button::Left:
			m_clickedPosition = m_mouse.getPosition(*(l_window->getWindow()));
			break;
		default:
			break;
		}
	}
}

sf::Vector2i Mouse::getClickedPosition()
{
	return m_clickedPosition;
}

Mouse::Mouse()
{
}


Mouse::~Mouse()
{
}
