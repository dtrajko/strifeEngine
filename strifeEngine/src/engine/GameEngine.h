#pragma once

#include <iostream>
#include "interfaces\IGameLogic.h"
#include "Window.h"
#include "graph\Input.h"
#include "Timer.h"
#include "WindowOptions.h"

namespace engine
{
	class GameEngine
	{
	private:
		std::string m_windowTitle;
		engine::Window* m_window;
		engine::interfaces::IGameLogic* m_gameLogic;
		engine::graph::Input* m_input;
		engine::Timer* m_timer;

	public:
		GameEngine(std::string windowTitle, int width, int height, bool vSync, WindowOptions* opts, interfaces::IGameLogic* gameLogic);
		virtual ~GameEngine();
	};
}
