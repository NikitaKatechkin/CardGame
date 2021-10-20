#pragma once
#include "Window.h"
#include "StateManager.h"

class Game
{
private:
	Window m_window;

	sf::Clock m_clock;
	sf::Time m_elapsed;

	StateManager m_stateManager;
	SharedContext m_context;
public:
	void HandleInput();
	
	void Update();
	void LateUpdate();

	void Render();

	Window* GetWindow();

	sf::Time GetElapsed();
	void RestartClock();

	Game();
	~Game();
};

