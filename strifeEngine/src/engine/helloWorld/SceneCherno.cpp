#include "SceneCherno.h"

namespace engine
{
	namespace helloWorld
	{
		SceneCherno::SceneCherno()
		{

		}

		void SceneCherno::init(Window * window)
		{
			masterRenderer = new MasterRendererCherno(window);
			loader = new Loader();

			float vertices[] = {
				-0.5f, -0.5f, // 0
				 0.5f, -0.5f, // 1
				 0.5f,  0.5f, // 2
				-0.5f,  0.5f, // 3
			};

			unsigned int textureCoords[] = {
				0, 0, // 0
				1, 0, // 1
				1, 1, // 2
				0, 1  // 3
			};

			unsigned int indices[] = {
				0, 1, 2,
				2, 3, 0
			};

			unsigned int vertexBuffer;
			glGenBuffers(1, &vertexBuffer);
			glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
			glBufferData(GL_ARRAY_BUFFER, 6 * 2 * sizeof(float), vertices, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

			unsigned int texCoordsBuffer;
			glGenBuffers(1, &texCoordsBuffer);
			glBindBuffer(GL_ARRAY_BUFFER, texCoordsBuffer);
			glBufferData(GL_ARRAY_BUFFER, 6 * 2 * sizeof(unsigned int), textureCoords, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			// glVertexAttribPointer(0, 2, GL_UNSIGNED_INT, GL_FALSE, sizeof(unsigned int) * 2, 0);

			unsigned int indexBuffer;
			glGenBuffers(1, &indexBuffer);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);
		}

		void SceneCherno::update(float interval, Input * input)
		{
		}

		void SceneCherno::render(Window * window)
		{
			masterRenderer->render(window, this);
		}

		Entity * SceneCherno::getEntity()
		{
			return entity;
		}

		void SceneCherno::cleanUp()
		{
			loader->cleanUp();
			masterRenderer->cleanUp();
		}

		ICamera * SceneCherno::getCamera()
		{
			return camera;
		}

		Loader * SceneCherno::getLoader()
		{
			return loader;
		}

		SceneCherno::~SceneCherno()
		{

		}
	}
}
