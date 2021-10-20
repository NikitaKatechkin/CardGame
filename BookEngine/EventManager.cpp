#include "EventManager.h"



void EventManager::LoadBindings()
{
	std::string delimeter = ":";

	std::ifstream inFileStreamBinding;
	inFileStreamBinding.open("config/keys.ini");

	if (!inFileStreamBinding.is_open())
	{
		std::cout << "ERROR" << std::endl;
		return;
	}

	std::string line;
	while (std::getline(inFileStreamBinding, line))
	{
		std::stringstream keystream(line);
		std::string callbackName;
		keystream >> callbackName;
		Binding* binding = new Binding(callbackName);
		while (!keystream.eof())
		{
			std::string keyValue;
			keystream >> keyValue;

			int start = 0;
			int end = keyValue.find(delimeter);

			if (end == std::string::npos)
			{
				delete binding;
				binding = nullptr;
				break;
			}

			EventType type = EventType(std::stoi(keyValue.substr(start, end - start)));
			int code = std::stoi(keyValue.substr(end + delimeter.length(),
				keyValue.find(delimeter, end + delimeter.length())));
			EventInfo eventInfo;
			eventInfo.m_code = code;
			binding->BindEvent(type, eventInfo);
		}
		
		if (!AddBinding(binding))
			delete binding;

		binding = nullptr;
	}
	inFileStreamBinding.close();
}

bool EventManager::AddBinding(Binding * l_binding)
{
	if(m_bindings.find(l_binding->m_name) != m_bindings.end())
		return false;

	return m_bindings.emplace(l_binding->m_name, l_binding).second;
}

bool EventManager::RemoveBinding(std::string l_name)
{
	auto iter = m_bindings.find(l_name);
	if (iter == m_bindings.end())
		return false;
	delete iter->second;
	m_bindings.erase(iter);
	return true;
}

void EventManager::SetFocus(bool l_focus)
{
	m_hasFocus = l_focus;
}

bool EventManager::RemoveCallback(StateType l_state, std::string l_name)
{
	auto iter = m_callbacks.find(l_state);
	if (iter == m_callbacks.end()) 
	{ 
		return false; 
	}
	auto iterBinding = iter->second.find(l_name);
	if (iterBinding == iter->second.end()) 
	{ 
		return false; 
	}
	iter->second.erase(l_name);
	return true;
}

void EventManager::SetCurrentState(StateType l_state)
{
	m_currentState = l_state;
}

void EventManager::HandleEvent(sf::Event * l_event)
{
	for (auto iter : m_bindings)
	{
		Binding* binding = iter.second;
		for (auto event_iter : binding->m_events)
		{
			EventType sfmlEvent = (EventType)l_event->type;
			if (event_iter.first != sfmlEvent)
			{
				continue;
			}

			if (sfmlEvent == EventType::KeyDown || 
				sfmlEvent == EventType::KeyUp)
			{
				if (event_iter.second.m_code == l_event->key.code)
				{
					if (binding->m_details.m_keyCode != -1)
					{
						binding->m_details.m_keyCode = event_iter.second.m_code;
					}
					++(binding->counter);
					break;
				}
			}
			else if (sfmlEvent == EventType::MButtonDown || sfmlEvent == EventType::MButtonUp)
			{
				if (event_iter.second.m_code == l_event->mouseButton.button)
				{
					binding->m_details.m_mouse.x = l_event->mouseButton.x;
					binding->m_details.m_mouse.y = l_event->mouseButton.y;
					if (binding->m_details.m_keyCode != -1)
					{
						binding->m_details.m_keyCode = event_iter.second.m_code;
					}
					++(binding->counter);
					break;
				}
			}
			else
			{
				switch (sfmlEvent)
				{
				case EventType::MouseWheel:
					binding->m_details.m_mouseWheelDelta = l_event->mouseWheel.delta;
					break;
				case EventType::WindowResized:
					binding->m_details.m_size = sf::Vector2f(float(l_event->size.width), float(l_event->size.height));
					break;
				case EventType::TextEntered:
					binding->m_details.m_textEntered = l_event->text.unicode;
					break;
				default:
					break;
				}
				++(binding->counter);
			}
		}
	}
}

void EventManager::Update()
{
	if (!m_hasFocus)
		return;

	for (auto iter : m_bindings)
	{
		Binding* binding = iter.second;
		for (auto event_iter : binding->m_events)
		{
			switch (event_iter.first)
			{
			case EventType::Keyboard:
				if (binding->m_details.m_keyCode != -1)
				{
					binding->m_details.m_keyCode = event_iter.second.m_code;
				}
				++(binding->counter);
				break;
			case EventType::Mouse:
				if (binding->m_details.m_keyCode != -1)
				{
					binding->m_details.m_keyCode = event_iter.second.m_code;
				}
				++(binding->counter);
				break;
			case EventType::Joystick:
				break;
			}

			if (binding->counter == binding->m_events.size())
			{
				auto stateCallbacks = m_callbacks.find(m_currentState);
				auto otherCallbacks = m_callbacks.find(StateType(0));

				if (stateCallbacks != m_callbacks.end())
				{
					auto callIter = stateCallbacks->second.find(binding->m_name);
					if (callIter != stateCallbacks->second.end())
					{
						callIter->second(&binding->m_details);
					}
				}

				if (otherCallbacks != m_callbacks.end())
				{
					auto callIter = otherCallbacks->second.find(binding->m_name);
					if (callIter != otherCallbacks->second.end())
					{
						callIter->second(&binding->m_details);
					}
				}
			}

			//if nothing happend and we missed EventCombo needs
			//to activate binding we simple reset the state if this
			//binding
			binding->counter = 0;
			binding->m_details.Clear();
		}
	}
}

sf::Vector2i EventManager::GetMousePosition(sf::RenderWindow * l_window)
{
	return (l_window ? sf::Mouse::getPosition(*l_window) 
		: sf::Mouse::getPosition());
}

EventManager::EventManager() :
	m_hasFocus(true)
{
	LoadBindings();
}


EventManager::~EventManager()
{
	for (auto iter : m_bindings)
	{
		delete iter.second;
		iter.second = nullptr;
	}
}
