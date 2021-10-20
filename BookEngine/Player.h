#pragma once
#include "GeneralPlayer.h"
class Player :
	public GeneralPlayer
{
public:
	void sendCard2House(sf::Vector2i l_pressedCoords);
	void takeDeckCard2Hand();
	void clearHouse();

	Player(int l_hand_size = 7, int l_house_size = 5, int l_deck_size = 52, int l_health = 300);
	~Player();
};

