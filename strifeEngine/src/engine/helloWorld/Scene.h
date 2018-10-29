#pragma once

#include <iostream>
#include "../../engine/interfaces/IScene.h"
#include "../../engine/interfaces/IMasterRenderer.h"
#include "../../engine/interfaces/ITerrain.h"
#include "../../engine/graph/Window.h"
#include "../../engine/helloWorld/MasterRenderer.h"
#include "../../engine/utils/Util.h"
#include "../../engine/tm/models/CubeMeshSimple.h"
#include "../../engine/tm/models/QuadMeshSimple.h"
#include "../../engine/tm/models/RawModel.h"
#include "../../engine/tm/models/TexturedModel.h"
#include "../../engine/tm/entities/Camera.h"
#include "../../engine/tm/textures/ModelTexture.h"
#include "../../engine/tm/loaders/OBJLoader.h"
#include "../../engine/tm/terrains/Terrain.h"

using namespace engine::graph;
using namespace engine::interfaces;
using namespace engine::utils;
using namespace engine::tm::loaders;
using namespace engine::tm::models;
using namespace engine::tm::entities;
using namespace engine::tm::textures;
using namespace engine::tm::terrains;

namespace engine
{
	namespace helloWorld
	{
		class Scene : public IScene
		{
		private:
			Loader * m_Loader;
			ICamera * m_Camera;
			IMasterRenderer * m_MasterRenderer;
			Light * m_Light;
			std::vector<Entity *> m_Entities;
			std::vector<ITerrain *> m_Terrains;
			float m_Counter = 0;

		public:
			Scene(Window * window);
			void init(Window * window);
			void update(float interval, Window * window);
			void entityCircularMotion();
			void render(Window * window);
			ICamera * getCamera();
			Loader * getLoader();
			Light * getLight();
			void processEntity(Entity * entity);
			void processTerrain(ITerrain * terrain);
			std::vector<Entity *> getEntities();
			std::vector<ITerrain *> getTerrains();
			void cleanUp();
			virtual ~Scene();
		};
	}
}
