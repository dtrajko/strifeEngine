#include "SceneHelloWorld.h"

namespace engine
{
	namespace helloWorld
	{
		SceneHelloWorld::SceneHelloWorld()
		{
			// masterRenderer = new MasterRendererHelloWorld();
		}

		void SceneHelloWorld::init()
		{

		}

		void SceneHelloWorld::update(float interval, Input * input)
		{

		}

		void SceneHelloWorld::render(Window * window)
		{
			// masterRenderer->render(window, this);
		}

		void SceneHelloWorld::cleanUp()
		{

		}

		ICamera SceneHelloWorld::getCamera()
		{
			return ICamera();
		}

		Loader SceneHelloWorld::getLoader()
		{
			return Loader();
		}

		SceneHelloWorld::~SceneHelloWorld()
		{

		}
	}
}
