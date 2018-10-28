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
			m_Light = new Light(glm::vec3(-20, 10, -20), glm::vec3(1, 1, 1));
			m_MasterRenderer = new MasterRenderer(window);
			m_Loader = new Loader();

			ModelTexture * modelTexture = new ModelTexture(m_Loader->loadTexture("resources/ThinMatrix/textures/normalMaps/barrel.png"));
			// ModelTexture * modelTexture = new ModelTexture(m_Loader->loadTexture("resources/ThinMatrix/textures/dragon.png"));
			modelTexture->setShineDumper(10);
			modelTexture->setReflectivity(1);

			std::cout << "BEFORE OBJLoader::loadOBJModel() " << Util::printTime() << std::endl;
			RawModel * rawModel = OBJLoader::loadOBJModel("resources/ThinMatrix/models/barrel.obj", m_Loader); // barrel, dragon
			std::cout << "AFTER OBJLoader::loadOBJModel() " << Util::printTime() << std::endl;

			TexturedModel * texturedModel = new TexturedModel(rawModel, modelTexture);
			m_Entity = new Entity(texturedModel, glm::vec3(0.0f, 0.0f, -40.0f), 0, 180, 0, 1);
		}

		void Scene::update(float interval, Window * window)
		{
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
			m_Entity->increaseRotation(0, 0.1f, 0);
			glm::vec3 posVec = glm::vec3(m_Entity->getPosition());
			posVec.x = initVec.x + glm::sin(m_Counter) * 5;
			posVec.z = initVec.z + glm::cos(m_Counter) * 5;
			m_Counter += 0.001f;
			m_Entity->setPosition(glm::vec3(posVec));
		}

		void Scene::render(Window * window)
		{
			m_MasterRenderer->render(window, this);
		}

		Entity * Scene::getEntity()
		{
			return m_Entity;
		}

		RawModel * Scene::getModel()
		{
			return m_RawModel;
		}

		Light * Scene::getLight()
		{
			return m_Light;
		}

		TexturedModel * Scene::getTexturedModel()
		{
			return m_TexturedModel;
		}

		std::vector<ITerrain *> Scene::getTerrains()
		{
			return m_Terrains;
		}

		void Scene::cleanUp()
		{
			m_Loader->cleanUp();
			m_MasterRenderer->cleanUp();
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
