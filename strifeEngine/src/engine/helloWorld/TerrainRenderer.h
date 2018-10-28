#ifndef _TERRAIN_RENDERER_H
#define _TERRAIN_RENDERER_H

#include "../interfaces/IRenderer.h"
#include "../interfaces/IScene.h"
#include "../helloWorld/TerrainShader.h"
#include "../tm/toolbox/Maths.h"
#include "../../vendor/glm/glm.hpp"
#include "../../vendor/glm/gtc/matrix_transform.hpp"

using namespace engine::interfaces;
using namespace engine::tm::toolbox;

namespace engine
{
	namespace helloWorld
	{
		class TerrainRenderer : public IRenderer
		{
		private:
			std::string m_VertexFile = "resources/shaders/terrainVertex.glsl";
			std::string m_FragmentFile = "resources/shaders/terrainFragment.glsl";
			TerrainShader * m_Shader;
			glm::mat4 m_ProjectionMatrix;
			glm::mat4 m_ViewMatrix;
			glm::mat4 m_TransformationMatrix;

		public:
			TerrainRenderer(Window * window, glm::mat4 projectionMatrix);
			glm::mat4 getProjectionMatrix(Window * window);
			void init(IScene * scene);
			void prepare(Window * window);
			void render(Window * window, IScene * scene);
			void renderModel(Entity * entity, IScene * scene);
			void cleanUp();
			virtual ~TerrainRenderer();
		};
	}
}

#endif
