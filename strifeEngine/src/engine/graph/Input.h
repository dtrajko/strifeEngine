#pragma once

#define MAX_KEYS  1024
#define MAX_BUTTONS 32

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../../vendor/glm/glm.hpp"
#include "../../vendor/glm/gtc/matrix_transform.hpp"
#include "Window.h"

namespace engine
{
	namespace graph
	{
		class Window;

		class Input
		{
		private:
			GLFWwindow * glfwWindow;
			Window * m_Window;
			glm::vec2 displayVector;
			glm::vec2 previousPosition;
			glm::vec2 currentPosition;
			bool * keys;
			bool * buttons;

		public:
			bool m_Keys[MAX_KEYS];
			bool m_MouseButtons[MAX_BUTTONS];
			double mouseX;
			double mouseY;

		public:
			Input(Window * window);
			void init();
			void update();
			bool isKeyPressed(unsigned int keyCode) const;
			bool isKeyDown(unsigned int keyCode) const;
			bool isMouseButtonPressed(unsigned int button) const;
			glm::vec2 getMousePosition() const;
			void setMousePosition(double xpos, double ypos);
			glm::vec2 getDisplayVector();
			virtual ~Input();

			static void key_callback(GLFWwindow * glfwWindow, int key, int scancode, int action, int mods);
			static void cursor_position_callback(GLFWwindow * glfwWindow, double xpos, double ypos);
			static void mouse_button_callback(GLFWwindow * glfwWindow, int button, int action, int mods);
			static void window_resize(GLFWwindow * glfwWindow, int width, int height);

			// TODO: 
			// getDisplayVector()
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
