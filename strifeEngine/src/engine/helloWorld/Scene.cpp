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

			// QuadMeshSimple mesh = QuadMeshSimple();
			CubeMeshSimple mesh = CubeMeshSimple();

			rawModel = loader->loadToVAO(mesh.vertices, mesh.verticesCount, mesh.textureCoords, mesh.textureCoordsCount, mesh.indices, mesh.indicesCount);

			ModelTexture * modelTexture = new ModelTexture(loader->loadTexture("resources/assets/textures/tiles.png"));
			texturedModel = new TexturedModel(rawModel, modelTexture);
			entity = new Entity(texturedModel, glm::vec3(0, 0, -3), 0, 0, 0, 1);

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
			entity->increaseRotation(0.001f, 0, 0.001f);
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
