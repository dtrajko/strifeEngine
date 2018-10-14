#include "GameEngine.h"
#include "Window.h"
#include "graph/Input.h"

namespace engine
{
	GameEngine::GameEngine(std::string windowTitle, int width, int height, bool vSync,
		engine::WindowOptions* opts, engine::interfaces::IGameLogic* gameLogic)
	{
		m_windowTitle = windowTitle;
		m_window = new Window();
		m_input = new graph::Input();
		m_gameLogic = gameLogic;
		std::cout << "GameEngine object initialized!" << std::endl;
	}

	GameEngine::~GameEngine()
	{

	}
}
