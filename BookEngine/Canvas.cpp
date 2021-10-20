#include "Canvas.h"



sf::Vector2f Canvas::getTopLeftCoords()
{
	return sf::Vector2f(m_coordinate_plane->left, m_coordinate_plane->top);
}

void Canvas::setTopLeftCoords(sf::Vector2f l_topLeftCoords)
{
	m_coordinate_plane->left = l_topLeftCoords.x;
	m_coordinate_plane->top = l_topLeftCoords.y;
}

sf::Vector2f Canvas::getCanvasSize()
{
	return sf::Vector2f(m_coordinate_plane->width, m_coordinate_plane->height);
}

void Canvas::setCanvasSize(sf::Vector2f l_size)
{
	m_coordinate_plane->width = l_size.x;
	m_coordinate_plane->height = l_size.y;
}

Canvas::Canvas(sf::Vector2f l_size, sf::Vector2f l_topLeftCoords)
{
	m_coordinate_plane = new sf::Rect<float>(l_topLeftCoords.x, l_topLeftCoords.y, 
		l_size.x, l_size.y);
}

Canvas::Canvas(Canvas * l_copy) :
	m_coordinate_plane(new sf::Rect<float>(l_copy->getTopLeftCoords(),
		l_copy->getCanvasSize()))
{
}


Canvas::~Canvas()
{
	//delete m_coordinate_plane;
}
