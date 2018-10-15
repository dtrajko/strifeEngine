#include "Window.h"

namespace engine
{
	Window::Window(std::string title, int width, int height, bool vSync, WindowOptions * opts)
	{
		m_title = title;
		m_width = width;
		m_height = height;
		m_vSync = vSync;
		m_opts = opts;
	}

	Window::~Window()
	{

	}
}
