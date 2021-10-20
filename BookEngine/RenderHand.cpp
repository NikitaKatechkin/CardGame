#include "RenderHand.h"


Drawable * RenderHand::getBackground()
{
	return m_background;
}

void RenderHand::setBackground(Drawable * l_background)
{
	delete m_background;
	m_background = new Drawable(l_background);
}

void RenderHand::draw_background(sf::RenderWindow * l_window)
{
	m_background->setSpritePosition(m_canvas->getTopLeftCoords().x, 
		m_canvas->getTopLeftCoords().y);

	l_window->draw(m_background->getSprite());
}

void RenderHand::draw_cards(sf::RenderWindow* l_window, std::vector<Card*> l_cards)
{
	if (!l_cards.empty())
	{
		float padding_x = (m_canvas->getCanvasSize().x - l_cards.size() *
			(l_cards[0]->getRenderObject()->getBack()->getSpriteSize().x)) / 2.f;
		float padding_y = (m_canvas->getCanvasSize().y - l_cards[0]->getRenderObject()->getBack()->getSpriteSize().y) / 2.f;

		for (int i = 0; i < int(l_cards.size()); i++)
		{
			l_cards[i]->getRenderObject()->getBack()->setSpritePosition(i * (l_cards[i]->getRenderObject()->getBack()->getSpriteSize().x) + padding_x + m_canvas->getTopLeftCoords().x,
				padding_y + m_canvas->getTopLeftCoords().y);
			l_cards[i]->getRenderObject()->getFront()->setSpritePosition(l_cards[i]->getRenderObject()->getBack()->getSpritePosition().x,
				l_cards[i]->getRenderObject()->getBack()->getSpritePosition().y);
			l_cards[i]->getRenderObject()->draw(l_window, l_cards[i]->isFaceUp());
		}
	}	
}

void RenderHand::draw(sf::RenderWindow * l_window, std::vector<Card*> l_cards)
{
	draw_background(l_window);
	draw_cards(l_window, l_cards);
}

RenderHand::RenderHand(std::string pathToTextureBackgroundConfig,
	std::string pathToSpriteBackgroundConfig) :
	m_background(new Drawable(pathToTextureBackgroundConfig,
		pathToSpriteBackgroundConfig))
{
	m_canvas = new Canvas(m_background->getSpriteSize(), 
		m_background->getSpritePosition());
}

RenderHand::RenderHand(RenderHand * l_copy) :
	m_background(l_copy->getBackground()),
	RenderObject(l_copy)
{
}

RenderHand::~RenderHand()
{
	delete m_background;
}
