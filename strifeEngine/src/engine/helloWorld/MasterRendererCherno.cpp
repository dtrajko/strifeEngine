#include "MasterRendererCherno.h"

namespace engine
{
	namespace helloWorld
	{
		MasterRendererCherno::MasterRendererCherno(Window * window)
		{
			std::string vertexFile = "resources/shaders/chernoVertex.glsl";
			std::string fragmentFile = "resources/shaders/chernoFragment.glsl";
			shader = new ChernoShader(vertexFile, fragmentFile);
		}

		void MasterRendererCherno::init(IScene * scene)
		{
		}

		glm::mat4 MasterRendererCherno::createProjectionMatrix(Window * window)
		{
			return glm::mat4();
		}

		glm::mat4 MasterRendererCherno::getProjectionMatrix(Window * window)
		{
			return glm::mat4();
		}

		void MasterRendererCherno::render(Window * window, IScene * scene)
		{
			prepare(window);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
		}

		void MasterRendererCherno::prepare(Window * window)
		{
			glViewport(0, 0, window->getWidth(), window->getHeight());
			glEnable(GL_DEPTH_TEST);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glClearColor(RED, GREEN, BLUE, 1.0f);
			shader->start();
		}

		void MasterRendererCherno::renderModel(Entity * entity)
		{
		}

		void MasterRendererCherno::cleanUp()
		{
		}

		MasterRendererCherno::~MasterRendererCherno()
		{
		}
	}
}
