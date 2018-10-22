#include "Window.h"

namespace engine
{
	namespace graph
	{
		Window::Window(std::string _title, int _width, int _height, bool _vSync, WindowOptions * _opts)

		{
			FOV = (60 * (float)M_PI) / 180;
			title = _title;
			width = _width;
			height = _height;
			vSync = _vSync;
			resized = false;
			opts = _opts;
			projectionMatrix = new glm::mat4();
			m_input = new Input();
		}

		Input * Window::getInput()
		{
			return m_input;
		}

		bool Window::init()
		{
			if (!glfwInit())
			{
				std::cout << "GameEngine: error initializing GLFW!" << std::endl;
				return false;
			}

			glfwDefaultWindowHints(); // optional, the current window hints are already the default
			glfwWindowHint(GLFW_VISIBLE, GL_FALSE); // the window will stay hidden after creation
			glfwWindowHint(GLFW_RESIZABLE, GL_TRUE); // the window will be resizable
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

			if (opts->compatibleProfile) {
				glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
			}
			else {
				glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
				glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
			}

			// m_window = new Window(m_windowTitle, m_width, m_height, m_vSync, m_opts);
			glfwWindow = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
			if (glfwWindow == NULL)
			{
				std::cout << "GameEngine: error creating window!" << std::endl;
				return false;
			}

			const GLFWvidmode * mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
			int x_Pos = (mode->width - width) / 2;
			int y_Pos = (mode->height - height) / 2;
			glfwSetWindowPos(glfwWindow, x_Pos, y_Pos);

			// GLFW setup
			// Make the OpenGL context current
			glfwMakeContextCurrent(glfwWindow);
			int width, height;
			glfwGetFramebufferSize(glfwWindow, &width, &height);

			if (isvSync()) {
				// Enable v-sync
				glfwSwapInterval(1);
			}

			// Make the window visible
			glfwShowWindow(glfwWindow);

			// Antialiasing
			if (opts->antialiasing) {
				glfwWindowHint(GLFW_SAMPLES, 4);
				glEnable(GL_MULTISAMPLE);
			}

			glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			if (opts->mode3D) {
				glEnable(GL_DEPTH_TEST);
			}

			glEnable(GL_STENCIL_TEST);
			if (opts->showTriangles) {
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			}

			// Support for transparencies
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

			if (opts->cullFace) {
				glEnable(GL_CULL_FACE);
				glCullFace(GL_BACK);
			}

			if (glewInit() != GLEW_OK)
			{
				std::cout << "GameEngine: Failed to initialize GLEW!" << std::endl;
			}

			m_input->init(this);

			std::cout << "GameEngine: init complete." << std::endl;

			return true;
		}

		void Window::close()
		{
			glfwSetWindowShouldClose(glfwWindow, true);
		}

		void Window::setMousePositionCenter()
		{
			int xPos = width / 2;
			int yPos = height / 2;
			setMousePosition(xPos, yPos);
		}

		void Window::setMousePosition(int xPos, int yPos)
		{
			glfwSetCursorPos(glfwWindow, xPos, yPos);
		}

		glm::mat4 * Window::updateProjectionMatrix()
		{
			float aspectRatio = (float)width / (float)height;
			projectionMatrix = &glm::perspective(FOV, aspectRatio, Z_NEAR, Z_FAR);
			return projectionMatrix;
		}

		glm::mat4 * Window::getProjectionMatrix()
		{
			return projectionMatrix;
		}

		void Window::setClearColor(float r, float g, float b, float a)
		{
			glClearColor(r, g, b, a);
		}

		bool Window::windowShouldClose()
		{
			return glfwWindowShouldClose(glfwWindow);
		}

		void Window::update()
		{
			glfwSwapBuffers(glfwWindow);
			glfwPollEvents();
		}

		void Window::restoreState()
		{
			if (opts->mode3D) {
				glEnable(GL_DEPTH_TEST);
			}
			glEnable(GL_STENCIL_TEST);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			if (opts->cullFace) {
				glEnable(GL_CULL_FACE);
				glCullFace(GL_BACK);
			}
		}

		GLFWwindow * Window::getHandle()
		{
			return glfwWindow;
		}

		std::string Window::getTitle()
		{
			return title;
		}

		void Window::setTitle(std::string & title)
		{
			glfwSetWindowTitle(glfwWindow, title.c_str());
		}

		int Window::getWidth()
		{
			return width;
		}

		int Window::getHeight()
		{
			return height;
		}

		void Window::setWidth(int _width)
		{
			width = _width;
		}

		void Window::setHeight(int _height)
		{
			height = _height;
		}

		WindowOptions * Window::getWindowOptions()
		{
			return opts;
		}

		bool Window::isResized()
		{
			return resized;
		}

		void Window::setResized(bool _resized)
		{
			resized = _resized;
		}

		bool Window::isvSync()
		{
			return vSync;
		}

		void Window::setvSync(bool _vSync)
		{
			vSync = _vSync;
		}

		void Window::cleanUp()
		{
			glfwTerminate();
		}

		Window::~Window()
		{

		}
	}
}
