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
			std::cout << "HelloWorld init" << std::endl;
			scene = new Scene(window);
		}

		void HelloWorld::update(float interval, Window * window)
		{
			scene->update(interval, window);
		}

		void HelloWorld::render(Window * window)
		{
			scene->render(window);
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
