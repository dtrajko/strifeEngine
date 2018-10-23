#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include "../../engine/WindowOptions.h"
#include "../../engine/graph/Input.h"

namespace engine
{
	namespace graph
	{
		class Input;

		class Window
		{
		public:
			float FOV;
			float Z_NEAR;
			float Z_FAR;

			int width;
			int height;

			Input * m_input;

		private:
			GLFWwindow * glfwWindow;
			std::string title;
			bool resized;
			bool vSync;
			WindowOptions * opts;
			glm::mat4 * projectionMatrix;

		public:
			Window(std::string _title, int _width, int _height, bool _vSync, WindowOptions * _opts);
			Input * getInput();
			bool init();
			void close();
			void setMousePositionCenter();
			void setMousePosition(int xPos, int yPos);
			glm::mat4 * updateProjectionMatrix();
			glm::mat4 * getProjectionMatrix();
			void setClearColor(float r, float g, float b, float a);
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
		};
	}
}
