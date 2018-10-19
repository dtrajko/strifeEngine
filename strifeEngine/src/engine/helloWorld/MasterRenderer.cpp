#include "MasterRenderer.h"

namespace engine
{
	namespace helloWorld
	{
		MasterRenderer::MasterRenderer(Window * window)
		{
			std::string vertexFile = "resources/shaders/simpleVertex.glsl";
			std::string fragmentFile = "resources/shaders/simpleFragment.glsl";
			shader = new SimpleShader(vertexFile, fragmentFile);
		}

		void MasterRenderer::init(IScene * scene)
		{
		}

		glm::mat4 MasterRenderer::createProjectionMatrix(Window * window)
		{
			return glm::mat4();
		}

		glm::mat4 MasterRenderer::getProjectionMatrix(Window * window)
		{
			return glm::mat4();
		}

		void MasterRenderer::render(Window * window, IScene * scene)
		{
			prepare(window);
			renderModel(scene->getModel());
		}

		void MasterRenderer::prepare(Window * window)
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glClearColor(RED, GREEN, BLUE, 1.0f);
			glViewport(0, 0, window->getWidth(), window->getHeight());
			glEnable(GL_DEPTH_TEST);
			// shader->start();
		}

		void MasterRenderer::renderModel(RawModel * model)
		{
			glBindVertexArray(model->getVaoID());
			glEnableVertexAttribArray(0);
			glDrawElements(GL_TRIANGLES, model->getVertexCount(), GL_UNSIGNED_INT, 0);
			glDisableVertexAttribArray(0);
			glBindVertexArray(0);
		}

		void MasterRenderer::renderModel(Entity * entity)
		{
		}

		void MasterRenderer::cleanUp()
		{
		}

		MasterRenderer::~MasterRenderer()
		{
		}
	}
}
