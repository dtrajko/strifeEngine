#pragma once

#include "../../engine/interfaces/IScene.h"
#include "../helloWorld/MasterRenderer.h"
#include "../interfaces/IMasterRenderer.h"
#include "../tm/textures/ModelTexture.h"
#include "../tm/models/CubeMeshSimple.h"
#include "../tm/models/QuadMeshSimple.h"
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
		class Scene : public IScene
		{
		private:
			Loader * loader;
			ICamera * camera;
			IMasterRenderer * masterRenderer;
			Entity * entity;
			RawModel * rawModel;
			TexturedModel * texturedModel;

		public:
			Scene();
			void init(Window * window);
			void update(float interval, Window * window, Input * input);
			void render(Window * window);
			ICamera * getCamera();
			Loader * getLoader();
			Entity * getEntity();
			RawModel * getModel();
			TexturedModel * getTexturedModel();
			void cleanUp();
			virtual ~Scene();
		};
	}
}