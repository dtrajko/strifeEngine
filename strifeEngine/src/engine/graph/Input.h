#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../../vendor/glm/glm.hpp"
#include "../../vendor/glm/gtc/matrix_transform.hpp"

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
			Input();
			void init();
			void input();
			void update();
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
