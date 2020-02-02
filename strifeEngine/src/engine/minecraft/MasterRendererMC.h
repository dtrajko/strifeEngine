#pragma once

#include "../interfaces/IMasterRenderer.h"
#include "../interfaces/IScene.h"
#include "../tm/toolbox/Maths.h"
#include "../../engine/tm/entities/Entity.h"
#include "../../engine/minecraft/skybox/SkyBoxRenderer.h"

#include "../../vendor/glm/glm.hpp"
#include "../../vendor/glm/gtc/matrix_transform.hpp"

using namespace engine::interfaces;
using namespace engine::tm::entities;
using namespace engine::tm::toolbox;
using namespace engine::minecraft::skybox;

namespace engine
{
	namespace minecraft
	{
		class MasterRendererMC : public IMasterRenderer
		{
		private:
			float RED   = 0.53f;
			float GREEN = 0.81f;
			float BLUE  = 0.98f;
			glm::mat4 m_ProjectionMatrix;
			glm::mat4 m_ViewMatrix;
			glm::mat4 m_TransformationMatrix;

			SkyBoxRenderer * m_SkyBoxRenderer;

		public:
			MasterRendererMC(Window * window);
			void init(IScene * scene);
			glm::mat4 createProjectionMatrix(Window * window);
			glm::mat4 getProjectionMatrix(Window * window);
			void prepare(Window * window);
			void render(Window * window, IScene * scene);
			static void enableCulling();
			static void disableCulling();
			void cleanUp();
			virtual ~MasterRendererMC();
		};
	}
}
