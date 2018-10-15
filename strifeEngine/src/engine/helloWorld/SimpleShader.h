#pragma once

#include "../../engine/tm/shaders/ShaderProgram.h"

using namespace engine::tm::shaders;

namespace engine
{
	namespace helloWorld
	{
		class SimpleShader : public ShaderProgram
		{
		public:
			SimpleShader();
			virtual ~SimpleShader();
		};
	}
}
