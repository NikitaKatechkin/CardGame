#include "Hand.h"



void Hand::addCard(Card * l_card)
{
	m_cards.push_back(l_card);
}

void Hand::clear()
{
	/*for (auto iter = m_cards.begin(); iter != m_cards.end(); ++iter)
	{
		delete *iter;
		*iter = NULL;
	}*/
	m_cards.erase(m_cards.begin(), m_cards.end());
	//std::cout << m_cards.size() << std::endl;
}

void Hand::print()
{
	if (!m_cards.empty())
	{
		for (auto *i : m_cards)
		{
			std::cout << i->getRank() << std::endl;
		}
	}
}

Card* Hand::getCard(int l_cardIndex)
{
	Card* result = m_cards[l_cardIndex];
	m_cards.erase(m_cards.begin() + l_cardIndex);
	return result;
}

int Hand::getTotal()
{
	int total = 0;
	for (std::vector<Card*>::iterator iter = m_cards.begin(); iter != m_cards.end(); ++iter)
		total += (*iter)->getRank();
	
	return total;
}

bool Hand::isFull()
{
	return int(m_cards.size()) >= m_max_size;
}

bool Hand::isEmpty()
{
	return m_cards.empty();
}

std::vector<Card*> Hand::getCards()
{
	return std::vector<Card*>(m_cards);
}

int Hand::getNumOfCardsInHand()
{
	return m_cards.size();
}

RenderHand * Hand::getRenderObject()
{
	return m_renderObject;
}

void Hand::setRenderObject(RenderHand * l_renderObject)
{
	delete m_renderObject;
	m_renderObject = new RenderHand(l_renderObject);
}

Hand::Hand(int l_max_size, std::string pathToTextureConfig, std::string pathToSpriteConfig):
	m_max_size(l_max_size),
	m_renderObject(new RenderHand(pathToTextureConfig, pathToSpriteConfig))
{
}


Hand::~Hand()
{
	clear();
	delete m_renderObject;
}
