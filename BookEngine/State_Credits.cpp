#include "State_Credits.h"
#include "StateManager.h"



void State_Credits::OnCreate()
{
	sf::Font* font = new sf::Font;
	font->loadFromFile("fonts/arial.ttf");
	test.GetText()->setFont(*font);
	test.GetText()->setString(sf::String("DONE BY KATECHKIN NIKITA && KHANBEKOVA ULYANA"));
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
	test.SetFillColor(sf::Color::Black);

	EventManager* eventManager = m_stateManager->
		GetContext()->m_eventManager;
	eventManager->AddCallback(StateType::Credits, "Key_Escape",
		&State_Credits::MainMenu, this);
}

void State_Credits::OnDestroy()
{
	EventManager* eventManager = m_stateManager->
		GetContext()->m_eventManager;
	eventManager->RemoveCallback(StateType::Credits, "Key_Escape");
}

void State_Credits::Activate()
{
}

void State_Credits::Deactivate()
{
}

void State_Credits::Update(const sf::Time & l_time)
{
}

void State_Credits::Draw()
{
	sf::RenderWindow* window = m_stateManager->
		GetContext()->m_window->GetRenderWindow();
	window->draw(*test.GetRectShape());
	window->draw(*test.GetText());
}

void State_Credits::MainMenu(EventDetails * l_details)
{
	m_stateManager->SwitchTo(StateType::MainMenu);
}

State_Credits::State_Credits(StateManager* l_stateManager):
	BaseState(l_stateManager)
{
}


State_Credits::~State_Credits()
{
}
