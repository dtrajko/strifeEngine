#pragma once

#include "../interfaces/IGameLogic.h"
#include "../interfaces/IScene.h"
#include "../../engine/graph/Input.h"
#include "../helloWorld/Scene.h"

using namespace engine::interfaces;
using namespace engine::graph;

namespace engine
{
	namespace helloWorld
	{
		class HelloWorld : public IGameLogic
		{
		private:
			Window * window;
			IScene * scene;

		public:
			HelloWorld();
			void init(Window * window);
			void input(Window * window);
			void update(float interval);
			void render(Window* window);
			Window * getWindow();
			void cleanUp();
			virtual ~HelloWorld();
		};
	}
}
