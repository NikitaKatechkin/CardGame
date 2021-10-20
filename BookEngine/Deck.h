#pragma once
#include <random>
#include <ctime>
#include <functional>

#include "Hand.h"
#include "Canvas.h"
#include "RenderDeck.h"

class Deck : public Hand
{
private:
	int m_capacity;

	RenderDeck* m_renderDeckObject;
public:
	void populate();
	void shuffle();

	void deal(Hand* l_hand);

	void print();

	RenderDeck* getRenderObject();
	void setRenderObject(RenderDeck* l_renderDeckObject);

	Deck(int l_deck_size = 52, sf::Vector2f l_topLeftCoord = sf::Vector2f(0.f, 0.f),
		sf::Vector2f l_size = sf::Vector2f(0.f, 0.f));
	~Deck();
};

