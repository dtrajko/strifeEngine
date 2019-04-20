#ifndef _SKYBOX_SHADER_H
#define _SKYBOX_SHADER_H

#include <iostream>
#include "../../../engine/tm/shaders/ShaderProgram.h"
#include "../../../vendor/glm/glm.hpp"
#include "../../../vendor/glm/gtc/matrix_transform.hpp"
#include "../../../engine/tm/entities/Light.h"

using namespace engine::tm::shaders;
using namespace engine::tm::entities;

namespace engine { namespace minecraft { namespace skybox {

	class SkyBoxShader : public ShaderProgram
	{
	public:
		SkyBoxShader(const std::string& vertexFile, const std::string& fragmentFile);
		void bindAttributes();
		void connectTextureUnits();
		virtual ~SkyBoxShader();
	};

} } }

#endif
