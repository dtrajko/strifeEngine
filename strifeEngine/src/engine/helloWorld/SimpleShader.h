#pragma once

#include "../../engine/tm/shaders/ShaderProgram.h"

using namespace engine::tm::shaders;

namespace engine
{
	namespace helloWorld
	{
		class SimpleShader : public ShaderProgram
		{
		private:
			int location_transformationMatrix;
			int location_projectionMatrix;
			int location_viewMatrix;

		public:
			SimpleShader(std::string& vertexFile, std::string& fragmentFile);
			virtual ~SimpleShader();
		};
	}
}
