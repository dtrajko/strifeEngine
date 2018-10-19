#include "Scene.h"

namespace engine
{
	namespace helloWorld
	{
		Scene::Scene()
		{

		}

		void Scene::init(Window * window)
		{
			masterRenderer = new MasterRenderer(window);
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

		void Scene::update(float interval, Input * input)
		{
		}

		void Scene::render(Window * window)
		{
			masterRenderer->render(window, this);
		}

		Entity * Scene::getEntity()
		{
			return entity;
		}

		RawModel * Scene::getModel()
		{
			return model;
		}

		void Scene::cleanUp()
		{
			loader->cleanUp();
			masterRenderer->cleanUp();
		}

		ICamera * Scene::getCamera()
		{
			return camera;
		}

		Loader * Scene::getLoader()
		{
			return loader;
		}

		Scene::~Scene()
		{

		}
	}
}
