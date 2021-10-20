#include "RenderDeck.h"



void RenderDeck::draw(sf::RenderWindow * l_window, std::vector<Card*> l_cards)
{
	if (!l_cards.empty())
	{
		int visible_cards_on_top = l_cards.size() < 3 ? l_cards.size() : 3;
		m_canvas->setCanvasSize(sf::Vector2f(l_cards[0]->getRenderObject()->getBack()->getSpriteSize().x + 15 * visible_cards_on_top,
			l_cards[0]->getRenderObject()->getBack()->getSpriteSize().y + 15 * visible_cards_on_top));
		m_canvas->setCanvasSize(sf::Vector2f(l_cards[0]->getRenderObject()->getFront()->getSpriteSize().x + 15 * visible_cards_on_top,
			l_cards[0]->getRenderObject()->getFront()->getSpriteSize().y + 15 * visible_cards_on_top));

		for (int i = 0; i < visible_cards_on_top; i++)
		{
			l_cards[l_cards.size() - 1 - i]->getRenderObject()->getBack()->setSpritePosition(m_canvas->getTopLeftCoords().x + i * 15,
				(visible_cards_on_top - i) * 15 + m_canvas->getTopLeftCoords().y);
			l_cards[l_cards.size() - 1 - i]->getRenderObject()->getFront()->setSpritePosition(m_canvas->getTopLeftCoords().x + i * 15,
				(visible_cards_on_top - i) * 15 + m_canvas->getTopLeftCoords().y);
			l_cards[l_cards.size() - 1 - i]->getRenderObject()->draw(l_window, l_cards[l_cards.size() - 1 - i]->isFaceUp());
		}
	}
}

RenderDeck::RenderDeck(sf::Vector2f l_topLeftCoord, sf::Vector2f l_size):
	RenderObject(l_topLeftCoord, l_size)
{
}

RenderDeck::RenderDeck(RenderDeck * l_copy):
	RenderObject(l_copy)
{
}


RenderDeck::~RenderDeck()
{
	delete m_canvas;
}
