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

		void HelloWorld::input(Window * window, Input * input)
		{
			m_input = input;
		}

		void HelloWorld::update(float interval, Input * input)
		{
			scene->update(interval, window, input);
		}

		void HelloWorld::render(Window * window)
		{
			scene->render(window);
		}

		Window * HelloWorld::getWindow()
		{
			return window;
		}

		Input * HelloWorld::getInput()
		{
			return m_input;
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
