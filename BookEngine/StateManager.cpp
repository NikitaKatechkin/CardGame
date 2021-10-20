#include "StateManager.h"



void StateManager::SwitchTo(StateType l_type)
{
	m_shared->m_eventManager->SetCurrentState(l_type);
	for (auto iter = m_states.begin(); iter != m_states.end(); ++iter)
	{
		if (iter->first == l_type)
		{
			m_states.back().second->Deactivate();
			StateType tmp_type = iter->first;
			BaseState* tmp_state = iter->second;
			m_states.erase(iter);
			m_states.emplace_back(tmp_type, tmp_state);
			tmp_state->Activate();
			return;
		}
	}

	if (!m_states.empty())
	{
		m_states.back().second->Deactivate();
	}
	CreateState(l_type);
	m_states.back().second->Activate();
}

void StateManager::Remove(StateType l_type)
{
	m_toRemove.push_back(l_type);
}

StateManager::StateManager(SharedContext* l_shared) :
	m_shared(l_shared)
{
	RegisterState<State_Intro>(StateType::Intro);
	RegisterState<State_Game>(StateType::Game);
	RegisterState<State_MainMenu>(StateType::MainMenu);
	RegisterState<State_Paused>(StateType::Paused);
	RegisterState<State_Credits>(StateType::Credits);
	RegisterState<State_FactHSE>(StateType::FactHSE);
}


StateManager::~StateManager()
{
	for (auto iter : m_states)
	{
		iter.second->OnDestroy();
		delete iter.second;
	}
}

void StateManager::CreateState(StateType l_type)
{
	auto newState = m_stateFactory.find(l_type);
	if (newState == m_stateFactory.end())
	{
		return;
	}
	BaseState* state = newState->second();
	m_states.emplace_back(l_type, state);
	state->OnCreate();
}

void StateManager::RemoveState(StateType l_type)
{
	for (auto iter = m_states.begin(); iter != m_states.end(); ++iter)
	{
		if (iter->first == l_type)
		{
			iter->second->OnDestroy();
			delete iter->second;
			m_states.erase(iter);
			return;
		}
	}
}

void StateManager::Update(sf::Time * l_time)
{
	if (m_states.empty())
	{
		return;
	}
	if (m_states.back().second->IsTranscendent() && m_states.size() > 1)
	{
		auto iter = m_states.end();
		while (iter != m_states.begin())
		{
			if (iter != m_states.end())
			{
				if (!iter->second->IsTranscendent())
				{
					break;
				}
			}
			--iter;
		}
		for (; iter != m_states.end(); ++iter)
		{
			m_states.back().second->Update(*l_time);
		}
	}
	else
	{
		m_states.back().second->Update(*l_time);
	}
}

void StateManager::Draw()
{
	if (m_states.empty())
	{
		return;
	}

	if (m_states.back().second->IsTransparent() && m_states.size() > 1)
	{
		auto iter = m_states.end();
		while (iter != m_states.begin())
		{
			if (iter != m_states.end())
			{
				if (!iter->second->IsTransparent())
				{
					break;
				}
			}
			--iter;
		}
		for (; iter != m_states.end(); ++iter)
		{
			iter->second->Draw();
		}
	}
	else
	{
		m_states.back().second->Draw();
	}
}

void StateManager::ProcessRequests()
{
	while (m_toRemove.begin() != m_toRemove.end())
	{
		RemoveState(*m_toRemove.begin());
		m_toRemove.erase(m_toRemove.begin());
	}
}

SharedContext * StateManager::GetContext()
{
	return m_shared;
}

bool StateManager::HasState(StateType l_type)
{
	for (auto iter = m_states.begin(); iter != m_states.end(); ++iter)
	{
		if (iter->first == l_type)
		{
			auto removed = std::find(m_toRemove.begin(), m_toRemove.end(), l_type);
			if (removed == m_toRemove.end())
			{
				return true;
			}
			return false;
		}
	}

	return false;
}
