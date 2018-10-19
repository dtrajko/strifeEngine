#include "ThinMatrix.h"

namespace engine
{
	namespace helloWorld
	{
		ThinMatrix::ThinMatrix()
		{

		}

		void ThinMatrix::init(Window * window)
		{
			scene = new SceneThinMatrix();
			scene->init(window);
		}

		void ThinMatrix::input(Window * window, Input * input)
		{
			m_input = input;
		}

		void ThinMatrix::update(float interval, Input * input)
		{
			scene->update(interval, input);
		}

		void ThinMatrix::render(Window * window)
		{
			scene->render(window);
		}

		Window * ThinMatrix::getWindow()
		{
			return window;
		}

		Input * ThinMatrix::getInput()
		{
			return m_input;
		}

		void ThinMatrix::cleanUp()
		{
			scene->cleanUp();
		}

		ThinMatrix::~ThinMatrix()
		{

		}
	}
}
