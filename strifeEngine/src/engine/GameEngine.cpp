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
		input = new engine::graph::Input(window);
		std::cout << "GameEngine object initialized! Window size " << width << "x" << height << std::endl;
	}

	bool GameEngine::init()
	{
		window->init();
		return true;
	}

	GLFWwindow * GameEngine::getWindow()
	{
		return window->getWindowHandle();
	}

	void GameEngine::update(float interval)
	{
		window->update();
	}

	void GameEngine::BeginRender()
	{
		glClearColor(0.2f, 0.3f, 0.8f, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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

	void GameEngine::Input()
	{

	}

	int GameEngine::getFPS()
	{
		return 0;
	}

	Timer GameEngine::getTimer()
	{
		return Timer();
	}

	void GameEngine::cleanup()
	{
		gameLogic->cleanUp();
	}

	GameEngine::~GameEngine()
	{

	}
}
