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
			light = new Light(glm::vec3(0, 10, 0), glm::vec3(1, 1, 1));
			masterRenderer = new MasterRenderer(window);
			loader = new Loader();

			ModelTexture * modelTexture = new ModelTexture(loader->loadTexture("resources/ThinMatrix/textures/normalMaps/barrel.png"));
			modelTexture->setShineDumper(1);
			modelTexture->setReflectivity(0);
			RawModel * rawModel = OBJLoader::loadOBJModel("resources/ThinMatrix/models/barrel.obj", loader);
			TexturedModel * texturedModel = new TexturedModel(rawModel, modelTexture);
			entity = new Entity(texturedModel, glm::vec3(0, -3.0f, -30), 0, 180, 0, 1);

			TerrainTexture * backgroundTexture = new TerrainTexture(loader->loadTexture("resources/ThinMatrix/textures/terrain_1/bg.png"));
			TerrainTexture * rTexture = new TerrainTexture(loader->loadTexture("resources/ThinMatrix/textures/terrain_1/1.png"));
			TerrainTexture * gTexture = new TerrainTexture(loader->loadTexture("resources/ThinMatrix/textures/terrain_1/2.png"));
			TerrainTexture * bTexture = new TerrainTexture(loader->loadTexture("resources/ThinMatrix/textures/terrain_1/3.png"));
			TerrainTexturePack * texturePack = new TerrainTexturePack(backgroundTexture, rTexture, gTexture, bTexture);
			TerrainTexture * blendMap = new TerrainTexture(loader->loadTexture("resources/ThinMatrix/textures/terrain_1/blendMap.png"));
			Terrain * terrain = new Terrain(0.0f, 0.0f, loader, texturePack, blendMap, "resources/ThinMatrix/textures/terrain_1/heightmap");
		}

		void Scene::update(float interval, Window * window)
		{
			camera->move(window);
			if (window->getInput()->isKeyPressed(GLFW_KEY_ESCAPE))
			{
				window->close();
			}
			entityCircularMotion();
		}

		void Scene::entityCircularMotion()
		{
			glm::vec3 posVec = glm::vec3(entity->getPosition());
			posVec.x = glm::sin(counter) * 20;
			posVec.z = glm::cos(counter) * 20;
			counter += 0.001f;
			entity->setPosition(glm::vec3(posVec));
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

		Light * Scene::getLight()
		{
			return light;
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
