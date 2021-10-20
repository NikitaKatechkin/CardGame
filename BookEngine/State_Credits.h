#pragma once
#include "BaseState.h"
#include "EventManager.h"
#include "Text.h"
#include "ButtonRect.h"

class State_Credits :
	public BaseState
{
private:
	ButtonRect test;
public:
	void OnCreate();
	void OnDestroy();

	void Activate();
	void Deactivate();

	void Update(const sf::Time& l_time);
	void Draw();

	void MainMenu(EventDetails* l_details);

	State_Credits(StateManager* l_stateManager);
	~State_Credits();
};

