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
		public:
			HelloWorld();
			void init(Window * window);
			void update(float interval, Window * window);
			void render(Window * window);
			void cleanUp();
			virtual ~HelloWorld();
		};
	}
}
