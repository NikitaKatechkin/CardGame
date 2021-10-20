#include "RenderObject.h"



Canvas * RenderObject::getCanvas()
{
	return m_canvas;
}

void RenderObject::setCanvas(Canvas * l_canvas)
{
	delete m_canvas;
	m_canvas = new Canvas(l_canvas);
}

RenderObject::RenderObject(sf::Vector2f l_topLeftCoord, sf::Vector2f l_size):
	m_canvas(new Canvas(l_size, l_topLeftCoord))
{
}

RenderObject::RenderObject(RenderObject * l_copy) :
	m_canvas(new Canvas(l_copy->getCanvas()))
{
}


RenderObject::~RenderObject()
{
	//delete m_canvas;
}
