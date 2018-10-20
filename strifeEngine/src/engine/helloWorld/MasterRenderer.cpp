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
			shader->start();
			renderTexturedModel(scene->getTexturedModel());
			shader->stop();
		}

		void MasterRenderer::prepare(Window * window)
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glClearColor(RED, GREEN, BLUE, 1.0f);
			glViewport(0, 0, window->getWidth(), window->getHeight());
			glEnable(GL_DEPTH_TEST);
		}

		void MasterRenderer::renderRawModel(RawModel * model)
		{
			glBindVertexArray(model->getVaoID());
			glEnableVertexAttribArray(0);
			glDrawElements(GL_TRIANGLES, model->getVertexCount(), GL_UNSIGNED_INT, 0);
			glDisableVertexAttribArray(0);
			glBindVertexArray(0);
		}

		void MasterRenderer::renderTexturedModel(TexturedModel * texturedModel)
		{
			RawModel * model = texturedModel->getRawModel();
			glBindVertexArray(model->getVaoID());
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, texturedModel->getTexture()->getID());
			glDrawElements(GL_TRIANGLES, model->getVertexCount(), GL_UNSIGNED_INT, 0);
			glDisableVertexAttribArray(0);
			glDisableVertexAttribArray(1);
			glBindVertexArray(0);
		}

		void MasterRenderer::renderModel(Entity * entity)
		{
		}

		void MasterRenderer::cleanUp()
		{
			shader->cleanUp();
		}

		MasterRenderer::~MasterRenderer()
		{
		}
	}
}
