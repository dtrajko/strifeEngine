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
			scene = new SceneHelloWorld();
			scene->init(window);
		}

		void HelloWorld::input(Window * window, Input * input)
		{
			m_input = input;
			// TODO - IF input.isKeyReleased THEN window.close()
		}

		void HelloWorld::update(float interval, Input * input)
		{
			scene->update(interval, input);
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
