#pragma once

#include "../../engine/tm/shaders/ShaderProgram.h"
#include "../../vendor/glm/glm.hpp"
#include "../../vendor/glm/gtc/matrix_transform.hpp"

using namespace engine::tm::shaders;

namespace engine
{
	namespace helloWorld
	{
		class ThinMatrixShader : public ShaderProgram
		{
		public:
			ThinMatrixShader(std::string& vertexFile, std::string& fragmentFile);
			virtual ~ThinMatrixShader();
		};
	}
}
