#pragma once
#include <SFML/Graphics.hpp>

class Text
{
private:
	sf::Text m_text;
	sf::Font m_font;
public:
	void SetTextOrigin(sf::Vector2f l_origin);
	void SetFont(sf::Font l_font);
	void SetCharacterSize(int l_characterSize);

	void SetString(std::string text);
	sf::String GetString();

	void SetupFont(std::string pathToFont);
	void SetupText(sf::Vector2f l_origin, sf::Font l_font, int l_characterSize);

	sf::Font* GetFont();

	sf::FloatRect GetLocalBounds();

	sf::Text* getSFMLText();

	sf::Vector2f GetPosition();
	void SetPosition(sf::Vector2f l_position);

	Text();
	Text(std::string pathToFont, sf::Vector2f l_origin, sf::Font l_font, int l_characterSize);
	Text(Text* l_copy);
	~Text();
};

