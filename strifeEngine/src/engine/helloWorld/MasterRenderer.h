#pragma once

#include "../interfaces/IMasterRenderer.h"
#include "../interfaces/IScene.h"
#include "../tm/toolbox/Maths.h"
#include "../../engine/tm/entities/Entity.h"
#include "../../vendor/glm/glm.hpp"
#include "../../vendor/glm/gtc/matrix_transform.hpp"
#include "../../engine/helloWorld/EntityRenderer.h"
#include "../../engine/tm/terrains/TerrainRenderer.h"
#include "../../engine/tm/water/WaterRenderer.h"
#include "../../engine/minecraft/skybox/SkyBoxRenderer.h"

using namespace engine::interfaces;
using namespace engine::helloWorld;
using namespace engine::tm::entities;
using namespace engine::tm::toolbox;
using namespace engine::tm::terrains;
using namespace engine::minecraft::skybox;

namespace engine
{
	namespace helloWorld
	{
		class MasterRenderer : public IMasterRenderer
		{
		private:
			float RED   = 0.53f;
			float GREEN = 0.81f;
			float BLUE  = 0.98f;
			glm::mat4 m_ProjectionMatrix;
			glm::mat4 m_ViewMatrix;
			glm::mat4 m_TransformationMatrix;

			EntityRenderer * m_EntityRenderer;
			TerrainRenderer * m_TerrainRenderer;
			WaterRenderer * m_WaterRenderer;
			SkyBoxRenderer * m_SkyBoxRenderer;

		public:
			MasterRenderer(Window * window);
			void init(IScene * scene);
			glm::mat4 createProjectionMatrix(Window * window);
			glm::mat4 getProjectionMatrix(Window * window);
			void prepare(Window * window);
			void render(Window * window, IScene * scene);
			static void enableCulling();
			static void disableCulling();
			void cleanUp();
			virtual ~MasterRenderer();
		};
	}
}
