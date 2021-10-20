#include "Text.h"



void Text::SetString(std::string text)
{
	m_text.setString(sf::String(text));
}

sf::String Text::GetString()
{
	return m_text.getString();
}

void Text::SetupFont(std::string pathToFont)
{
	m_font.loadFromFile(pathToFont);
	m_text.setFont(m_font);
}

void Text::SetupText(sf::Vector2f l_origin, sf::Font l_font, int l_characterSize)
{
	SetTextOrigin(l_origin);
	SetFont(l_font);
	SetCharacterSize(l_characterSize);
}

sf::Font* Text::GetFont()
{
	return &m_font;
}

sf::FloatRect Text::GetLocalBounds()
{
	return m_text.getLocalBounds();
}

sf::Text * Text::getSFMLText()
{
	return &m_text;
}

sf::Vector2f Text::GetPosition()
{
	return m_text.getPosition();
}

void Text::SetPosition(sf::Vector2f l_position)
{
	m_text.setPosition(l_position);
}

Text::Text()
{

}

Text::Text(std::string pathToFont, sf::Vector2f l_origin, sf::Font l_font, int l_characterSize)
{
	SetupFont(pathToFont);
	SetupText(l_origin, l_font, l_characterSize);
}

Text::Text(Text * l_copy)
{
	SetFont(*l_copy->GetFont());
	m_font = *l_copy->GetFont();
	m_text = *l_copy->getSFMLText();
}


Text::~Text()
{
}

void Text::SetTextOrigin(sf::Vector2f l_origin)
{
	sf::FloatRect currentTextRect = GetLocalBounds();
	m_text.setOrigin(currentTextRect.left + l_origin.x, 
		currentTextRect.top + l_origin.y);
}

void Text::SetFont(sf::Font l_font)
{
	m_text.setFont(l_font);
}

void Text::SetCharacterSize(int l_characterSize)
{
	m_text.setCharacterSize(l_characterSize);
}
