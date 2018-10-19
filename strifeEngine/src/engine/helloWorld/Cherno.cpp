#include "Cherno.h"

namespace engine
{
	namespace helloWorld
	{
		Cherno::Cherno()
		{

		}

		void Cherno::init(Window * window)
		{
			scene = new SceneCherno();
			scene->init(window);
		}

		void Cherno::input(Window * window, Input * input)
		{
			m_input = input;
		}

		void Cherno::update(float interval, Input * input)
		{
			scene->update(interval, input);
		}

		void Cherno::render(Window * window)
		{
			scene->render(window);
		}

		Window * Cherno::getWindow()
		{
			return window;
		}

		Input * Cherno::getInput()
		{
			return m_input;
		}

		void Cherno::cleanUp()
		{
			scene->cleanUp();
		}

		Cherno::~Cherno()
		{

		}
	}
}
