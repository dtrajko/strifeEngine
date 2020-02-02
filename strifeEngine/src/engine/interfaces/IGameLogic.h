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
		public:
			virtual void init(Window * window) = 0;
			virtual void update(float interval, Window * window) = 0;
			virtual void render(Window * window) = 0;
			virtual void cleanUp() = 0;
		};
	}
}
