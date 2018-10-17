#pragma once

#include "../Window.h"

namespace engine
{
	namespace graph
	{
		class Input
		{
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
