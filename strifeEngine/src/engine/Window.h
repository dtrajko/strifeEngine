#pragma once

#include <iostream>
#include "../engine/WindowOptions.h"

namespace engine
{
	class Window
	{
	public:
		float FOV;
		float Z_NEAR;
		float Z_FAR;

		int m_width;
		int m_height;

	private:
		std::string m_title;
		long m_windowHandle;
		bool m_resized;
		bool m_vSync;
		WindowOptions * m_opts;

	public:
		Window(std::string title, int width, int height, bool vSync, WindowOptions * opts);
		virtual ~Window();
	};
}
