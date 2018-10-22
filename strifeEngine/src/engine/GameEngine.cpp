#include "GameEngine.h"

namespace engine
{
	GameEngine::GameEngine(std::string _windowTitle, int _width, int _height, bool _vSync, WindowOptions * _opts, IGameLogic * _gameLogic)
	{
		windowTitle = _windowTitle;
		width = _width;
		height = _height;
		vSync = _vSync;
		opts = _opts;
		gameLogic = _gameLogic;
		window = new Window(windowTitle, width, height, vSync, opts);
		timer = new Timer();
		std::cout << "GameEngine object initialized! Window size " << width << "x" << height << std::endl;
	}

	bool GameEngine::init()
	{
		window->init();
		timer->init();
		gameLogic->init(window);
		lastFps = timer->getTime();
		fps = 0;
		return true;
	}

	GLFWwindow * GameEngine::getWindow()
	{
		return window->getHandle();
	}

	void GameEngine::update(float interval)
	{
		gameLogic->update(interval);
		window->update();
	}

	void GameEngine::render()
	{
		gameLogic->render(window);
	}

	void GameEngine::start()
	{
		std::cout << "GameEngine: started." << std::endl;
		init();
		gameLoop();
		cleanUp();
	}

	void GameEngine::gameLoop()
	{
		while (!glfwWindowShouldClose(window->getHandle()))
		{
			input();
			update(0.0f);
			render();
		}
	}

	void GameEngine::sync()
	{

	}

	void GameEngine::input()
	{
		gameLogic->input(window);
	}

	int GameEngine::getFPS()
	{
		return 0;
	}

	Timer GameEngine::getTimer()
	{
		return Timer();
	}

	void GameEngine::cleanUp()
	{
		gameLogic->cleanUp();
	}

	GameEngine::~GameEngine()
	{

	}
}
