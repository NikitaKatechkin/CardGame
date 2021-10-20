#include "State_FactHSE.h"
#include "StateManager.h"


void State_FactHSE::OnCreate()
{
	SetTransparent(true);
	//SetTranscendent(true);

	m_timePassed = 0.f;

	sf::Font* font = new sf::Font;
	font->loadFromFile("fonts/arial.ttf");
	test.GetText()->setFont(*font);
	test.GetText()->setString(sf::String("EXTREMLY INTERESTING FACT ABOUT HSE"));
	test.GetText()->setCharacterSize(28);
	test.GetText()->setStyle(sf::Text::Bold);
	sf::Vector2u windowSize = m_stateManager->
		GetContext()->m_window->GetRenderWindow()->getSize();
	sf::FloatRect textRect = test.GetText()->getLocalBounds();
	test.GetText()->setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	test.GetText()->setPosition(windowSize.x / 2.0f, windowSize.y / 2.0f);

	test.SetSize(sf::Vector2f(windowSize));
	test.SetPosition(sf::Vector2f(0, 0));
	test.SetFillColor(sf::Color(0, 0, 0, 150));
}

void State_FactHSE::OnDestroy()
{
}

void State_FactHSE::Activate()
{
	m_timePassed = 0.f;
}

void State_FactHSE::Deactivate()
{
	m_timePassed = 0.f;
}

void State_FactHSE::Update(const sf::Time & l_time)
{
	/*if (m_timePassed < 15.0f)
	{
		m_timePassed += l_time.asSeconds();
		if (m_timePassed < 5.0f)
		{
			test.SetPosition(sf::Vector2f(test.GetPosition().x,
				test.GetPosition().y + (72 * l_time.asSeconds())));
		}
	}*/
	m_timePassed += l_time.asSeconds();
	if (m_timePassed > 5.0f)
	{
		m_stateManager->SwitchTo(StateType::Game);
	}
}

void State_FactHSE::Draw()
{
	sf::RenderWindow* window = m_stateManager->
		GetContext()->m_window->GetRenderWindow();
	window->draw(*test.GetRectShape());
	window->draw(*test.GetText());
}

State_FactHSE::State_FactHSE(StateManager* l_stateManager):
	BaseState(l_stateManager)
{
}


State_FactHSE::~State_FactHSE()
{
}
