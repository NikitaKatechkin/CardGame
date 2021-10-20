#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

#include "RenderHand.h"

class Hand
{
protected:
	std::vector<Card*> m_cards;
	int m_max_size;

	RenderHand* m_renderObject;
public:
	void addCard(Card* l_card);
	Card* getCard(int l_cardIndex);

	void clear();

	void print();

	int getTotal();

	bool isFull();
	bool isEmpty();

	std::vector<Card*> getCards();

	int getNumOfCardsInHand();

	RenderHand* getRenderObject();
	void setRenderObject(RenderHand* l_renderObject);

	Hand(int l_max_size = 5, 
		std::string pathToTextureConfig = "config/hand_background_texture.ini",
		std::string pathToSpriteConfig = "config/hand_background_sprite.ini");
	~Hand();
};

