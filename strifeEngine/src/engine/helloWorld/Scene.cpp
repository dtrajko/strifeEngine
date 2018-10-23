#include "Scene.h"

namespace engine
{
	namespace helloWorld
	{
		Scene::Scene(Window * window)
		{
			init(window);
		}

		void Scene::init(Window * window)
		{
			camera = new Camera();

			masterRenderer = new MasterRenderer(window);
			loader = new Loader();

			/*
			float vertices[] = {
				// left bottom triangle
				-0.5f,  0.5f, 0.0f,  // V0
				-0.5f, -0.5f, 0.0f,  // V1
				0.5f, -0.5f, 0.0f,  // V2
				0.5f,  0.5f, 0.0f,  // V3
			};

			float textureCoords[] = {
			0, 0,  // V0
			0, 1,  // V1
			1, 1,  // V2
			1, 0,  // V3
			};

			unsigned int indices[] = {
				0, 1, 3,  // top left triangle     (V0, V1, V2)
				3, 1, 2   // bottom right triangle (V3, V1, V2)
			};
			rawModel = loader->loadToVAO(vertices, 4 * 3, textureCoords, 4 * 2, indices, 2 * 3);
			*/

			float vertices[] = {
				-0.5f,  0.5f, -0.5f,
				-0.5f, -0.5f, -0.5f,
				0.5f, -0.5f, -0.5f,
				0.5f,  0.5f, -0.5f,

				-0.5f,  0.5f,  0.5f,
				-0.5f, -0.5f,  0.5f,
				0.5f, -0.5f,  0.5f,
				0.5f,  0.5f,  0.5f,

				0.5f,  0.5f, -0.5f,
				0.5f, -0.5f, -0.5f,
				0.5f, -0.5f,  0.5f,
				0.5f,  0.5f,  0.5f,

				-0.5f,  0.5f, -0.5f,
				-0.5f, -0.5f, -0.5f,
				-0.5f, -0.5f,  0.5f,
				-0.5f,  0.5f,  0.5f,

				-0.5f,  0.5f,  0.5f,
				-0.5f,  0.5f, -0.5f,
				0.5f,  0.5f, -0.5f,
				0.5f,  0.5f,  0.5f,

				-0.5f, -0.5f,  0.5f,
				-0.5f, -0.5f, -0.5f,
				0.5f, -0.5f, -0.5f,
				0.5f, -0.5f,  0.5f
			};

			float textureCoords[] = {
				0, 0,
				0, 1,
				1, 1,
				1, 0,
				0, 0,
				0, 1,
				1, 1,
				1, 0,
				0, 0,
				0, 1,
				1, 1,
				1, 0,
				0, 0,
				0, 1,
				1, 1,
				1, 0,
				0, 0,
				0, 1,
				1, 1,
				1, 0,
				0, 0,
				0, 1,
				1, 1,
				1, 0
			};

			unsigned int indices[] = {
				0, 1, 3,
				3, 1, 2,
				4, 5, 7,
				7, 5, 6,
				8, 9, 11,
				11, 9, 10,
				12, 13, 15,
				15, 13, 14,
				16, 17, 19,
				19, 17, 18,
				20, 21, 23,
				23, 21, 22
			};

			unsigned int verticesCount = 6 * 4 * 3;
			unsigned int textureCoordsCount = 24 * 2;
			unsigned int indicesCount = 12 * 3;

			rawModel = loader->loadToVAO(vertices, verticesCount, textureCoords, textureCoordsCount, indices, indicesCount);

			ModelTexture * modelTexture = new ModelTexture(loader->loadTexture("resources/assets/textures/tiles.png"));
			texturedModel = new TexturedModel(rawModel, modelTexture);
			entity = new Entity(texturedModel, glm::vec3(0, 0, -3), 0, 0, 0, 1);
		}

		void Scene::update(float interval, Window * window)
		{
			entity->increaseRotation(0.001f, 0.001f, 0);
			camera->move(window);
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
			return rawModel;
		}

		TexturedModel * Scene::getTexturedModel()
		{
			return texturedModel;
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
