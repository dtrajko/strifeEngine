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
		m_input = new engine::graph::Input(window);
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

		// temporary
		sprite = new Sprite("resources/assets/art/fortnite.png", 350, 100);
		std::string VERTEX_FILE = "resources/shaders/simpleVertex.glsl";
		std::string FRAGMENT_FILE = "resources/shaders/simpleFragment.glsl";
		SimpleShader * simpleShader = new SimpleShader(VERTEX_FILE, FRAGMENT_FILE);

		return true;
	}

	GLFWwindow * GameEngine::getWindow()
	{
		return window->getHandle();
	}

	void GameEngine::update(float interval)
	{
		window->update();
		sprite->update();
	}

	void GameEngine::render()
	{
		glClearColor(0.2f, 0.3f, 0.8f, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		sprite->render();
		gameLogic->render(window);
	}

	void GameEngine::start()
	{
		std::cout << "GameEngine: started." << std::endl;
		init();
		gameLoop();
		cleanup();
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
		m_input->input(window);
		gameLogic->input(window, m_input);
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
