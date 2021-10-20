#include "Game.h"



void Game::HandleInput()
{
}

void Game::Update()
{
	m_window.Update();
	m_stateManager.Update(&m_elapsed);
}

void Game::LateUpdate()
{
	m_stateManager.ProcessRequests();
	RestartClock();
}

void Game::Render()
{
	m_window.BeginDraw();

	m_stateManager.Draw();

	m_window.EndDraw();
}

Window * Game::GetWindow()
{
	return &m_window;
}

sf::Time Game::GetElapsed()
{
	return m_elapsed;
}

void Game::RestartClock()
{
	m_elapsed = m_clock.restart();
}

Game::Game():
	m_window("GameHSEEngine", sf::Vector2u(1500, 1000)),
	m_stateManager(&m_context)
{
	RestartClock();
	m_context.m_window = &m_window;
	m_context.m_eventManager = m_window.GetEventManager();
	m_stateManager.SwitchTo(StateType::Intro);
}


Game::~Game()
{
}
