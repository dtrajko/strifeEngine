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
			// temporary
			sprite = new Sprite("resources/assets/art/fortnite.png", 350, 100);

			Loader * loader = new Loader();
			CubeMeshSimple * cubeMesh = new CubeMeshSimple();
			ModelTexture * texture = new ModelTexture(loader->loadTexture("resources/assets/textures/tiles.png"));
			RawModel * model = loader->loadToVAO(cubeMesh->vertices, cubeMesh->textureCoords, cubeMesh->indices);
			TexturedModel * texturedModel = new TexturedModel(model, texture);
			entity = new Entity(texturedModel, glm::vec3(0, -0.8f, -5), 0, 0, 0, 1);
		}

		void SceneHelloWorld::update(float interval, Input * input)
		{
			sprite->update();
		}

		void SceneHelloWorld::render(Window * window)
		{
			masterRenderer->render(window, this);
		}

		Entity * SceneHelloWorld::getEntity()
		{
			return entity;
		}

		/* a temporary method */
		Sprite * SceneHelloWorld::getSprite()
		{
			return sprite;
		}

		void SceneHelloWorld::cleanUp()
		{

		}

		ICamera * SceneHelloWorld::getCamera()
		{
			return camera;
		}

		Loader SceneHelloWorld::getLoader()
		{
			return Loader();
		}

		SceneHelloWorld::~SceneHelloWorld()
		{

		}
	}
}
