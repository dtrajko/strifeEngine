#ifndef _TERRAIN_RENDERER_H
#define _TERRAIN_RENDERER_H

#include "../../vendor/glm/glm.hpp"
#include "../../vendor/glm/gtc/matrix_transform.hpp"
#include "../../engine/interfaces/IScene.h"
#include "../../engine/interfaces/IRenderer.h"
#include "../../engine/interfaces/ITerrain.h"
#include "../../engine/helloWorld/TerrainShader.h"
#include "../../engine/tm/toolbox/Maths.h"
#include "../../engine/tm/terrains/Terrain.h"
#include "../../engine/utils/Log.h"

using namespace engine::interfaces;
using namespace engine::utils;
using namespace engine::tm::toolbox;
using namespace engine::tm::terrains;

namespace engine
{
	namespace helloWorld
	{
		class TerrainRenderer : public IRenderer
		{
		private:
			const std::string m_VertexFile = "resources/shaders/terrainVertex.glsl";
			const std::string m_FragmentFile = "resources/shaders/terrainFragment.glsl";
			TerrainShader * m_Shader;
			glm::mat4 m_ProjectionMatrix;
			glm::mat4 m_ViewMatrix;
			glm::mat4 m_TransformationMatrix;

		public:
			TerrainRenderer(Window * window, glm::mat4 projectionMatrix);
			glm::mat4 getProjectionMatrix(Window * window);
			void init(IScene * scene);
			void prepare(Window * window);
			void render(Window * window, IScene * scene, glm::mat4 & viewMatrix, glm::vec4 clipPlane);
			void renderTerrain(ITerrain * terrain, IScene * scene);
			void cleanUp();
			virtual ~TerrainRenderer();
		};
	}
}

#endif
