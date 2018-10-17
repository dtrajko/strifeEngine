#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "interfaces\IGameLogic.h"
#include "Window.h"
#include "Timer.h"
#include "WindowOptions.h"
#include "../engine/graph/Input.h"

using namespace engine;
using namespace engine::interfaces;
using namespace engine::graph;

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
		std::string windowTitle;
		Window * window;
		IGameLogic * gameLogic;
		Input * input;
		Timer * timer;

	public:
		GameEngine(std::string _windowTitle, int _width, int _height, bool _vSync, WindowOptions * _opts, IGameLogic * _gameLogic);
		void start();
		void run();
		bool init();
		GLFWwindow * getWindow();
		void gameLoop();
		void sync();
		void Input();
		void update(float interval);
		void BeginRender();
		void EndRender();
		int getFPS();
		engine::Timer getTimer();
		void cleanup();
		virtual ~GameEngine();
	};
}
