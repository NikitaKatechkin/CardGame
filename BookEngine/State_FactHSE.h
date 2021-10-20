#pragma once
#include "BaseState.h"
#include "EventManager.h"
#include "ButtonRect.h"

class State_FactHSE :
	public BaseState
{
private:
	ButtonRect test;

	float m_timePassed;
public:
	void OnCreate();
	void OnDestroy();

	void Activate();
	void Deactivate();

	void Update(const sf::Time& l_time);
	void Draw();

	State_FactHSE(StateManager* l_stateManager);
	~State_FactHSE();
};

