#include "ButtonRect.h"



sf::Vector2f ButtonRect::GetPosition()
{
	return m_rects.getPosition();
}

void ButtonRect::SetPosition(sf::Vector2f l_position)
{
	m_rects.setPosition(l_position);
}

sf::Vector2f ButtonRect::GetSize()
{
	return m_rects.getSize();
}

void ButtonRect::SetSize(sf::Vector2f l_size)
{
	m_rects.setSize(l_size);
}

void ButtonRect::SetRectOrigin(sf::Vector2f l_origin)
{
	sf::FloatRect currentRect = m_rects.getGlobalBounds();
	m_rects.setOrigin(currentRect.left + l_origin.x, 
		currentRect.top + l_origin.y);
}

sf::Text * ButtonRect::GetText()
{
	return &m_text;
}

sf::RectangleShape * ButtonRect::GetRectShape()
{
	return &m_rects;
}

void ButtonRect::SetFillColor(sf::Color l_color)
{
	m_rects.setFillColor(l_color);
}

sf::Color ButtonRect::getFillColor()
{
	return m_rects.getFillColor();
}

ButtonRect::ButtonRect()
{
}


ButtonRect::~ButtonRect()
{
}
