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
			shader->start();
			projectionMatrix = createProjectionMatrix(window);
			shader->loadMatrix("projectionMatrix", projectionMatrix);
			shader->stop();
		}

		void MasterRenderer::init(IScene * scene)
		{

		}

		glm::mat4 MasterRenderer::getProjectionMatrix(Window * window)
		{
			return projectionMatrix;
		}

		void MasterRenderer::render(Window * window, IScene * scene)
		{
			prepare(window);
			shader->start();
			shader->loadLight(scene->getLight());
			shader->loadMatrix("viewMatrix", Maths::createViewMatrix(scene->getCamera()));
			renderModel(scene->getEntity(), scene);
			shader->stop();
		}

		void MasterRenderer::prepare(Window * window)
		{
			glViewport(0, 0, window->getWidth(), window->getHeight());
			glEnable(GL_DEPTH_TEST);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glClearColor(RED, GREEN, BLUE, 1.0f);
		}

		void MasterRenderer::renderModel(Entity * entity, IScene * scene)
		{
			TexturedModel * texturedModel = entity->getTexturedModel();
			RawModel * model = texturedModel->getRawModel();
			glBindVertexArray(model->getVaoID());
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);
			glEnableVertexAttribArray(2);
			transformationMatrix = Maths::createTransformationMatrix(
				entity->getPosition(), entity->getRotX(), entity->getRotY(), entity->getRotZ(), entity->getScale());
			shader->loadMatrix("transformationMatrix", transformationMatrix);
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, texturedModel->getTexture()->getID());
			glDrawElements(GL_TRIANGLES, model->getVertexCount(), GL_UNSIGNED_INT, 0);
			glDisableVertexAttribArray(0);
			glDisableVertexAttribArray(1);
			glDisableVertexAttribArray(2);
			glBindVertexArray(0);
		}

		glm::mat4 MasterRenderer::createProjectionMatrix(Window * window)
		{
			glm::mat4 projectionMatrix;
			float aspectRatio = (float)window->getWidth() / (float)window->getHeight();
			float scaleY = (1.0f / glm::tan(glm::radians(FOV / 2.0f))) * aspectRatio;
			float scaleX = scaleY / aspectRatio;
			float frustrumLength = FAR_PLANE - NEAR_PLANE;
			projectionMatrix[0][0] = scaleX;
			projectionMatrix[1][1] = scaleY;
			projectionMatrix[2][2] = -((FAR_PLANE - NEAR_PLANE) / frustrumLength);
			projectionMatrix[2][3] = -1;
			projectionMatrix[3][2] = -((2 * NEAR_PLANE * FAR_PLANE) / frustrumLength);
			projectionMatrix[3][3] = 0;
			return projectionMatrix;
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
