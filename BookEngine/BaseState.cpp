#include "BaseState.h"



bool BaseState::IsTransparent() const
{
	return m_transparent;
}

void BaseState::SetTransparent(bool l_transparancy)
{
	m_transparent = l_transparancy;
}

void BaseState::SetTranscendent(bool l_transcendence)
{
	m_transcendent = l_transcendence;
}

bool BaseState::IsTranscendent() const
{
	return m_transcendent;
}

StateManager * BaseState::GetStateManager()
{
	return m_stateManager;
}

BaseState::BaseState(StateManager* l_stateManager) :
	m_stateManager(l_stateManager), m_transparent(false), m_transcendent(false)
{
}


BaseState::~BaseState()
{
}
