#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "interfaces\IGameLogic.h"
#include "Timer.h"
#include "WindowOptions.h"
#include "../engine/graph/Window.h"
#include "../engine/graph/Input.h"

using namespace engine;
using namespace engine::graph;
using namespace engine::interfaces;

namespace engine
{
	class GameEngine
	{
	public:
		WindowOptions * m_Options;
		int m_Width;
		int m_Height;
		bool m_vSync;

	private:
		static Timer * timer;
		GLFWwindow * glfwWindow;
		Window * window;
		std::string m_WindowTitle;
		IGameLogic* m_GameLogic;
		int fps;
		double lastFps;

	public:
		GameEngine(std::string& windowTitle, int width, int height, bool vSync, WindowOptions* options, IGameLogic* gameLogic);
		static Timer * getTimer();
		int getFPS();
		GLFWwindow * getWindow();
		void start();
		bool init();
		void gameLoop();
		void sync();
		void update(float interval, Window * window);
		void render();
		void cleanUp();
		virtual ~GameEngine();
	};
}
