#include "MasterRendererHelloWorld.h"

namespace engine
{
	namespace helloWorld
	{
		MasterRendererHelloWorld::MasterRendererHelloWorld(Window * window)
		{
			std::string vertexFile = "resources/shaders/simpleVertex.glsl";
			std::string fragmentFile = "resources/shaders/simpleFragment.glsl";
			shader = new SimpleShader(vertexFile, fragmentFile);
			projectionMatrix = createProjectionMatrix(window);
			shader->start();
			shader->loadMatrix("projectionMatrix", projectionMatrix);
			shader->stop();
		}

		void MasterRendererHelloWorld::init(IScene * scene)
		{

		}

		glm::mat4 MasterRendererHelloWorld::createProjectionMatrix(Window * window)
		{
			float aspectRatio = (float) window->getWidth() / (float) window->getHeight();
			projectionMatrix = glm::perspective(
				glm::radians(FOV),
				aspectRatio,
				NEAR_PLANE,
				FAR_PLANE
			);
			return projectionMatrix;
		}

		glm::mat4 MasterRendererHelloWorld::getProjectionMatrix(Window * window)
		{
			return projectionMatrix;
		}

		void MasterRendererHelloWorld::render(Window * window, IScene * scene)
		{
			prepare(window);
			shader->loadMatrix("viewMatrix", scene->getCamera()->getViewMatrix());
			renderModel(scene->getEntity());
		}

		void MasterRendererHelloWorld::prepare(Window * window)
		{
			glViewport(0, 0, window->getWidth(), window->getHeight());
			glEnable(GL_DEPTH_TEST);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glClearColor(RED, GREEN, BLUE, 1.0f);
			shader->start();
		}

		void MasterRendererHelloWorld::renderModel(Entity * entity)
		{
			TexturedModel * texturedModel = entity->getTexturedModel();
			RawModel * rawModel = texturedModel->getRawModel();
			glBindVertexArray(rawModel->getVaoID());
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);
			glm::mat4 transformationMatrix = Maths::createTransformationMatrix(entity->getPosition(), entity->getRotX(), entity->getRotY(), entity->getRotZ(), entity->getScale());
			shader->loadMatrix("transformationMatrix", transformationMatrix);
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE0, texturedModel->getTexture()->getID());
			shader->loadInt("textureSampler", 0);
			glDrawElements(GL_TRIANGLES, rawModel->getVertexCount(), GL_UNSIGNED_INT, nullptr);
			glDisableVertexAttribArray(0);
			glDisableVertexAttribArray(1);
			glBindVertexArray(0);
		}

		void MasterRendererHelloWorld::cleanUp()
		{
			shader->cleanUp();
		}

		MasterRendererHelloWorld::~MasterRendererHelloWorld()
		{

		}
	}
}
