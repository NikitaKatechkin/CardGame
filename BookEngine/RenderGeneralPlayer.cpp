#include "RenderGeneralPlayer.h"



void RenderGeneralPlayer::draw(Hand* l_hand, Deck* l_deck, Deck* l_discard, Hand* l_house, sf::RenderWindow * l_window, bool l_bottom)
{
	l_bottom ? m_canvas->setTopLeftCoords(sf::Vector2f(0.f, l_window->getSize().y / 2.f)) :
		m_canvas->setTopLeftCoords(sf::Vector2f(0.f, 0.f));
	m_canvas->setCanvasSize(sf::Vector2f(float(l_window->getSize().x), float(l_window->getSize().y) / 2.f));

	float hand_padding_left = (m_canvas->getCanvasSize().x - l_hand->getRenderObject()->getCanvas()->getCanvasSize().x) / 2.f;
	float hand_padding_top = l_bottom ?
		m_canvas->getCanvasSize().y - l_hand->getRenderObject()->getCanvas()->getCanvasSize().y : 0;
	l_hand->getRenderObject()->getCanvas()->setTopLeftCoords(sf::Vector2f(hand_padding_left + m_canvas->getTopLeftCoords().x, hand_padding_top + m_canvas->getTopLeftCoords().y));
	l_hand->getRenderObject()->draw(l_window, l_hand->getCards());


	float house_padding_top = l_bottom ?
		hand_padding_top - l_house->getRenderObject()->getCanvas()->getCanvasSize().y : l_hand->getRenderObject()->getCanvas()->getCanvasSize().y;
	l_house->getRenderObject()->getCanvas()->setTopLeftCoords(sf::Vector2f(hand_padding_left + m_canvas->getTopLeftCoords().x, house_padding_top + m_canvas->getTopLeftCoords().y));
	l_house->getRenderObject()->draw(l_window, l_house->getCards());

	float deck_padding_top = l_bottom ?
		hand_padding_top + m_canvas->getTopLeftCoords().y - Card().getRenderObject()->getBack()->getSpriteSize().y :
		hand_padding_top + m_canvas->getTopLeftCoords().y + Card().getRenderObject()->getBack()->getSpriteSize().y;
	l_deck->getRenderObject()->getCanvas()->setTopLeftCoords(sf::Vector2f(m_canvas->getTopLeftCoords().x, deck_padding_top));
	l_deck->getRenderObject()->draw(l_window, l_deck->getCards());

	l_discard->getRenderObject()->getCanvas()->setTopLeftCoords(
		sf::Vector2f(m_canvas->getTopLeftCoords().x + m_canvas->getCanvasSize().x - l_discard->getRenderObject()->getCanvas()->getCanvasSize().x, deck_padding_top));
	l_discard->getRenderObject()->draw(l_window, l_discard->getCards());
}


RenderGeneralPlayer::RenderGeneralPlayer(sf::Vector2f l_topLeftCoord, sf::Vector2f l_size) :
	RenderObject(l_topLeftCoord, l_topLeftCoord)
{
}

RenderGeneralPlayer::RenderGeneralPlayer(RenderGeneralPlayer * l_copy) :
	RenderObject(l_copy)
{
}


RenderGeneralPlayer::~RenderGeneralPlayer()
{
}
