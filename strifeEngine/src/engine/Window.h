#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../engine/WindowOptions.h"

namespace engine
{
	class Window
	{
	public:
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

	public:
		Window(std::string _title, int _width, int _height, bool _vSync, WindowOptions * _opts);
		bool init();
		void close();
		void setMousePositionCenter();
		void setMousePosition(int xPos, int yPos);
		void updateProjectionMatrix(); // TODO: return value Matrix4f
		void getProjectionMatrix();; // TODO: return value Matrix4f
		void setClearColor(float r, float g, float b, float a);
		bool isKeyPressed(int keyCode);
		bool windowShouldClose();
		void update();
		void restoreState();
		void cleanup();
		virtual ~Window();

		// getters / setters
		GLFWwindow * getWindowHandle();
		std::string getTitle();
		void setTitle(std::string & title);
		int getWidth();
		int getHeight();
		WindowOptions * getWindowOptions();
		bool isResized();
		void setResized(bool _resized);
		bool isvSync();
		void setvSync(bool _vSync);
	};
}
