#pragma once

#include "../../engine/interfaces/IScene.h"

using namespace engine::interfaces;

namespace engine
{
	namespace helloWorld
	{
		class SceneHelloWorld : public IScene
		{
		public:
			SceneHelloWorld();
			virtual ~SceneHelloWorld();
		};
	}
}
