#include "Deck.h"

void Deck::populate()
{
	/*for (int i = 0; i < m_capacity; i++)
	{
		m_cards.push_back(new Card(rand() % 10));
	}*/

	std::string l_pathToTextureBackConfig = "config/card_back_texture.ini";
	std::string l_pathToSpriteBackConfig = "config/card_back_sprite.ini";
	std::string l_pathToSpriteFrontConfig = "config/card_front_sprite.ini";

	std::string pathToTextureFontConfig = "config/configFront/card_front_texture_";
	std::string format = ".ini";

	for (int i = 1; i < m_capacity + 1; i++)
	{
		std::string fullTexturePathConfig = pathToTextureFontConfig + std::to_string(i) + format;
		//std::cout << fullTexturePathConfig << std::endl;
		m_cards.push_back(new Card((i-1) % 13 + 1, false, l_pathToTextureBackConfig,
			l_pathToSpriteBackConfig, fullTexturePathConfig, l_pathToSpriteFrontConfig));
	}
}

int Rand(int n)
{
	return rand() % n;
}

void Deck::shuffle()
{
	
	std::random_shuffle(m_cards.begin(), m_cards.end(), std::pointer_to_unary_function<int, int>(Rand));
}

void Deck::deal(Hand * l_hand)
{
	if (m_cards.empty())
	{
		populate();
		shuffle();
	}
	l_hand->addCard(m_cards.back());
	m_cards.pop_back();
}

void Deck::print()
{
	if (!m_cards.empty())
	{
		for (auto *i : m_cards)
		{
			std::cout << i->getRank();
		}
		std::cout << std::endl;
	}
}

RenderDeck * Deck::getRenderObject()
{
	return m_renderDeckObject;
}

void Deck::setRenderObject(RenderDeck * l_renderDeckObject)
{
	delete m_renderDeckObject;
	m_renderDeckObject = new RenderDeck(l_renderDeckObject);
}

Deck::Deck(int l_deck_size, sf::Vector2f l_topLeftCoord, sf::Vector2f l_size) :
	Hand(), m_capacity(l_deck_size), m_renderDeckObject(new RenderDeck(l_topLeftCoord, l_size))
{
	populate();
	shuffle();

	//Starting deck canvas size setting
	int visible_cards_on_top = m_cards.size() < 3 ? m_cards.size() : 3;
	/*m_renderDeckObject->getCanvas()->setCanvasSize(sf::Vector2f(new Card()->getRenderObject()->getBack()->getSpriteSize().x + 15 * visible_cards_on_top,
		new Card()->getRenderObject()->getBack()->getSpriteSize().y + 15 * visible_cards_on_top));*/
	m_renderDeckObject->getCanvas()->setCanvasSize(sf::Vector2f(Card().getRenderObject()->getBack()->getSpriteSize().x + 15 * visible_cards_on_top, 
		Card().getRenderObject()->getBack()->getSpriteSize().y + 15 * visible_cards_on_top));
}

Deck::~Deck()
{
	delete m_renderDeckObject;
}
