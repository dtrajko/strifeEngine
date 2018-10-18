#pragma once

#include "../../engine/tm/shaders/ShaderProgram.h"
#include "../../vendor/glm/glm.hpp"
#include "../../vendor/glm/gtc/matrix_transform.hpp"

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
			void loadProjectionMatrix(glm::mat4 projMatrix);
			virtual ~SimpleShader();
		};
	}
}
