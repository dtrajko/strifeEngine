#pragma once

#include "../interfaces/IGameLogic.h"
#include "../interfaces/IScene.h"
#include "../../engine/graph/Input.h"
#include "../helloWorld/SceneThinMatrix.h"

using namespace engine::interfaces;
using namespace engine::graph;

namespace engine
{
	namespace helloWorld
	{
		class ThinMatrix : public IGameLogic
		{
		private:
			Window * window;
			IScene * scene;
			Input * m_input;

		public:
			ThinMatrix();
			void init(Window * window);
			void input(Window * window, Input * input);
			void update(float interval, Input * input);
			void render(Window* window);
			Window * getWindow();
			Input * getInput();
			void cleanUp();
			virtual ~ThinMatrix();
		};
	}
}
