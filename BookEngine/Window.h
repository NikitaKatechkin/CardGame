#pragma once
#include "EventManager.h"

class Window
{
private:
	sf::RenderWindow m_window;
	sf::Vector2u m_windowSize;
	std::string m_windowTitle;

	bool m_isDone;
	bool m_isFullscreen;

	EventManager m_eventManager;
	bool m_isFocused;

	void Setup(std::string l_title, sf::Vector2u l_size);
	void Destroy();
	void Create();
public:
	void BeginDraw();
	void EndDraw();

	void Update();

	bool IsDone();
	bool IsFullscreen();
	sf::Vector2u GetWindowSize();

	sf::RenderWindow* GetRenderWindow();

	void Draw(sf::Drawable* l_drawable);

	bool IsFocused();
	EventManager* GetEventManager();
	void ToggleFullscreen(EventDetails* l_details);
	void Close(EventDetails* l_details = nullptr);

	Window(std::string l_title, sf::Vector2u l_size);
	Window();
	~Window();
};

