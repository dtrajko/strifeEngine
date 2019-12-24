#include "GameEngine.h"


namespace engine
{
	GameEngine::GameEngine(std::string & windowTitle, int width, int height, bool vSync, WindowOptions * options, IGameLogic * gameLogic)
	{
		m_Options = options;
		m_WindowTitle = windowTitle;
		m_Width = width;
		m_Height = height;
		m_vSync = vSync;
		m_GameLogic = gameLogic;
		window = new Window(m_WindowTitle, m_Width, m_Height, m_vSync, m_Options);
		timer = TimerSingleton::get();
		lastFps = 0;
		std::cout << "GameEngine object initialized! Window size " << m_Width << "x" << m_Height << std::endl;
	}

	bool GameEngine::init()
	{
		timer->init();
		m_GameLogic->init(window);
		lastFps = timer->getTime();
		fps = 0;
		return true;
	}

	GLFWwindow * GameEngine::getWindow()
	{
		return window->getHandle();
	}

	void GameEngine::update(float interval, Window * window)
	{
		window->update();
		m_GameLogic->update(interval, window);
	}

	void GameEngine::render()
	{
		m_GameLogic->render(window);
	}

	void GameEngine::start()
	{
		std::cout << "GameEngine: started." << std::endl;
		init();
		gameLoop();
	}

	void GameEngine::gameLoop()
	{
		while (!glfwWindowShouldClose(window->getHandle()))
		{
			update(0.0f, window);
			render();

			std::cout << "getTime: " << timer->getTime() << " getElapsedTime: " << timer->getElapsedTime() << " getLastLoopTime: " << timer->getLastLoopTime() << std::endl;
		}
	}

	void GameEngine::sync()
	{

	}

	int GameEngine::getFPS()
	{
		return fps;
	}

	TimerSingleton * GameEngine::getTimer()
	{
		return timer;
	}

	void GameEngine::cleanUp()
	{
		m_GameLogic->cleanUp();
	}

	GameEngine::~GameEngine()
	{

	}
}
