#pragma once

#include <iostream>
#include "../../engine/interfaces/IScene.h"
#include "../helloWorld/MasterRenderer.h"
#include "../interfaces/IMasterRenderer.h"
#include "../tm/textures/ModelTexture.h"
#include "../tm/models/CubeMeshSimple.h"
#include "../tm/models/QuadMeshSimple.h"
#include "../tm/models/RawModel.h"
#include "../tm/models/TexturedModel.h"
#include "../tm/entities/Camera.h"
#include "../graph/Window.h"
#include "../tm/loaders/OBJLoader.h"
#include "../../engine/utils/Util.h"

using namespace engine::interfaces;
using namespace engine::graph;
using namespace engine::tm::textures;
using namespace engine::tm::models;
using namespace engine::tm::entities;
using namespace engine::tm::loaders;
using namespace engine::utils;

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
			Light * light;
			TexturedModel * texturedModel;

			float counter = 0;

		public:
			Scene(Window * window);
			void init(Window * window);
			void update(float interval, Window * window);
			void entityCircularMotion();
			void render(Window * window);
			ICamera * getCamera();
			Loader * getLoader();
			Entity * getEntity();
			RawModel * getModel();
			Light * getLight();
			TexturedModel * getTexturedModel();
			void cleanUp();
			virtual ~Scene();
		};
	}
}
