#include "State_Paused.h"
#include "StateManager.h"


State_Paused::State_Paused(StateManager* l_stateManager):
	BaseState(l_stateManager)
{
}


State_Paused::~State_Paused()
{
}

void State_Paused::OnCreate()
{
	SetTransparent(true);

	sf::Font* font = new sf::Font;
	font->loadFromFile("fonts/arial.ttf");
	test.GetText()->setFont(*font);
	test.GetText()->setString(sf::String("PAUSED"));
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

	EventManager* eventManager = m_stateManager->
		GetContext()->m_eventManager;
	eventManager->AddCallback(StateType::Paused, "Key_P",
		&State_Paused::Unpause, this);
}

void State_Paused::OnDestroy()
{
	EventManager* eventManager = m_stateManager->
		GetContext()->m_eventManager;
	eventManager->RemoveCallback(StateType::Paused, "Key_P");
}

void State_Paused::Activate()
{
}

void State_Paused::Deactivate()
{
}

void State_Paused::Update(const sf::Time & l_time)
{
}

void State_Paused::Draw()
{
	sf::RenderWindow* window = m_stateManager->
		GetContext()->m_window->GetRenderWindow();
	window->draw(*test.GetRectShape());
	window->draw(*test.GetText());
}

void State_Paused::Unpause(EventDetails * l_details)
{
	m_stateManager->SwitchTo(StateType::Game);
}
