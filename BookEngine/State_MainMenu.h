#pragma once
#include "BaseState.h"
#include "EventManager.h"
#include "ButtonRect.h"

class State_MainMenu :
	public BaseState
{
private:
	Text m_text;

	sf::Vector2f m_buttonSize;
	sf::Vector2f m_buttonPos;
	unsigned int m_buttonPadding;

	ButtonRect m_buttons[3];
public:
	void OnCreate();
	void OnDestroy();

	void Activate();
	void Deactivate();

	void Update(const sf::Time& l_time);
	void Draw();

	void MouseClick(EventDetails* l_details);

	State_MainMenu(StateManager* l_stateManager);
	~State_MainMenu();
};

