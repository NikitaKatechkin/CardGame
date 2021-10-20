#pragma once
#include "Drawable.h"
#include "RenderObject.h"

class RenderCard : public RenderObject
{
protected:
	Drawable* m_back;
	Drawable* m_front;
public:
	Drawable* getBack();
	void setBack(Drawable* l_back);

	Drawable* getFront();
	void setFront(Drawable* l_front);

	void drawBackOn(sf::RenderWindow* l_window);
	void drawFrontOn(sf::RenderWindow * l_window);
	void draw(sf::RenderWindow* l_window, bool l_isFaceUp);

	RenderCard(std::string pathToTextureBackConfig, std::string pathToSpriteBackConfig, 
		std::string pathToTextureFrontConfig, std::string pathToSpriteFrontConfig);
	RenderCard(RenderCard* l_copy);
	~RenderCard();
};

