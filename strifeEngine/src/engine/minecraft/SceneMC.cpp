#include "SceneMC.h"


namespace engine
{
	namespace minecraft
	{
		SceneMC::SceneMC(Window * window)
		{
			init(window);
		}

		void SceneMC::init(Window * window)
		{
			m_Camera = new Camera();
			m_Camera->setPosition(0.0f, 60.0f, 180.0f);
			m_Camera->setRotation(0.0f, 0.0f, 0.0f);
			m_Light = new Light(glm::vec3(2000, 2000, 2000), glm::vec3(1, 1, 1));
			m_MasterRenderer = new MasterRendererMC(window);
			m_Loader = new Loader();

			m_SkyBox = new SkyBox("resources/Minecraft/models/skybox.obj", "resources/Minecraft/textures/skybox_desert.png", m_Loader);
			m_SkyBox->setScale(glm::vec3(680.0f));
			m_SkyBox->setPosition(0.0f, 0.0f, 0.0f);

			// TexturedModel for AABB entities (bounding boxes)
			CubeMeshSimple meshCubeAABB = CubeMeshSimple();
			RawModel* rawModelMeshCubeAABB = m_Loader->loadToVAO(meshCubeAABB.getVertices(), meshCubeAABB.getVerticesCount(),
				meshCubeAABB.getTextureCoords(), meshCubeAABB.getTextureCoordsCount(),
				meshCubeAABB.getIndices(), meshCubeAABB.getIndicesCount());
			ModelTexture* modelTextureAABB = new ModelTexture(m_Loader->loadTexture("resources/Minecraft/textures/AABB.png"));
			TexturedModel* texturedModelAABB = new TexturedModel(rawModelMeshCubeAABB, modelTextureAABB);

			CubeMeshSimple meshCube = CubeMeshSimple();
			RawModel * rawModelMeshCube = m_Loader->loadToVAO(meshCube.getVertices(), meshCube.getVerticesCount(),
				meshCube.getTextureCoords(), meshCube.getTextureCoordsCount(),
				meshCube.getIndices(), meshCube.getIndicesCount());
			ModelTexture * modelTextureTiles = new ModelTexture(m_Loader->loadTexture("resources/assets/textures/tiles.png"));
			TexturedModel * texturedModelTiles = new TexturedModel(rawModelMeshCube, modelTextureTiles);
			Entity * entityCube1 = new Entity(texturedModelTiles, glm::vec3(-80, 40, -80), glm::vec3(0), glm::vec3(10));
			processEntity(entityCube1);
			// set AABB Entity
			Entity* entityAABBCube1 = new Entity(texturedModelAABB, entityCube1->getPosition(), glm::vec3(0), glm::vec3(entityCube1->getScale() *= 1.05f));
			entityCube1->setEntityAABB(entityAABBCube1);
			processEntity(entityCube1->getEntityAABB());

			RawModel * rawModelSphere = OBJLoader::loadOBJModel("resources/Minecraft/models/sphere.obj", m_Loader);
			ModelTexture * modelTextureSphere = new ModelTexture(m_Loader->loadTexture("resources/Minecraft/textures/stairs_texture.png"));
			TexturedModel * texturedModelSphere = new TexturedModel(rawModelSphere, modelTextureSphere);

			m_Player = new Player(texturedModelSphere, glm::vec3(0.0f, 40.0f, 160.0f), glm::vec3(0), glm::vec3(10));
			m_Camera->setPlayer(m_Player);
			processEntity(m_Player);
			// set AABB Entity
			Entity* m_PlayerEntityAABB = new Entity(texturedModelAABB, m_Player->getPosition(), glm::vec3(0), m_Player->getScale());
			m_Player->setEntityAABB(m_PlayerEntityAABB);
			processEntity(m_Player->getEntityAABB());

			std::cout << "Scene rawModel vaoID: " << rawModelMeshCube->getVaoID() << std::endl;
			std::cout << "Scene modelTexture ID: " << modelTextureTiles->getID() << std::endl;
		}

		void SceneMC::update(float interval, Window * window)
		{
			window->getInput()->update();
			m_Player->move(interval, window, getEntities());
			m_Camera->move(window);
			if (window->getInput()->isKeyPressed(GLFW_KEY_ESCAPE))
			{
				window->close();
			}
		}

		void SceneMC::render(Window * window)
		{
			m_MasterRenderer->render(window, this);
		}

		Light * SceneMC::getLight()
		{
			return m_Light;
		}

		SkyBox * SceneMC::getSkyBox()
		{
			return m_SkyBox;
		}

		void SceneMC::processEntity(Entity * entity)
		{
			m_Entities.push_back(entity);
		}

		std::vector<Entity*> SceneMC::getEntities()
		{
			return m_Entities;
		}

		void SceneMC::cleanUp()
		{
			m_Loader->cleanUp();
			m_MasterRenderer->cleanUp();
			m_Entities.clear();
		}

		ICamera * SceneMC::getCamera()
		{
			return m_Camera;
		}

		Loader * SceneMC::getLoader()
		{
			return m_Loader;
		}

		SceneMC::~SceneMC()
		{

		}
	}
}
