#include "GameEngine.h"

using namespace engine;
using namespace engine::interfaces;

namespace engine
{
	GameEngine::GameEngine(std::string windowTitle, int width, int height, bool vSync, WindowOptions* opts, IGameLogic* gameLogic)
	{
		m_width = width;
		m_height = height;
		m_vSync = vSync;
		m_opts = opts;
		m_windowTitle = windowTitle;
		m_gameLogic = gameLogic;
		std::cout << "GameEngine object initialized! Window size " << m_width << "x" << m_height << std::endl;
	}

	bool GameEngine::init()
	{
		if (!glfwInit())
		{
			std::cout << "GameEngine: error initializing GLFW!" << std::endl;
			return false;
		}

		// m_window = new Window(m_windowTitle, m_width, m_height, m_vSync, m_opts);
		window = glfwCreateWindow(m_width, m_height, m_windowTitle.c_str(), NULL, NULL);
		if (window == NULL)
		{
			std::cout << "GameEngine: error creating window!" << std::endl;
			return false;
		}

		// GLFW setup
		glfwMakeContextCurrent(window);
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		glfwSwapInterval(1);

		if (glewInit() != GLEW_OK)
		{
			std::cout << "GameEngine: Failed to initialize GLEW!" << std::endl;
		}

		const GLFWvidmode * mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
		int x_Pos = (mode->width - m_width) / 2;
		int y_Pos = (mode->height - m_height) / 2;
		glfwSetWindowPos(window, x_Pos, y_Pos);

		// OpenGL setup
		// Viewport
		glViewport(0, 0, m_width, m_height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, m_width, 0, m_height, -10, 10);
		glDepthRange(-10, 10);
		glMatrixMode(GL_MODELVIEW);
		// Alpha blending
		glEnable(GL_ALPHA_TEST);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		m_input = new graph::Input();
		std::cout << "GameEngine: init complete." << std::endl;

		return true;
	}

	GLFWwindow * GameEngine::getWindow()
	{
		return window;
	}

	void GameEngine::update(float interval)
	{
		glfwPollEvents();
	}

	void GameEngine::BeginRender()
	{
		glClearColor(0.2f, 0.3f, 0.8f, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void GameEngine::EndRender()
	{
		glfwSwapBuffers(window);
	}

	void GameEngine::start()
	{
		std::cout << "GameEngine: started." << std::endl;
	}

	void GameEngine::run()
	{
	}

	void GameEngine::gameLoop()
	{
	}

	void GameEngine::sync()
	{
	}

	void GameEngine::input()
	{
	}

	int GameEngine::getFPS()
	{
		return 0;
	}

	engine::Timer GameEngine::getTimer()
	{
		return engine::Timer();
	}

	void GameEngine::cleanup()
	{
		m_gameLogic->cleanUp();
	}

	GameEngine::~GameEngine()
	{

	}
}
