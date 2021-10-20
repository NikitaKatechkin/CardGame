#pragma once
#include "Canvas.h"

class RenderObject
{
protected:
	Canvas* m_canvas;
public:
	Canvas* getCanvas();
	void setCanvas(Canvas* l_canvas);

	RenderObject(sf::Vector2f l_topLeftCoord = sf::Vector2f(0.f, 0.f),
		sf::Vector2f l_size = sf::Vector2f(0.f, 0.f));
	RenderObject(RenderObject* l_copy);
	~RenderObject();
};

