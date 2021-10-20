#include "GeneralPlayer.h"


bool GeneralPlayer::isFullHand()
{
	return m_hand->isFull();
}

bool GeneralPlayer::isEmptyHand()
{
	return m_hand->isEmpty();
}

bool GeneralPlayer::isFullHouse()
{
	return m_house->isFull();
}

void GeneralPlayer::takeDeckCard2Hand()
{
	if (!isFullHand())
	{
		if (m_deck->isEmpty())
		{
			while (!m_discard->isEmpty())
			{
				m_deck->addCard(m_discard->getCard(m_discard->getNumOfCardsInHand() - 1));
			}
			m_deck->populate();
			
		}
		m_deck->deal(m_hand);
	}
}

void GeneralPlayer::sendCard2House()
{
	if (!isFullHouse())
	{
		srand(time(0));
		Card* toHouse = new Card(m_hand->getCard(rand() % m_hand->getNumOfCardsInHand()));
		toHouse->Flip();
		m_house->addCard(toHouse);
		//m_house->addCard(m_hand->getCard(m_hand->getNumOfCardsInHand() - 1));
	}
}

int GeneralPlayer::playedCardTotal()
{
	return m_house->getTotal();
}

int GeneralPlayer::getHealth()
{
	return m_health;
}

void GeneralPlayer::setHealth(int l_health)
{
	m_health = l_health;
}

void GeneralPlayer::clearHouse()
{
	while (!m_house->isEmpty())
	{
		Card* tmp = m_house->getCard(m_house->getNumOfCardsInHand() - 1);
		tmp->Flip();
		m_discard->addCard(tmp);
	}
}

Hand * GeneralPlayer::getHand()
{
	return m_hand;
}

Deck * GeneralPlayer::getDeck()
{
	return m_deck;
}

Hand * GeneralPlayer::getHouse()
{
	return m_house;
}

Deck * GeneralPlayer::getDiscard()
{
	return m_discard;
}

RenderGeneralPlayer * GeneralPlayer::getRenderObject()
{
	return m_renderObject;
}

void GeneralPlayer::setRenderObject(RenderGeneralPlayer * l_renderDeckObject)
{
	delete m_renderObject;
	m_renderObject = new RenderGeneralPlayer(l_renderDeckObject);
}

/*void GeneralPlayer::draw(sf::RenderWindow * l_window, bool l_bottom)
{
	/*l_bottom ? setTopLeftCoords(sf::Vector2f(0.f, l_window->getSize().y / 2.f)) :
		setTopLeftCoords(sf::Vector2f(0.f, 0.f));
	setCanvasSize(sf::Vector2f(l_window->getSize().x, l_window->getSize().y / 2.f));

	float hand_padding_left = (getCanvasSize().x - m_hand->getSpriteSize().x) / 2.f;
	float hand_padding_top = l_bottom ? 
		getCanvasSize().y - m_hand->getSpriteSize().y : 0;
	m_hand->setSpritePosition(hand_padding_left + getTopLeftCoords().x, hand_padding_top + getTopLeftCoords().y);
	m_hand->draw(l_window);

	float deck_padding_top = l_bottom ?
		hand_padding_top + getTopLeftCoords().y - Card().getSpriteSize().y :
		hand_padding_top + getTopLeftCoords().y + Card().getSpriteSize().y;
	m_deck->setTopLeftCoords(sf::Vector2f(getTopLeftCoords().x, deck_padding_top));
	m_deck->draw(l_window);
}*/

GeneralPlayer::GeneralPlayer(int l_hand_size, int l_house_size, int l_deck_size, int l_health) :
	m_health(l_health), m_renderObject(new RenderGeneralPlayer())
{
	m_hand = new Hand(l_hand_size);
	m_house = new Hand(l_house_size);
	m_deck = new Deck(l_deck_size);
	m_discard = new Deck(l_deck_size);
	m_discard->clear();
}

GeneralPlayer::~GeneralPlayer()
{
	delete m_hand;
	delete m_house;
	delete m_deck;
	delete m_renderObject;
	delete m_discard;
}
