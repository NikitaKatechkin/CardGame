#include "Player.h"



void Player::sendCard2House(sf::Vector2i l_pressedCoords)
{
	int counter = 0;
	for (auto iter : m_hand->getCards())
	{
		float cardLeftX = iter->getRenderObject()->getBack()->getSpritePosition().x;
		float cardRightX = iter->getRenderObject()->getBack()->getSpritePosition().x + 
			iter->getRenderObject()->getBack()->getSpriteSize().x;

		float cardTopY = iter->getRenderObject()->getBack()->getSpritePosition().y;
		float cardBottomY = iter->getRenderObject()->getBack()->getSpritePosition().y +
			iter->getRenderObject()->getBack()->getSpriteSize().y;
		if (cardLeftX < l_pressedCoords.x && cardRightX > l_pressedCoords.x
			&& cardTopY < l_pressedCoords.y && cardBottomY > l_pressedCoords.y)
		{
			m_house->addCard(m_hand->getCard(counter));
		}
		counter++;
	}
}

void Player::takeDeckCard2Hand()
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
		Card* tmp = m_hand->getCard(m_hand->getNumOfCardsInHand() - 1);
		tmp->Flip();
		m_hand->addCard(tmp);
	}
}

void Player::clearHouse()
{
	while (!m_house->isEmpty())
	{
		Card* tmp = m_house->getCard(m_house->getNumOfCardsInHand() - 1);
		tmp->Flip();
		m_discard->addCard(tmp);
	}
}

Player::Player(int l_hand_size, int l_house_size, int l_deck_size, int l_health):
	GeneralPlayer(l_hand_size, l_house_size, l_deck_size, l_health)
{
}


Player::~Player()
{
}
