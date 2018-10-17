#pragma once

#include "../../engine/interfaces/IScene.h"
#include "../helloWorld/MasterRendererHelloWorld.h"

using namespace engine::interfaces;

namespace engine
{
	namespace helloWorld
	{
		class SceneHelloWorld : public IScene
		{
		private:
			IMasterRenderer * masterRenderer;
		public:
			SceneHelloWorld();
			void init();
			void update(float interval, Input * input);
			void render(Window * window);
			void cleanUp();
			ICamera getCamera();
			virtual Loader getLoader();
			virtual ~SceneHelloWorld();
		};
	}
}
