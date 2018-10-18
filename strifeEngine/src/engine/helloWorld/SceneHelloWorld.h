#pragma once

#include "../../engine/interfaces/IScene.h"
#include "../helloWorld/MasterRendererHelloWorld.h"
#include "../interfaces/IMasterRenderer.h"
#include "../../engine/graph/Sprite.h"
#include "../tm/textures/ModelTexture.h"
#include "../tm/models/CubeMeshSimple.h"
#include "../tm/models/RawModel.h"
#include "../tm/models/TexturedModel.h"

using namespace engine::interfaces;
using namespace engine::graph;
using namespace engine::tm::textures;
using namespace engine::tm::models;

namespace engine
{
	namespace helloWorld
	{
		class SceneHelloWorld : public IScene
		{
		private:
			ICamera * camera;
			IMasterRenderer * masterRenderer;
			// temporary
			Sprite * sprite;
			Entity * entity;
		public:
			SceneHelloWorld();
			void init(Window * window);
			void update(float interval, Input * input);
			void render(Window * window);
			ICamera * getCamera();
			Loader getLoader();
			Entity * getEntity();
			Sprite * getSprite(); // temporary
			void cleanUp();
			virtual ~SceneHelloWorld();
		};
	}
}
