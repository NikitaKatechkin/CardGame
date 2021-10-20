#pragma once
#include <SFML/Graphics.hpp>

class StateManager;

class BaseState
{
	friend class StateManager;
protected:
	StateManager* m_stateManager;
	bool m_transparent;
	bool m_transcendent;
public:
	virtual void OnCreate() = 0;
	virtual void OnDestroy() = 0;

	virtual void Activate() = 0;
	virtual void Deactivate() = 0;

	virtual void Update(const sf::Time& l_time) = 0;
	virtual void Draw() = 0;

	bool IsTransparent() const;
	void SetTransparent(bool l_transparancy);

	void SetTranscendent(bool l_transcendence);
	bool IsTranscendent() const;

	StateManager* GetStateManager();

	BaseState(StateManager* l_stateManager);
	virtual ~BaseState();
};

