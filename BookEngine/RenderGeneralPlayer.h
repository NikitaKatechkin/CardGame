#pragma once
#include "Canvas.h"
#include "Deck.h"

class RenderGeneralPlayer : public RenderObject
{
protected:

public:

	void draw(Hand* l_hand, Deck* l_deck, Deck* l_discard, Hand* l_house, sf::RenderWindow* l_window, bool l_bottom = true);

	RenderGeneralPlayer(sf::Vector2f l_topLeftCoord = sf::Vector2f(0.f, 0.f),
		sf::Vector2f l_size = sf::Vector2f(0.f, 0.f));
	RenderGeneralPlayer(RenderGeneralPlayer * l_copy);
	~RenderGeneralPlayer();
};

