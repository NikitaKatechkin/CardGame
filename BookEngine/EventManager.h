#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <functional>
#include <iostream>
#include <fstream>
#include <sstream>

enum class EventType
{
	KeyDown = sf::Event::KeyPressed,
	KeyUp = sf::Event::KeyReleased,
	MButtonDown = sf::Event::MouseButtonPressed,
	MButtonUp = sf::Event::MouseButtonReleased,
	MouseWheel = sf::Event::MouseWheelMoved,
	WindowResized = sf::Event::Resized,
	GainedFocus = sf::Event::GainedFocus, 
	LostFocus = sf::Event::LostFocus,
	MouseEntered = sf::Event::MouseEntered,
	MouseLeft = sf::Event::MouseLeft,
	Closed = sf::Event::Closed,
	TextEntered = sf::Event::TextEntered,
	Keyboard = sf::Event::Count,
	Mouse,
	Joystick
};

struct EventInfo
{
	EventInfo()
	{
		m_code = 0;
	}
	EventInfo(int l_event)
	{
		m_code = l_event;
	}
	union
	{
		int m_code;
	};
};

struct EventDetails
{
	EventDetails(std::string l_name) :
		m_name(l_name)
	{
		Clear();
	}

	std::string m_name;

	sf::Vector2f m_size;
	sf::Uint32 m_textEntered;

	sf::Vector2i m_mouse;
	int m_mouseWheelDelta;
	int m_keyCode;

	void Clear()
	{
		m_size = sf::Vector2f(0, 0);
		m_textEntered = 0;
		m_mouse = sf::Vector2i(0, 0);
		m_mouseWheelDelta = 0;
		m_keyCode = -1; //lastPressedButton
	}
};

using Events = std::vector<std::pair<EventType, EventInfo>>;

struct Binding
{
	Binding(std::string l_name):
		m_name(l_name), m_details(l_name), counter(0)
	{

	}

	void BindEvent(EventType l_type, EventInfo l_info = EventInfo()) 
	{
		m_events.emplace_back(l_type, l_info);
	}

	Events m_events;
	std::string m_name;
	int counter;

	EventDetails m_details;
};

using Bindings = std::unordered_map<std::string, Binding*>;

using CallbacksContainer = std::unordered_map<std::string, std::function<void(EventDetails*)>>;

enum class StateType;
using Callbacks = std::unordered_map<StateType, CallbacksContainer>;

class EventManager
{
private:
	void LoadBindings();

	Bindings m_bindings;
	Callbacks m_callbacks;
	StateType m_currentState;
	bool m_hasFocus;
public:
	bool AddBinding(Binding* l_binding);
	bool RemoveBinding(std::string l_name);

	void SetFocus(bool l_focus);

	template<class T>
	bool AddCallback(StateType l_state, const std::string& l_name, 
		void(T::*l_func)(EventDetails*), T* l_instance)
	{
		auto iter = m_callbacks.emplace(l_state, CallbacksContainer()).first;
		auto temp = std::bind(l_func, l_instance, std::placeholders::_1);
		return iter->second.emplace(l_name, temp).second;
	}

	bool RemoveCallback(StateType l_state, std::string l_name);

	void SetCurrentState(StateType l_state);

	void HandleEvent(sf::Event* l_event);
	void Update();

	sf::Vector2i GetMousePosition(sf::RenderWindow* l_window = nullptr);

	EventManager();
	~EventManager();
};

