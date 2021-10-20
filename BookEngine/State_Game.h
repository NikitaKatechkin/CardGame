#pragma once
#include "BaseState.h"
#include "EventManager.h"
#include "Player.h"

class State_Game :
	public BaseState
{
private:
	GeneralPlayer* m_computer;
	Player* m_player;

	//sf::Vector2f mousePositionOnClick;
	Drawable* m_background;

	int m_discard_counter;

	bool m_isOver;
public:
	void OnCreate();
	void OnDestroy();

	void Activate();
	void Deactivate();

	void Update(const sf::Time& l_time);
	void Draw();

	void MainMenu(EventDetails* l_details);
	void Pause(EventDetails* l_details);
	void MouseClick(EventDetails* l_details);

	State_Game(StateManager* l_stateManager);
	~State_Game();
};

