#include "Input.h"
#include "../utils/Log.h"

using namespace engine::utils;

namespace engine
{
	namespace graph
	{
		void Input::key_callback(GLFWwindow * glfwWindow, int key, int scancode, int action, int mods)
		{
			Window * window = (Window*) glfwGetWindowUserPointer(glfwWindow);
			window->getInput()->m_Keys[key] = action != GLFW_RELEASE;
		}

		void Input::mouse_button_callback(GLFWwindow * glfwWindow, int button, int action, int mods)
		{
			Window * window = (Window*) glfwGetWindowUserPointer(glfwWindow);
			window->getInput()->m_MouseButtons[button] = action != GLFW_RELEASE;
		}

		void Input::cursor_position_callback(GLFWwindow * glfwWindow, double xpos, double ypos)
		{
			Window * window = (Window*) glfwGetWindowUserPointer(glfwWindow);
			window->getInput()->setMousePosition(xpos, ypos);
		}

		void Input::window_resize(GLFWwindow * glfwWindow, int width, int height)
		{
			Window * window = (Window*)glfwGetWindowUserPointer(glfwWindow);
			window->setWidth(width);
			window->setHeight(height);
		}

		Input::Input()
		{
			mouseX = 0.0;
			mouseY = 0.0;
		}

		void Input::init(Window * window)
		{
			for (int indKeys = 0; indKeys < MAX_KEYS; indKeys++)
			{
				m_Keys[indKeys] = false;
			}

			for (int indButtons = 0; indButtons < MAX_BUTTONS; indButtons++)
			{
				m_MouseButtons[indButtons] = false;
			}

			// GLFW callbacks
			glfwWindow = window->getHandle();
			glfwSetWindowUserPointer(glfwWindow, window);
			glfwSetWindowSizeCallback(glfwWindow, window_resize);
			glfwSetKeyCallback(glfwWindow, key_callback);
			glfwSetMouseButtonCallback(glfwWindow, mouse_button_callback);
			glfwSetCursorPosCallback(glfwWindow, cursor_position_callback);
		}

		void Input::input()
		{
			// TODO
		}

		void Input::update()
		{
			for (int indKey = 0; indKey < GLFW_KEY_LAST; indKey++)
			{
				m_Keys[indKey] = isKeyPressed(indKey);
			}
			for (int indButton = 0; indButton < GLFW_MOUSE_BUTTON_LAST; indButton++)
			{
				m_MouseButtons[indButton] = isMouseButtonPressed(indButton);
			}
		}

		bool Input::isKeyPressed(unsigned int keyCode) const
		{
			if (keyCode >= MAX_KEYS)
			{
				return false;
			}
			return m_Keys[keyCode];
		}

		bool Input::isMouseButtonPressed(unsigned int buttonCode) const
		{
			if (buttonCode >= MAX_BUTTONS)
			{
				return false;
			}
			return m_MouseButtons[buttonCode];
		}

		glm::vec2 Input::getMousePosition() const
		{
			return glm::vec2(mouseX, mouseY);
		}

		void Input::setMousePosition(double xpos, double ypos)
		{
			mouseX = xpos;
			mouseY = ypos;
		}

		Input::~Input()
		{

		}
	}
}
