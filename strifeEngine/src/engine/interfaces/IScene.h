#pragma once

#include "ICamera.h"
#include "IMasterRenderer.h"
#include "../../engine/graph/Input.h"
#include "../../engine/tm/loaders/Loader.h"

using namespace engine::graph;
using namespace engine::tm::loaders;

namespace engine
{
	namespace interfaces
	{
		class IScene
		{
		public:
			virtual void init() = 0;
			virtual void update(float interval, Input * input) = 0;
			virtual void cleanUp() = 0;
			virtual ICamera getCamera() = 0;
			virtual Loader getLoader() = 0;
		};
	}
}
