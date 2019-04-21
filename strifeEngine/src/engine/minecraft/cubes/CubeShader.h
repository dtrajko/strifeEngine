#ifndef _CUBE_SHADER_H
#define _CUBE_SHADER_H

#include <iostream>
#include "../../../vendor/glm/glm.hpp"
#include "../../../vendor/glm/gtc/matrix_transform.hpp"
#include "../../../engine/tm/shaders/ShaderProgram.h"
#include "../../../engine/tm/entities/Light.h"

using namespace engine::tm::shaders;
using namespace engine::tm::entities;

namespace engine { namespace minecraft { namespace cubes {

	class CubeShader : public ShaderProgram
	{
	public:
		CubeShader(const std::string& vertexFile, const std::string& fragmentFile);
		virtual ~CubeShader();
	};

} } }

#endif
