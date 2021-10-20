#pragma once
#include "Card.h"
#include "Canvas.h"

class RenderHand : public RenderObject
{
protected:
	Drawable* m_background;
public:
	Drawable* getBackground();
	void setBackground(Drawable* l_background);

	void draw_background(sf::RenderWindow* l_window);
	void draw_cards(sf::RenderWindow* l_window, std::vector<Card*> l_cards);
	void draw(sf::RenderWindow* l_window, std::vector<Card*> l_cards);

	RenderHand(std::string pathToTextureBackgroundConfig, 
		std::string pathToSpriteBackgroundConfig);
	RenderHand(RenderHand* l_copy);
	~RenderHand();
};

