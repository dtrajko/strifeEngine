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
			light = new Light(glm::vec3(-20, 10, -20), glm::vec3(1, 1, 1));
			masterRenderer = new MasterRenderer(window);
			loader = new Loader();

			ModelTexture * modelTexture = new ModelTexture(loader->loadTexture("resources/ThinMatrix/textures/normalMaps/barrel.png"));
			// ModelTexture * modelTexture = new ModelTexture(loader->loadTexture("resources/ThinMatrix/textures/dragon.png"));
			modelTexture->setShineDumper(10);
			modelTexture->setReflectivity(1);

			std::cout << "BEFORE OBJLoader::loadOBJModel() " << Util::printTime() << std::endl;
			RawModel * rawModel = OBJLoader::loadOBJModel("resources/ThinMatrix/models/barrel.obj", loader); // barrel, dragon
			std::cout << "AFTER OBJLoader::loadOBJModel() " << Util::printTime() << std::endl;

			TexturedModel * texturedModel = new TexturedModel(rawModel, modelTexture);
			entity = new Entity(texturedModel, glm::vec3(0.0f, 0.0f, -40.0f), 0, 180, 0, 1);
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
			glm::vec3 initVec = glm::vec3(glm::vec3(0.0f, 0.0f, -40.0f));
			entity->increaseRotation(0, 0.1f, 0);
			glm::vec3 posVec = glm::vec3(entity->getPosition());
			posVec.x = initVec.x + glm::sin(counter) * 5;
			posVec.z = initVec.z + glm::cos(counter) * 5;
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
