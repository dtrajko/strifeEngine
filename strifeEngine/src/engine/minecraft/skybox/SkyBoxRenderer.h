#ifndef _SKYBOX_RENDERER_H
#define _SKYBOX_RENDERER_H

#include "../../../engine/interfaces/IRenderer.h"
#include "../../../engine/interfaces/IScene.h"
#include "../../../engine/minecraft/skybox/SkyBox.h"
#include "../../../engine/minecraft/skybox/SkyBoxShader.h"
#include "../../../engine/tm/toolbox/Maths.h"
#include "../../../vendor/glm/glm.hpp"
#include "../../../vendor/glm/gtc/matrix_transform.hpp"

using namespace engine::interfaces;
using namespace engine::tm::toolbox;
using namespace engine::minecraft::skybox;

namespace engine { namespace minecraft { namespace skybox {

	class SkyBoxRenderer : public IRenderer
	{
	private:
		const std::string m_VertexFile = "resources/shaders/skyBoxVertex.glsl";
		const std::string m_FragmentFile = "resources/shaders/skyBoxFragment.glsl";
		SkyBoxShader * m_Shader;
		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_TransformationMatrix;

		float rotationOffsetY = 0;

	public:
		SkyBoxRenderer(Window * window, glm::mat4 projectionMatrix);
		glm::mat4 getProjectionMatrix(Window * window);
		void init(IScene * scene);
		void prepare(Window * window);
		void render(Window * window, IScene * scene, glm::mat4 & viewMatrix);
		void render(Window * window, IScene * scene, glm::mat4 & viewMatrix, glm::vec4 clipPlane);
		void renderSkyBox(SkyBox * skyBox);
		void cleanUp();
		virtual ~SkyBoxRenderer();
	};

} } }

#endif
