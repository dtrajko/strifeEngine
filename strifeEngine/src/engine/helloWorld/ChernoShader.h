#pragma once

#include "../../engine/tm/shaders/ShaderProgram.h"
#include "../../vendor/glm/glm.hpp"
#include "../../vendor/glm/gtc/matrix_transform.hpp"

using namespace engine::tm::shaders;

namespace engine
{
	namespace helloWorld
	{
		class ChernoShader : public ShaderProgram
		{
		public:
			ChernoShader(std::string& vertexFile, std::string& fragmentFile);
			virtual ~ChernoShader();
		};
	}
}
