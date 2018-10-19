#include "MasterRendererCherno.h"

namespace engine
{
	namespace helloWorld
	{
		MasterRendererCherno::MasterRendererCherno(Window * window)
		{
			std::string vertexFile = "resources/shaders/simpleVertex.glsl";
			std::string fragmentFile = "resources/shaders/simpleFragment.glsl";
			shader = new SimpleShader(vertexFile, fragmentFile);
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
			glViewport(0, 0, window->getWidth(), window->getHeight());
			prepare();
		}

		void MasterRendererCherno::prepare()
		{
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
