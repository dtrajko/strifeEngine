#pragma once

#include "IScene.h"
#include "../../engine/graph/Window.h"
#include "../../engine/graph/Input.h"

using namespace engine::graph;

namespace engine
{
	namespace interfaces
	{
		class IGameLogic
		{
		private:
			Window * m_window;
			IScene * m_scene;
			Input * m_input;

		public:
			virtual void init(Window* window) = 0;
			virtual void input(Window* window, Input * input) = 0;
			virtual void update(float interval, Input * input) = 0;
			virtual void render(Window* window) = 0;
			virtual Window * getWindow() = 0;
			virtual Input * getInput() = 0;
			virtual void cleanUp() = 0;
		};
	}
}
