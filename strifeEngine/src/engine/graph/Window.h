#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../../vendor/glm/glm.hpp"
#include "../../vendor/glm/gtc/matrix_transform.hpp"
#include "../../engine/WindowOptions.h"
#include "../../engine/graph/Input.h"

namespace engine
{
	namespace graph
	{
		#define MAX_KEYS  1024
		#define MAX_BUTTONS 32

		class Window
		{
		public:
			Input * m_input;

			bool m_Keys[MAX_KEYS];
			bool m_MouseButtons[MAX_BUTTONS];
			double mouseX;
			double mouseY;

			float FOV;
			float Z_NEAR;
			float Z_FAR;

			int width;
			int height;

		private:
			GLFWwindow * glfwWindow;
			std::string title;
			bool resized;
			bool vSync;
			WindowOptions * opts;
			glm::mat4 * projectionMatrix;

		public:
			Window(std::string _title, int _width, int _height, bool _vSync, WindowOptions * _opts);
			bool init();
			void close();
			void setMousePositionCenter();
			void setMousePosition(int xPos, int yPos);
			glm::mat4 * updateProjectionMatrix();
			glm::mat4 * getProjectionMatrix();
			void setClearColor(float r, float g, float b, float a);
			bool isKeyPressed(unsigned int keyCode) const;
			bool isMouseButtonPressed(unsigned int button) const;
			glm::vec2 getMousePosition() const;
			bool windowShouldClose();
			void update();
			void restoreState();
			void cleanUp();
			virtual ~Window();

			// getters / setters
			GLFWwindow * getHandle();
			std::string getTitle();
			void setTitle(std::string & title);
			int getWidth();
			int getHeight();
			void setWidth(int _width);
			void setHeight(int _height);
			WindowOptions * getWindowOptions();
			bool isResized();
			void setResized(bool _resized);
			bool isvSync();
			void setvSync(bool _vSync);

			static void key_callback(GLFWwindow * glfwWindow, int key, int scancode, int action, int mods);
			static void cursor_position_callback(GLFWwindow * glfwWindow, double xpos, double ypos);
			static void mouse_button_callback(GLFWwindow * glfwWindow, int button, int action, int mods);
			static void window_resize(GLFWwindow * glfwWindow, int width, int height);

		};
	}
}
