#pragma once
#include <SFML/Graphics.hpp>

class Canvas
{
protected:
	sf::Rect<float>* m_coordinate_plane;
public:
	sf::Vector2f getTopLeftCoords();
	void setTopLeftCoords(sf::Vector2f l_topLeftCoords);

	sf::Vector2f getCanvasSize();
	void setCanvasSize(sf::Vector2f l_size);

	Canvas(sf::Vector2f l_size = sf::Vector2f(0.f, 0.f), 
		sf::Vector2f l_topLeftCoords = sf::Vector2f(0.f, 0.f));
	Canvas(Canvas * l_copy);
	~Canvas();
};

