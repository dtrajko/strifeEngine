#pragma once

#include "../../engine/interfaces/IScene.h"
#include "../helloWorld/MasterRendererCherno.h"
#include "../interfaces/IMasterRenderer.h"
#include "../tm/textures/ModelTexture.h"
#include "../tm/models/CubeMeshSimple.h"
#include "../tm/models/RawModel.h"
#include "../tm/models/TexturedModel.h"
#include "../tm/entities/Camera.h"

using namespace engine::interfaces;
using namespace engine::graph;
using namespace engine::tm::textures;
using namespace engine::tm::models;
using namespace engine::tm::entities;

namespace engine
{
	namespace helloWorld
	{
		class SceneCherno : public IScene
		{
		private:
			Loader * loader;
			ICamera * camera;
			IMasterRenderer * masterRenderer;
			Entity * entity;

		public:
			SceneCherno();
			void init(Window * window);
			void update(float interval, Input * input);
			void render(Window * window);
			ICamera * getCamera();
			Loader * getLoader();
			Entity * getEntity();
			void cleanUp();
			virtual ~SceneCherno();
		};
	}
}
