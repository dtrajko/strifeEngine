#include "SceneThinMatrix.h"

namespace engine
{
	namespace helloWorld
	{
		SceneThinMatrix::SceneThinMatrix()
		{

		}

		void SceneThinMatrix::init(Window * window)
		{
			masterRenderer = new MasterRendererThinMatrix(window);
			loader = new Loader();

			float vertices[]= {
				// left bottom triangle
				-0.5f,  0.5f, 0.0f,  // V0
				-0.5f, -0.5f, 0.0f,  // V1
				 0.5f, -0.5f, 0.0f,  // V2
				 0.5f,  0.5f, 0.0f,  // V3
			};

			unsigned int indices[] = {
				0, 1, 3,  // top left triangle     (V0, V1, V2)
				3, 1, 2   // bottom right triangle (V3, V1, V2)
			};

			model = loader->loadToVAO(vertices, 4 * 3, indices, 6);
		}

		void SceneThinMatrix::update(float interval, Input * input)
		{
		}

		void SceneThinMatrix::render(Window * window)
		{
			masterRenderer->render(window, this);
		}

		Entity * SceneThinMatrix::getEntity()
		{
			return entity;
		}

		RawModel * SceneThinMatrix::getModel()
		{
			return model;
		}

		void SceneThinMatrix::cleanUp()
		{
			loader->cleanUp();
			masterRenderer->cleanUp();
		}

		ICamera * SceneThinMatrix::getCamera()
		{
			return camera;
		}

		Loader * SceneThinMatrix::getLoader()
		{
			return loader;
		}

		SceneThinMatrix::~SceneThinMatrix()
		{

		}
	}
}
