#pragma once

#include "./Window.h"

namespace engine
{
	namespace graph
	{
		class Input
		{
		private:
			GLFWwindow * windowHandle;
			glm::vec2 displayVector;
			glm::vec2 currentPosition;
			bool * keys;
			bool * buttons;

		public:
			Input(Window * window);
			void init(Window * window);
			void input(Window * window);
			void update(Window * window);
			virtual ~Input();

			// TODO: 
			// getDisplVec()
			// getMousePosition()
			// getMouseWheelDelta()
			// isLeftButtonPressed()
			// isRightButtonPressed()
			// isKeyDown()
			// isKeyPressed()
			// isKeyReleased()
			// isMouseButtonDown()
			// isMouseButtonPressed()
			// isMouseButtonReleased()
		};
	}
}
