#include "SceneHelloWorld.h"

namespace engine
{
	namespace helloWorld
	{
		SceneHelloWorld::SceneHelloWorld()
		{

		}

		void SceneHelloWorld::init(Window * window)
		{
			masterRenderer = new MasterRendererHelloWorld(window);
			camera = new Camera();
			loader = new Loader();
			CubeMeshSimple * cubeMesh = new CubeMeshSimple();
			ModelTexture * texture = new ModelTexture(loader->loadTexture("resources/assets/textures/tiles.png"));
			RawModel * model = loader->loadToVAO(
				cubeMesh->vertices, cubeMesh->verticesCount,
				cubeMesh->textureCoords, cubeMesh->textureCoordsCount,
				cubeMesh->indices, cubeMesh->indicesCount);
			TexturedModel * texturedModel = new TexturedModel(model, texture);
			entity = new Entity(texturedModel, glm::vec3(0, -1.0f, 0), 0, 0, 0, 1);
		}

		void SceneHelloWorld::update(float interval, Input * input)
		{
			entity->setRotation(entity->getRotX(), entity->getRotY() + 0.1f, entity->getRotZ());
		}

		void SceneHelloWorld::render(Window * window)
		{
			masterRenderer->render(window, this);
		}

		Entity * SceneHelloWorld::getEntity()
		{
			return entity;
		}

		void SceneHelloWorld::cleanUp()
		{
			loader->cleanUp();
			masterRenderer->cleanUp();
		}

		ICamera * SceneHelloWorld::getCamera()
		{
			return camera;
		}

		Loader * SceneHelloWorld::getLoader()
		{
			return loader;
		}

		SceneHelloWorld::~SceneHelloWorld()
		{

		}
	}
}
