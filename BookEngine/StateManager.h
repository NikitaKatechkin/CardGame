#pragma once
#include "BaseState.h"
#include "Window.h"
#include "State_Intro.h"
#include "State_MainMenu.h"
#include "State_Game.h"
#include "State_Paused.h"
#include "State_Credits.h"
#include "State_FactHSE.h"

enum class StateType 
{
	Intro = 1, MainMenu, Game, Paused, GameOver, Credits, FactHSE
};

struct SharedContext
{
	SharedContext() :
		m_window(nullptr), m_eventManager(nullptr) {}
	Window* m_window;
	EventManager* m_eventManager;
};

using StateContainer = std::vector<std::pair<StateType, BaseState*>>;
using TypeContainer = std::vector<StateType>;
using StateFactory = std::unordered_map<StateType, std::function<BaseState* (void)>>;


class StateManager
{
private:
	void CreateState(StateType l_type);
	void RemoveState(StateType l_type);

	template <class T>
	void RegisterState(StateType l_type)
	{
		m_stateFactory[l_type] = [this]() -> BaseState*
		{
			return new T(this);
		};
	}

	SharedContext* m_shared;
	StateContainer m_states;
	TypeContainer m_toRemove;
	StateFactory m_stateFactory;
public:
	void Update(sf::Time* l_time);
	void Draw();

	void ProcessRequests();

	SharedContext* GetContext();
	bool HasState(StateType l_type);

	void SwitchTo(StateType l_type);
	void Remove(StateType l_type);

	StateManager(SharedContext* l_shared);
	~StateManager();
};

