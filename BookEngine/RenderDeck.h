#pragma once
#include "Canvas.h"
#include "Card.h"

class RenderDeck : public RenderObject
{
protected:

public:

	void draw(sf::RenderWindow* l_window, std::vector<Card*> l_cards);

	RenderDeck(sf::Vector2f l_topLeftCoord = sf::Vector2f(0.f, 0.f), 
		sf::Vector2f l_size = sf::Vector2f(0.f, 0.f));
	RenderDeck(RenderDeck* l_copy);
	~RenderDeck();
};

