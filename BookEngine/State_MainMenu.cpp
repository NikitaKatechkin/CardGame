#include "State_MainMenu.h"
#include "StateManager.h"


void State_MainMenu::OnCreate()
{
	m_text.SetupFont("fonts/arial.ttf");
	m_text.SetString("MAIN MENU:");
	m_text.SetCharacterSize(36);
	sf::FloatRect testRect = m_text.GetLocalBounds();
	m_text.SetTextOrigin(sf::Vector2f(testRect.width / 2.0f, testRect.height / 2.0f));
	sf::Vector2u windowSize = m_stateManager->GetContext()->m_window->GetWindowSize();
	m_text.SetPosition(sf::Vector2f(float(windowSize.x) / 2.f, float(windowSize.y) / 4.f));

	m_buttonSize = sf::Vector2f((windowSize.x / 800.0f * 300.0f), (windowSize.y / 400 * 32.0f));
	m_buttonPos = sf::Vector2f(float(windowSize.x) / 2.f, float(windowSize.y) / 2.f);
	m_buttonPadding = 8; 
	std::string str[3] = {"PLAY", "CREDITS", "EXIT"};
	/*str[0] = "PLAY";
	str[1] = "CREDITS";
	str[2] = "EXIT";*/
	for (int i = 0; i < 3; ++i) {
		sf::Vector2f buttonPosition(m_buttonPos.x, m_buttonPos.y +
			(i * (m_buttonSize.y + m_buttonPadding)));

		m_buttons[i].SetSize(m_buttonSize);
		m_buttons[i].SetFillColor(sf::Color::Red);
		m_buttons[i].SetRectOrigin(sf::Vector2f(m_buttonSize.x / 2.0f,
			m_buttonSize.y / 2.0f));
		m_buttons[i].SetPosition(buttonPosition);
		m_buttons[i].GetText()->setFont(*m_text.GetFont());
		m_buttons[i].GetText()->setString(sf::String(str[i]));
		m_buttons[i].GetText()->setCharacterSize(24);
		sf::FloatRect rect = m_buttons[i].GetText()->getLocalBounds();
		m_buttons[i].GetText()->setOrigin(sf::Vector2f(rect.width / 2.0f,
			rect.top + rect.height / 2.0f));
		m_buttons[i].GetText()->setPosition(buttonPosition);
	}

	EventManager* eventManager = m_stateManager->
		GetContext()->m_eventManager;
	eventManager->AddCallback(StateType::MainMenu, "Mouse_Left",
		&State_MainMenu::MouseClick, this);
}

void State_MainMenu::OnDestroy()
{
	EventManager* eventManager = m_stateManager->GetContext()->m_eventManager;
	eventManager->RemoveCallback(StateType::MainMenu, "Mouse_Left");
}

void State_MainMenu::Activate()
{
	if (m_stateManager->HasState(StateType::Game)
		&& m_buttons[0].GetText()->getString() == "PLAY")
	{
		m_buttons[0].GetText()->setString(sf::String("RESUME"));
		sf::FloatRect rect = m_buttons[0].GetText()->getLocalBounds();
		m_buttons[0].GetText()->setOrigin(rect.left + rect.width / 2.0f,
			rect.top + rect.height / 2.0f);
	}
}

void State_MainMenu::Deactivate()
{
}

void State_MainMenu::Update(const sf::Time & l_time)
{
}

void State_MainMenu::Draw()
{
	sf::RenderWindow* window = m_stateManager->GetContext()->
		m_window->GetRenderWindow();
	window->draw(*m_text.getSFMLText());
	for (int i = 0; i < 3; ++i) {
		window->draw(*m_buttons[i].GetRectShape());
		window->draw(*m_buttons[i].GetText());
	}
}

void State_MainMenu::MouseClick(EventDetails * l_details)
{
	sf::Vector2i mousePos = l_details->m_mouse;
	float halfX = m_buttonSize.x / 2.0f;
	float halfY = m_buttonSize.y / 2.0f;
	for (int i = 0; i < 3; ++i) {
		if (mousePos.x >= m_buttons[i].GetRectShape()->getPosition().x - halfX &&
			mousePos.x <= m_buttons[i].GetRectShape()->getPosition().x + halfX &&
			mousePos.y >= m_buttons[i].GetRectShape()->getPosition().y - halfY &&
			mousePos.y <= m_buttons[i].GetRectShape()->getPosition().y + halfY)
		{
			if (i == 0) {
				m_stateManager->SwitchTo(StateType::Game);
			}
			else if (i == 1) {
				m_stateManager->SwitchTo(StateType::Credits);
			}
			else if (i == 2) {
				m_stateManager->GetContext()->m_window->Close();
			}
		}
	}
}

State_MainMenu::State_MainMenu(StateManager* l_stateManager):
	BaseState(l_stateManager)
{
}


State_MainMenu::~State_MainMenu()
{
}
