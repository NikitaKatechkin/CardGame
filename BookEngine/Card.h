#pragma once
#include "RenderCard.h"

class Card
{
private:
	int m_rank;
	bool m_isFaceUp;

	RenderCard* m_renderObject;
public:
	void Flip();
	bool isFaceUp();

	int getRank();
	void setRank(int l_rank);

	Card* operator=(Card* l_left);

	RenderCard* getRenderObject();
	void setRenderObject(RenderCard* l_renderObject);

	Card(int l_rank = 0, 
		bool l_isFaceUp = false, 
		std::string l_pathToTextureBackConfig = "config/card_back_texture.ini", 
		std::string l_pathToSpriteBackConfig = "config/card_back_sprite.ini",
		std::string l_pathToTextureFrontConfig = "config/card_front_texture.ini",
		std::string l_pathToSpriteFrontConfig = "config/card_front_sprite.ini");
	Card(Card* copy);

	~Card();
};

