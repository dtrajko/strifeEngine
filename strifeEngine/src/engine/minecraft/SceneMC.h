#pragma once

#include <iostream>
#include "../../engine/interfaces/IScene.h"
#include "../../engine/interfaces/IMasterRenderer.h"
#include "../../engine/interfaces/ITerrain.h"
#include "../../engine/graph/Window.h"
#include "../../engine/graph/TextureAtlas.h"
#include "../../engine/graph/Material.h"
#include "../../engine/graph/Mesh.h"
#include "../../engine/minecraft/MasterRendererMC.h"
#include "../../engine/utils/Util.h"
#include "../../engine/tm/models/CubeMeshSimple.h"
#include "../../engine/tm/models/QuadMeshSimple.h"
#include "../../engine/tm/models/RawModel.h"
#include "../../engine/tm/models/TexturedModel.h"
#include "../../engine/tm/entities/Camera.h"
#include "../../engine/tm/entities/Player.h"
#include "../../engine/tm/textures/ModelTexture.h"
#include "../../engine/tm/loaders/OBJLoader.h"
#include "../../engine/minecraft/skybox/SkyBox.h"

using namespace engine::graph;
using namespace engine::interfaces;
using namespace engine::utils;
using namespace engine::tm::loaders;
using namespace engine::tm::models;
using namespace engine::tm::entities;
using namespace engine::tm::textures;
using namespace engine::minecraft;
using namespace engine::minecraft::skybox;


class engine::minecraft::MasterRendererMC;


namespace engine
{
	namespace minecraft
	{
		class SceneMC : public IScene
		{
		private:
			Loader * m_Loader;
			ICamera * m_Camera;
			IMasterRenderer * m_MasterRenderer;
			Light * m_Light;
			std::vector<Entity *> m_Entities;
			SkyBox * m_SkyBox;
			Player * m_Player;

		public:
			SceneMC(Window * window);
			void init(Window * window);
			void update(float interval, Window * window);
			void render(Window * window);
			ICamera * getCamera();
			Loader * getLoader();
			Light * getLight();
			SkyBox * getSkyBox();
			void processEntity(Entity * entity);
			std::vector<Entity *> getEntities();
			void cleanUp();
			virtual ~SceneMC();

			// Inherited via IScene
			virtual std::vector<ITerrain*> getTerrains() override { return std::vector<ITerrain*>(); };
			virtual std::vector<WaterTile*> getWaterTiles() override { return std::vector<WaterTile*>(); };
		};
	}
}
