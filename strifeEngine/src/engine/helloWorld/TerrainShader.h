#pragma once

#include <iostream>
#include "../../engine/tm/shaders/ShaderProgram.h"
#include "../../vendor/glm/glm.hpp"
#include "../../vendor/glm/gtc/matrix_transform.hpp"
#include "../../engine/tm/entities/Light.h"

using namespace engine::tm::shaders;
using namespace engine::tm::entities;

namespace engine
{
	namespace helloWorld
	{
		class TerrainShader : public ShaderProgram
		{
		public:
			TerrainShader(const std::string& vertexFile, const std::string& fragmentFile);
			void bindAttributes();
			void getAllUniformLocations();
			void loadLight(Light * light);
			void loadShineVariables(float shineDamper, float reflectivity);
			virtual ~TerrainShader();
		};
	}
}
