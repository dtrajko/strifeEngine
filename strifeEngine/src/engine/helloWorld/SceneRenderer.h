#ifndef _SCENE_RENDERER_H
#define _SCENE_RENDERER_H

#include "../interfaces/IRenderer.h"
#include "../interfaces/IScene.h"
#include "../helloWorld/SceneShader.h"
#include "../tm/toolbox/Maths.h"
#include "../../vendor/glm/glm.hpp"
#include "../../vendor/glm/gtc/matrix_transform.hpp"

using namespace engine::interfaces;
using namespace engine::helloWorld;
using namespace engine::tm::toolbox;

namespace engine
{
	namespace helloWorld
	{
		class SceneRenderer : public IRenderer
		{
		private:
			const std::string m_VertexFile = "resources/shaders/sceneVertex.glsl";
			const std::string m_FragmentFile = "resources/shaders/sceneFragment.glsl";
			SceneShader * m_Shader;
			glm::mat4 m_ProjectionMatrix;
			glm::mat4 m_ViewMatrix;
			glm::mat4 m_TransformationMatrix;

		public:
			SceneRenderer(Window * window, glm::mat4 projectionMatrix);
			glm::mat4 getProjectionMatrix(Window * window);
			void init(IScene * scene);
			void prepare(Window * window);
			void render(Window * window, IScene * scene, glm::mat4 & viewMatrix, glm::vec4 clipPlane);
			void renderModel();
			void cleanUp();
			virtual ~SceneRenderer();
		};
	}
}

#endif
