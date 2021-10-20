#include "State_Game.h"
#include "StateManager.h"


State_Game::State_Game(StateManager* l_stateManager):
	BaseState(l_stateManager)
{
}


State_Game::~State_Game()
{
}

void State_Game::OnCreate()
{
	m_discard_counter = 0;

	m_computer = new GeneralPlayer();
	m_player = new Player();
	m_background = new Drawable("config/game_background_texture.ini", "config/game_background_sprite.ini");

	EventManager* eventManager = m_stateManager->
		GetContext()->m_eventManager;
	eventManager->AddCallback(StateType::Game, "Mouse_Left",
		&State_Game::MouseClick, this);
	eventManager->AddCallback(StateType::Game, "Key_Escape",
		&State_Game::MainMenu, this);
	eventManager->AddCallback(StateType::Game, "Key_P",
		&State_Game::Pause, this);
}

void State_Game::OnDestroy()
{
	delete m_computer;
	delete m_player;
	delete m_background;

	EventManager* eventManager = m_stateManager->GetContext()->m_eventManager;
	eventManager->RemoveCallback(StateType::Game, "Mouse_Left");
	eventManager->RemoveCallback(StateType::Game, "Key_Escape");
	eventManager->RemoveCallback(StateType::Game, "Key_P");
}

void State_Game::Activate()
{
}

void State_Game::Deactivate()
{
}

void State_Game::Update(const sf::Time & l_time)
{
	if (m_player->isEmptyHand())
	{
		while (!m_player->isFullHand())
		{
			m_player->takeDeckCard2Hand();
		}
	}
	if (m_computer->isEmptyHand())
	{
		while (!m_computer->isFullHand())
		{
			m_computer->takeDeckCard2Hand();
		}
	}

	if (!m_computer->isFullHouse() && !m_computer->isEmptyHand())
	{
		m_computer->sendCard2House();
	}
	/*if (!m_player->isFullHouse() && !m_player->isEmptyHand())
	{
		m_player->sendCard2House(m_player->getClickedPosition());
	}*/

	if (m_computer->isFullHouse() && m_player->isFullHouse())
	{
		if (m_computer->getHouse()->getTotal() > m_player->getHouse()->getTotal())
		{
			m_player->setHealth(m_player->getHealth() - (m_computer->getHouse()->getTotal() - m_player->getHouse()->getTotal()));
		}
		else
		{
			m_computer->setHealth(m_computer->getHealth() - (m_player->getHouse()->getTotal() - m_computer->getHouse()->getTotal()));
		}

		m_player->clearHouse();
		m_computer->clearHouse();

		m_discard_counter++;
		if (m_discard_counter > 2)
		{
			m_stateManager->SwitchTo(StateType::FactHSE);
			m_discard_counter = 0;
		}
		
	}

	if (m_computer->getHealth() <= 0 || m_player->getHealth() <= 0)
	{
		m_isOver = true;
		m_stateManager->GetContext()->m_window->Close();
		//m_window->close();
	}
}

void State_Game::Draw()
{
	sf::RenderWindow* window = m_stateManager->GetContext()->
		m_window->GetRenderWindow();

	m_background->draw(window);
	
	m_computer->getRenderObject()->draw(m_computer->getHand(), m_computer->getDeck(), m_computer->getDiscard(), m_computer->getHouse(), window, false);
	m_player->getRenderObject()->draw(m_player->getHand(), m_player->getDeck(), m_player->getDiscard(), m_player->getHouse(), window, true);
}

void State_Game::MainMenu(EventDetails * l_details)
{
	m_stateManager->SwitchTo(StateType::MainMenu);
}

void State_Game::Pause(EventDetails * l_details)
{
	m_stateManager->SwitchTo(StateType::Paused);
}

void State_Game::MouseClick(EventDetails * l_details)
{
	sf::Vector2i mousePos = l_details->m_mouse;
	if (!m_player->isFullHouse() && !m_player->isEmptyHand())
	{
		m_player->sendCard2House(mousePos);
	}
}
