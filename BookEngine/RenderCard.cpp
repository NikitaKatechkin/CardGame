#include "RenderCard.h"



Drawable* RenderCard::getBack()
{
	return m_back;
}

void RenderCard::setBack(Drawable* l_back)
{
	delete m_back;
	m_back = new Drawable(l_back);
}

Drawable* RenderCard::getFront()
{
	return m_front;
}

void RenderCard::setFront(Drawable * l_front)
{
	delete m_front;
	m_front = new Drawable(l_front);
}

void RenderCard::drawBackOn(sf::RenderWindow * l_window)
{
	l_window->draw(m_back->getSprite());
}

void RenderCard::drawFrontOn(sf::RenderWindow * l_window)
{
	l_window->draw(m_front->getSprite());
}

void RenderCard::draw(sf::RenderWindow * l_window, bool l_isFaceUp)
{
	l_isFaceUp ? drawFrontOn(l_window) : drawBackOn(l_window);
}

RenderCard::RenderCard(std::string pathToTextureBackConfig,
	std::string pathToSpriteBackConfig, 
	std::string pathToTextureFrontConfig, 
	std::string pathToSpriteFrontConfig) :
	m_back(new Drawable(pathToTextureBackConfig, pathToSpriteBackConfig)),
	m_front(new Drawable(pathToTextureFrontConfig, pathToSpriteFrontConfig))
{
}

RenderCard::RenderCard(RenderCard * l_copy):
	m_back(l_copy->getBack()),
	m_front(l_copy->getFront())
{
}

RenderCard::~RenderCard()
{
	delete m_back;
	delete m_front;
}
