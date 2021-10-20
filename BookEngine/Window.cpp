#include "Window.h"



void Window::ToggleFullscreen(EventDetails* l_details)
{
	m_isFullscreen = !m_isFullscreen;
	Destroy();
	Create();
}

void Window::Draw(sf::Drawable * l_drawable)
{
	BeginDraw();
	m_window.draw(*l_drawable);
	EndDraw();
}

bool Window::IsFocused()
{
	return m_isFocused;
}

EventManager * Window::GetEventManager()
{
	return &m_eventManager;
}

void Window::Close(EventDetails * l_details)
{
	m_isDone = true;
	Destroy();
}

Window::Window(std::string l_title, sf::Vector2u l_size)
{
	Setup(l_title, l_size);
}

Window::Window()
{
	Setup("Window", sf::Vector2u(640, 480));
}


Window::~Window()
{
	Destroy();
}

void Window::Setup(std::string l_title, sf::Vector2u l_size)
{
	m_windowTitle = l_title;
	m_windowSize = l_size;
	m_isDone = false;
	m_isFullscreen = false;
	m_isFocused = true;

	m_eventManager.AddCallback(StateType(0), "Fullscreen_toggle", &Window::ToggleFullscreen, this);
	m_eventManager.AddCallback(StateType(0), "Window_close", &Window::Close, this);

	Create();
}

void Window::Destroy()
{
	m_window.close();
}

void Window::Create()
{
	auto style = (m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
	m_window.create({m_windowSize.x, m_windowSize.y, 32},m_windowTitle, style);
}

void Window::BeginDraw()
{
	m_window.clear(sf::Color::Black);
}

void Window::EndDraw()
{
	m_window.display();
}

void Window::Update()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::LostFocus:
			m_isFocused = false;
			m_eventManager.SetFocus(m_isFocused);
			break;
		case sf::Event::GainedFocus:
			m_isFocused = true;
			m_eventManager.SetFocus(m_isFocused);
			break;
		default:
			break;
		}
		m_eventManager.HandleEvent(&event);
	}
	m_eventManager.Update();
}

bool Window::IsDone()
{
	return m_isDone;
}

bool Window::IsFullscreen()
{
	return m_isFullscreen;
}

sf::Vector2u Window::GetWindowSize()
{
	return m_windowSize;
}

sf::RenderWindow* Window::GetRenderWindow()
{
	return &m_window;
}
