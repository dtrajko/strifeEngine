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
		int width;
		int height;
		bool vSync;
		WindowOptions * opts;

	private:
		GLFWwindow * glfwWindow;
		Window * window;
		std::string windowTitle;
		IGameLogic * gameLogic;
		Timer * timer;
		double lastFps;
		int fps;

	public:
		GameEngine(std::string & _windowTitle, int _width, int _height, bool _vSync, WindowOptions * _opts, IGameLogic * _gameLogic);
		void start();
		bool init();
		GLFWwindow * getWindow();
		void gameLoop();
		void sync();
		void update(float interval, Window * window);
		void render();
		int getFPS();
		engine::Timer getTimer();
		void cleanUp();
		virtual ~GameEngine();
	};
}
