#include "HelloWorld.h"

namespace engine
{
	namespace helloWorld
	{
		HelloWorld::HelloWorld()
		{

		}

		void HelloWorld::init(Window * window)
		{
			scene = new Scene();
			scene->init(window);
		}

		void HelloWorld::input(Window * window)
		{
		}

		void HelloWorld::update(float interval)
		{
			scene->update(interval, window);
		}

		void HelloWorld::render(Window * window)
		{
			scene->render(window);
		}

		Window * HelloWorld::getWindow()
		{
			return window;
		}

		void HelloWorld::cleanUp()
		{
			scene->cleanUp();
		}

		HelloWorld::~HelloWorld()
		{

		}
	}
}
