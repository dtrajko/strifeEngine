#ifndef _ENTITY_RENDERER_H
#define _ENTITY_RENDERER_H

#include "../interfaces/IRenderer.h"
#include "../interfaces/IScene.h"
#include "../helloWorld/EntityShader.h"
#include "../tm/toolbox/Maths.h"
#include "../../engine/tm/entities/Entity.h"
#include "../../vendor/glm/glm.hpp"
#include "../../vendor/glm/gtc/matrix_transform.hpp"

using namespace engine::interfaces;
using namespace engine::helloWorld;
using namespace engine::tm::entities;
using namespace engine::tm::toolbox;

namespace engine
{
	namespace helloWorld
	{
		class EntityRenderer : public IRenderer
		{
		private:
			const std::string m_VertexFile = "resources/shaders/entityVertex.glsl";
			const std::string m_FragmentFile = "resources/shaders/entityFragment.glsl";
			EntityShader * m_Shader;
			glm::mat4 m_ProjectionMatrix;
			glm::mat4 m_ViewMatrix;
			glm::mat4 m_TransformationMatrix;

		public:
			EntityRenderer(Window * window, glm::mat4 projectionMatrix);
			glm::mat4 getProjectionMatrix(Window * window);
			void init(IScene * scene);
			void prepare(Window * window);
			void render(Window * window, IScene * scene, glm::mat4 & viewMatrix);
			void renderModel(Entity * entity);
			void cleanUp();
			virtual ~EntityRenderer();
		};
	}
}

#endif
