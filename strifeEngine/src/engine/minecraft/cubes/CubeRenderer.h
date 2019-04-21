#ifndef _CUBE_RENDERER_H
#define _CUBE_RENDERER_H

#include "../../interfaces/IRenderer.h"
#include "../../interfaces/IScene.h"
#include "../../minecraft/cubes/CubeShader.h"
#include "../../tm/toolbox/Maths.h"
#include "../../../vendor/glm/glm.hpp"
#include "../../../vendor/glm/gtc/matrix_transform.hpp"

using namespace engine::interfaces;
using namespace engine::minecraft::cubes;
using namespace engine::tm::toolbox;

namespace engine { namespace minecraft { namespace cubes {

	class CubeRenderer : public IRenderer
	{
	private:
		const std::string m_VertexFile = "resources/shaders/cubeVertex.glsl";
		const std::string m_FragmentFile = "resources/shaders/cubeFragment.glsl";
		CubeShader * m_Shader;
		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_TransformationMatrix;

	public:
		CubeRenderer(Window * window, glm::mat4 projectionMatrix);
		glm::mat4 getProjectionMatrix(Window * window);
		void init(IScene * scene);
		void prepare(Window * window);
		void render(Window * window, IScene * scene, glm::mat4 & viewMatrix, glm::vec4 clipPlane);
		void renderModel();
		void cleanUp();
		virtual ~CubeRenderer();
	};

} } }
#endif
