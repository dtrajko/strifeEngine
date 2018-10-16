#pragma once

#include <iostream>
#include "interfaces\IGameLogic.h"
#include "Window.h"
#include "graph\Input.h"
#include "Timer.h"
#include "WindowOptions.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace engine
{
	class GameEngine
	{
	public:
		int m_width;
		int m_height;
		bool m_vSync;
		WindowOptions * m_opts;

	private:
		GLFWwindow * window;
		std::string m_windowTitle;
		engine::Window* m_window;
		engine::interfaces::IGameLogic* m_gameLogic;
		engine::graph::Input* m_input;
		engine::Timer* m_timer;

	public:
		GameEngine(std::string windowTitle, int width, int height, bool vSync, WindowOptions* opts, interfaces::IGameLogic* gameLogic);
		void start();
		void run();
		bool init();
		void gameLoop();
		void sync();
		void input();
		void update(float interval);
		void BeginRender();
		void EndRender();
		int getFPS();
		engine::Timer getTimer();
		void cleanup();
		virtual ~GameEngine();
	};
}
