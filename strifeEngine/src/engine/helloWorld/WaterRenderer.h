#ifndef _WATER_RENDERER_H
#define _WATER_RENDERER_H

#include "../../vendor/glm/glm.hpp"
#include "../../vendor/glm/gtc/matrix_transform.hpp"
#include "../../engine/interfaces/IScene.h"
#include "../../engine/interfaces/IRenderer.h"
#include "../../engine/helloWorld/WaterShader.h"
#include "../../engine/tm/water/WaterTile.h"
#include "../../engine/tm/toolbox/Maths.h"
#include "../../engine/utils/Log.h"

using namespace engine::interfaces;
using namespace engine::utils;
using namespace engine::tm::toolbox;
using namespace engine::tm::water;

namespace engine
{
	namespace helloWorld
	{
		class WaterRenderer : public IRenderer
		{
		private:
			const std::string m_VertexFile = "resources/shaders/waterVertex.glsl";
			const std::string m_FragmentFile = "resources/shaders/waterFragment.glsl";
			WaterShader * m_Shader;
			glm::mat4 m_ProjectionMatrix;
			glm::mat4 m_ViewMatrix;
			glm::mat4 m_TransformationMatrix;

		public:
			WaterRenderer(Window * window, glm::mat4 projectionMatrix);
			glm::mat4 getProjectionMatrix(Window * window);
			void init(IScene * scene);
			void prepare(Window * window);
			void render(Window * window, IScene * scene, glm::mat4 & viewMatrix);
			void renderWaterTile(WaterTile * waterTile, IScene * scene);
			void cleanUp();
			virtual ~WaterRenderer();
		};
	}
}

#endif
