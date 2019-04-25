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
			m_Camera->setPosition(0.0f, 60.0f, 180.0f);
			m_Camera->setRotation(0.0f, 0.0f, 0.0f);
			m_Light = new Light(glm::vec3(2000, 2000, 2000), glm::vec3(1, 1, 1));
			m_MasterRenderer = new MasterRenderer(window);
			m_Loader = new Loader();

			m_SkyBox = new SkyBox("resources/Minecraft/models/skybox.obj", "resources/Minecraft/textures/skybox_desert.png", m_Loader);
			m_SkyBox->setScale(glm::vec3(680.0f));
			m_SkyBox->setPosition(0.0f, 0.0f, 0.0f);

			ModelTexture * terrainTexture = new ModelTexture(m_Loader->loadTexture("resources/ThinMatrix/textures/terrain_1/2.png"));
			// terrainTexture.setShineDumper(20);
			// terrainTexture.setReflectivity(1);
			ITerrain * terrain = new Terrain(-0.5f, -0.5f, m_Loader, terrainTexture, "resources/ThinMatrix/textures/heightmap.png");
			processTerrain(terrain);

			// TexturedModel for AABB entities (bounding boxes)
			RawModel* rawModelCubeAABB = OBJLoader::loadOBJModel("resources/Minecraft/models/cube.obj", m_Loader);
			ModelTexture* modelTextureTilesAABB = new ModelTexture(m_Loader->loadTexture("resources/Minecraft/textures/AABB.png"));
			TexturedModel* texturedModelTilesAABB = new TexturedModel(rawModelCubeAABB, modelTextureTilesAABB);

			ModelTexture * modelTextureBarrel = new ModelTexture(m_Loader->loadTexture("resources/ThinMatrix/textures/normalMaps/barrel.png"));
			modelTextureBarrel->setShineDumper(10);
			modelTextureBarrel->setReflectivity(1);
			RawModel * rawModelBarrel = OBJLoader::loadOBJModel("resources/ThinMatrix/models/barrel.obj", m_Loader);
			TexturedModel * texturedModelBarrel = new TexturedModel(rawModelBarrel, modelTextureBarrel);
			Entity * entityBarrel = new Entity(texturedModelBarrel, glm::vec3(-40.0f, 20.0f, -40.0f), 0, 0, 0, 2);
			processEntity(entityBarrel);

			CubeMeshSimple meshCube = CubeMeshSimple();
			RawModel * rawModelMeshCube = m_Loader->loadToVAO(meshCube.getVertices(), meshCube.getVerticesCount(),
				meshCube.getTextureCoords(), meshCube.getTextureCoordsCount(),
				meshCube.getIndices(), meshCube.getIndicesCount());
			ModelTexture * modelTextureTiles = new ModelTexture(m_Loader->loadTexture("resources/assets/textures/tiles.png"));
			TexturedModel * texturedModelTiles = new TexturedModel(rawModelMeshCube, modelTextureTiles);
			Entity * entityCube1 = new Entity(texturedModelTiles, glm::vec3(-80, 40, -80), 0, 0, 0, 20);
			processEntity(entityCube1);
			// set AABB Entity
			Entity* entityAABBCube1 = new Entity(texturedModelTilesAABB, entityCube1->getPosition(), 0, 0, 0, entityCube1->getScale() * 0.54f);
			entityCube1->setEntityAABB(entityAABBCube1);
			processEntity(entityCube1->getEntityAABB());

			Entity * entityCube2 = new Entity(texturedModelTiles, glm::vec3(20.0f, 0.0f, -40.0f), 0, 0, 0, 20);
			processEntity(entityCube2);
			// set AABB Entity
			Entity* entityAABBCube2 = new Entity(texturedModelTilesAABB, entityCube2->getPosition(), 0, 0, 0, entityCube2->getScale() * 0.54f);
			entityCube2->setEntityAABB(entityAABBCube2);
			processEntity(entityCube2->getEntityAABB());

			QuadMeshSimple meshQuad = QuadMeshSimple();
			RawModel * rawModelQuad = m_Loader->loadToVAO(meshQuad.getVertices(), meshQuad.getVerticesCount(),
				meshQuad.getTextureCoords(), meshQuad.getTextureCoordsCount(),
				meshQuad.getIndices(), meshQuad.getIndicesCount());
			modelTextureTiles = new ModelTexture(m_Loader->loadTexture("resources/assets/textures/tiles.png"));
			texturedModelTiles = new TexturedModel(rawModelQuad, modelTextureTiles);
			Entity * entityQuad = new Entity(texturedModelTiles, glm::vec3(-80, 60, -80), 60, 0, 0, 40);
			processEntity(entityQuad);

			ModelTexture * modelTextureFern = new ModelTexture(m_Loader->loadTexture("resources/ThinMatrix/textures/fern.png"));
			modelTextureFern->setTransparency(1);
			RawModel * rawModelFern = OBJLoader::loadOBJModel("resources/ThinMatrix/models/fern.obj", m_Loader);
			TexturedModel * texturedModelFern = new TexturedModel(rawModelFern, modelTextureFern);
			Entity * entityFern = new Entity(texturedModelFern, glm::vec3(60.0f, 10.0f, 00.0f), 0, 0, 0, 2);
			processEntity(entityFern);

			ModelTexture * fernTextureAtlas = new ModelTexture(m_Loader->loadTexture("resources/ThinMatrix/textures/fern_atlas.png"));
			fernTextureAtlas->setNumberOfRows(2);
			fernTextureAtlas->setTransparency(true);
			fernTextureAtlas->setUsesFakeLighting(true);
			TexturedModel * fernModel = new TexturedModel(OBJLoader::loadOBJModel("fern", m_Loader), fernTextureAtlas);
			Entity * entityFernTexAtlas = new Entity(fernModel, 0, glm::vec3(-80.0f, 20.0f, -40.0f), 0, 0, 0, 2);
			processEntity(entityFernTexAtlas);

			ModelTexture * modelTexturePine = new ModelTexture(m_Loader->loadTexture("resources/ThinMatrix/textures/pine.png"));
			modelTexturePine->setTransparency(1);
			RawModel * rawModelPine = OBJLoader::loadOBJModel("resources/ThinMatrix/models/pine.obj", m_Loader);
			texturedModelTiles = new TexturedModel(rawModelPine, modelTexturePine);
			Entity * entityPine = new Entity(texturedModelTiles, glm::vec3(155.0f, 10.0f, -140.0f), 0, 0, 0, 4);
			processEntity(entityPine);
			// set AABB Entity
			glm::vec3 entityPinePositionAABB = glm::vec3(entityPine->getPosition().x, entityPine->getPosition().y + 38, entityPine->getPosition().z);
			Entity* entityAABBPine = new Entity(texturedModelTilesAABB, entityPinePositionAABB, 0, 0, 0, glm::vec3(5, 38, 5));
			entityPine->setEntityAABB(entityAABBPine);
			processEntity(entityPine->getEntityAABB());

			// Mesh * meshCobble = (Mesh *) OBJLoader::loadOBJModel("resources/Minecraft/models/cube.obj", m_Loader);
			// TextureAtlas * textureCobble = new TextureAtlas("resources/Minecraft/textures/terrain_texture_cobble.png", 2, 1);
			// Material * materialCobble = new Material(textureCobble);
			// materialCobble->setReflectance(1.0f);
			// materialCobble->setTransparency(1.0f);
			// meshCobble->setMaterial(materialCobble);

			WaterTile * waterTile = new WaterTile(m_Loader, 0, WaterTile::HEIGHT, 0);
			processWaterTile(waterTile);

			RawModel * rawModelSphere = OBJLoader::loadOBJModel("resources/Minecraft/models/sphere.obj", m_Loader);
			ModelTexture * modelTextureSphere = new ModelTexture(m_Loader->loadTexture("resources/Minecraft/textures/stairs_texture.png"));
			TexturedModel * texturedModelSphere = new TexturedModel(rawModelSphere, modelTextureSphere);

			m_Player = new Player(texturedModelSphere, glm::vec3(0.0f, 40.0f, 160.0f), 0, 0, 0, 10);
			m_Camera->setPlayer(m_Player);
			processEntity(m_Player);
			// set AABB Entity
			Entity* m_PlayerEntityAABB = new Entity(texturedModelTilesAABB, m_Player->getPosition(), 0, 0, 0, m_Player->getScale());
			m_Player->setEntityAABB(m_PlayerEntityAABB);
			processEntity(m_Player->getEntityAABB());

			Entity * entitySphereObject1 = new Entity(texturedModelSphere, glm::vec3(0.0f, 40.0f, 100.0f), 0, 0, 0, 10);
			processEntity(entitySphereObject1);
			// set AABB Entity
			Entity* entityAABBSphereObject1 = new Entity(texturedModelTilesAABB, entitySphereObject1->getPosition(), 0, 0, 0, entitySphereObject1->getScale());
			entitySphereObject1->setEntityAABB(entityAABBSphereObject1);
			processEntity(entitySphereObject1->getEntityAABB());

			Entity * entitySphereObject2 = new Entity(texturedModelSphere, glm::vec3(0.0f, 40.0f, 40.0f), 0, 0, 0, 10);
			processEntity(entitySphereObject2);
			// set AABB Entity
			Entity * entityAABBSphereObject2 = new Entity(texturedModelTilesAABB, entitySphereObject2->getPosition(), 0, 0, 0, entitySphereObject2->getScale());
			entitySphereObject2->setEntityAABB(entityAABBSphereObject2);
			processEntity(entitySphereObject2->getEntityAABB());

			std::cout << "Scene rawModel vaoID: " << rawModelMeshCube->getVaoID() << std::endl;
			std::cout << "Scene modelTexture ID: " << modelTextureTiles->getID() << std::endl;
			std::cout << "Scene terrainTexture ID: " << terrainTexture->getID() << std::endl;
			std::cout << "Scene WaterTile DuDvTexture: " << waterTile->getDuDvTexture() << std::endl;
			std::cout << "Scene WaterTile NormalMap: " << waterTile->getNormalMap() << std::endl;
		}

		void Scene::update(float interval, Window * window)
		{
			window->getInput()->update();
			m_Player->move(interval, window, getEntities());
			m_Camera->move(window);
			if (window->getInput()->isKeyPressed(GLFW_KEY_ESCAPE))
			{
				window->close();
			}
			entityCircularMotion();
		}

		void Scene::entityCircularMotion()
		{
			if (m_Entities.size() == 0) return;

			Entity * entity = m_Entities.at(0);
			entity->increaseRotation(0, 0.1f, 0);
			glm::vec3 initVec = glm::vec3(glm::vec3(-40.0f, 20.0f, -80.0f));
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

		SkyBox * Scene::getSkyBox()
		{
			return m_SkyBox;
		}

		void Scene::processEntity(Entity * entity)
		{
			m_Entities.push_back(entity);
		}

		void Scene::processTerrain(ITerrain * terrain)
		{
			m_Terrains.push_back(terrain);
		}

		void Scene::processWaterTile(WaterTile * waterTile)
		{
			m_WaterTiles.push_back(waterTile);
		}

		std::vector<Entity*> Scene::getEntities()
		{
			return m_Entities;
		}

		std::vector<ITerrain *> Scene::getTerrains()
		{
			return m_Terrains;
		}

		std::vector<WaterTile*> Scene::getWaterTiles()
		{
			return m_WaterTiles;
		}

		void Scene::cleanUp()
		{
			m_Loader->cleanUp();
			m_MasterRenderer->cleanUp();
			m_Entities.clear();
			m_Terrains.clear();
			m_WaterTiles.clear();
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
