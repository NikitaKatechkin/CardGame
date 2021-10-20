#include "Card.h"

void Card::Flip()
{
	m_isFaceUp = !m_isFaceUp;
}

bool Card::isFaceUp()
{
	return m_isFaceUp;
}

int Card::getRank()
{
	return m_rank;
}

void Card::setRank(int l_rank)
{
	m_rank = l_rank;
}

Card* Card::operator=(Card * l_left)
{
	m_rank = l_left->getRank();
	m_isFaceUp = l_left->isFaceUp();

	return this;
}

RenderCard * Card::getRenderObject()
{
	return m_renderObject;
}

void Card::setRenderObject(RenderCard * l_renderObject)
{
	delete m_renderObject;
	m_renderObject = new RenderCard(l_renderObject);
}

Card::Card(int l_rank, bool l_isFaceUp, 
	std::string l_pathToTextureBackConfig, 
	std::string l_pathToSpriteBackConfig, 
	std::string l_pathToTextureFrontConfig,
	std::string l_pathToSpriteFrontConfig) :
	m_rank(l_rank), m_isFaceUp(l_isFaceUp), 
	m_renderObject(new RenderCard(l_pathToTextureBackConfig, l_pathToSpriteBackConfig,
		l_pathToTextureFrontConfig, l_pathToSpriteFrontConfig))
{
}

Card::Card(Card * l_copy) :
	m_rank(l_copy->getRank()), 
	m_isFaceUp(l_copy->isFaceUp()),
	m_renderObject(l_copy->getRenderObject())
{
}

Card::~Card()
{
	delete m_renderObject;
}
