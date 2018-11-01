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
			m_Camera = new Camera();
			m_Camera->setPosition(0.0f, 20.0f, 0.0f);
			m_Camera->setRotation(0.0f, 0.0f, 0.0f);
			m_Light = new Light(glm::vec3(2000, 2000, 2000), glm::vec3(1, 1, 1));
			m_MasterRenderer = new MasterRenderer(window);
			m_Loader = new Loader();

			ModelTexture * modelTexture = new ModelTexture(m_Loader->loadTexture("resources/ThinMatrix/textures/normalMaps/barrel.png"));
			modelTexture->setShineDumper(10);
			modelTexture->setReflectivity(1);
			RawModel * rawModel = OBJLoader::loadOBJModel("resources/ThinMatrix/models/barrel.obj", m_Loader);
			TexturedModel * texturedModel = new TexturedModel(rawModel, modelTexture);
			Entity * entity = new Entity(texturedModel, glm::vec3(0.0f, 12.0f, -40.0f), 0, 0, 0, 1);
			processEntity(entity);

			modelTexture = new ModelTexture(m_Loader->loadTexture("resources/ThinMatrix/textures/fern.png"));
			modelTexture->setTransparency(1);
			rawModel = OBJLoader::loadOBJModel("resources/ThinMatrix/models/fern.obj", m_Loader);
			texturedModel = new TexturedModel(rawModel, modelTexture);
			Entity * entityFern = new Entity(texturedModel, glm::vec3(-40.0f, 0.0f, -20.0f), 0, 0, 0, 2);
			processEntity(entityFern);

			modelTexture = new ModelTexture(m_Loader->loadTexture("resources/ThinMatrix/textures/pine.png"));
			modelTexture->setTransparency(1);
			rawModel = OBJLoader::loadOBJModel("resources/ThinMatrix/models/pine.obj", m_Loader);
			texturedModel = new TexturedModel(rawModel, modelTexture);
			Entity * entityPine = new Entity(texturedModel, glm::vec3(40.0f, 0.0f, -180.0f), 0, 0, 0, 4);
			processEntity(entityPine);

			ModelTexture * terrainTexture = new ModelTexture(m_Loader->loadTexture("resources/ThinMatrix/textures/terrain_1/2.png"));
			// terrainTexture->setShineDumper(20);
			// terrainTexture->setReflectivity(1);
			ITerrain * terrain = new Terrain(-0.5f, -0.5f, m_Loader, terrainTexture, "resources/ThinMatrix/textures/heightmap.png");
			processTerrain(terrain);

			std::cout << "Scene rawModel vaoID: " << rawModel->getVaoID() << std::endl;
			std::cout << "Scene modelTexture ID: " << modelTexture->getID() << std::endl;
			std::cout << "Scene terrainTexture ID: " << terrainTexture->getID() << std::endl;
		}

		void Scene::update(float interval, Window * window)
		{
			window->getInput()->update();
			m_Camera->move(window);
			if (window->getInput()->isKeyPressed(GLFW_KEY_ESCAPE))
			{
				window->close();
			}
			entityCircularMotion();
		}

		void Scene::entityCircularMotion()
		{
			glm::vec3 initVec = glm::vec3(glm::vec3(0.0f, 0.0f, -40.0f));
			Entity * entity = m_Entities.at(0);
			entity->increaseRotation(0, 0.1f, 0);
			glm::vec3 posVec = glm::vec3(entity->getPosition());
			posVec.x = initVec.x + glm::sin(m_Counter) * 5;
			posVec.z = initVec.z + glm::cos(m_Counter) * 5;
			m_Counter += 0.001f;
			entity->setPosition(glm::vec3(posVec));
		}

		void Scene::render(Window * window)
		{
			m_MasterRenderer->render(window, this);
		}

		Light * Scene::getLight()
		{
			return m_Light;
		}

		void Scene::processEntity(Entity * entity)
		{
			m_Entities.push_back(entity);
		}

		void Scene::processTerrain(ITerrain * terrain)
		{
			m_Terrains.push_back(terrain);
		}

		std::vector<Entity*> Scene::getEntities()
		{
			return m_Entities;
		}

		std::vector<ITerrain *> Scene::getTerrains()
		{
			return m_Terrains;
		}

		void Scene::cleanUp()
		{
			m_Loader->cleanUp();
			m_MasterRenderer->cleanUp();
			m_Entities.clear();
			m_Terrains.clear();
		}

		ICamera * Scene::getCamera()
		{
			return m_Camera;
		}

		Loader * Scene::getLoader()
		{
			return m_Loader;
		}

		Scene::~Scene()
		{

		}
	}
}
