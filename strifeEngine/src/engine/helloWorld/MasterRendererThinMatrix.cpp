#include "MasterRendererThinMatrix.h"

namespace engine
{
	namespace helloWorld
	{
		MasterRendererThinMatrix::MasterRendererThinMatrix(Window * window)
		{
			std::string vertexFile = "resources/shaders/thinMatrixVertex.glsl";
			std::string fragmentFile = "resources/shaders/thinMatrixFragment.glsl";
			shader = new ThinMatrixShader(vertexFile, fragmentFile);
		}

		void MasterRendererThinMatrix::init(IScene * scene)
		{
		}

		glm::mat4 MasterRendererThinMatrix::createProjectionMatrix(Window * window)
		{
			return glm::mat4();
		}

		glm::mat4 MasterRendererThinMatrix::getProjectionMatrix(Window * window)
		{
			return glm::mat4();
		}

		void MasterRendererThinMatrix::render(Window * window, IScene * scene)
		{
			prepare(window);
			renderModel(scene->getModel());
		}

		void MasterRendererThinMatrix::prepare(Window * window)
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glClearColor(RED, GREEN, BLUE, 1.0f);
			glViewport(0, 0, window->getWidth(), window->getHeight());
			glEnable(GL_DEPTH_TEST);
			// shader->start();
		}

		void MasterRendererThinMatrix::renderModel(RawModel * model)
		{
			glBindVertexArray(model->getVaoID());
			glEnableVertexAttribArray(0);
			glDrawElements(GL_TRIANGLES, model->getVertexCount(), GL_UNSIGNED_INT, 0);
			glDisableVertexAttribArray(0);
			glBindVertexArray(0);
		}

		void MasterRendererThinMatrix::renderModel(Entity * entity)
		{
		}

		void MasterRendererThinMatrix::cleanUp()
		{
		}

		MasterRendererThinMatrix::~MasterRendererThinMatrix()
		{
		}
	}
}
