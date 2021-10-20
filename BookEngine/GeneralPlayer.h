#pragma once
#include "RenderGeneralPlayer.h"

class GeneralPlayer
{
protected:
	Hand* m_hand;
	Hand* m_house;
	int m_health;
	Deck* m_deck;
	Deck* m_discard;

	RenderGeneralPlayer* m_renderObject;
public:
	bool isFullHand();
	bool isEmptyHand();

	bool isFullHouse();

	void takeDeckCard2Hand();
	void sendCard2House();

	int playedCardTotal();
	
	int getHealth();
	void setHealth(int l_health);

	void clearHouse();

	Hand* getHand();
	Deck* getDeck();
	Hand* getHouse();
	Deck* getDiscard();

	RenderGeneralPlayer* getRenderObject();
	void setRenderObject(RenderGeneralPlayer* l_renderDeckObject);

	//void draw(sf::RenderWindow* l_window, bool l_bottom = true);

	GeneralPlayer(int l_hand_size = 7, int l_house_size = 5, int l_deck_size = 52, int l_health = 300);
	~GeneralPlayer();
};

