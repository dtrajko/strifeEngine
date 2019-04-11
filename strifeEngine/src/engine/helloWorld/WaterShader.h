#ifndef _WATER_SHADER_H
#define _WATER_SHADER_H

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
		class WaterShader : public ShaderProgram
		{
		public:
			WaterShader(const std::string& vertexFile, const std::string& fragmentFile);
			void bindAttributes();
			void getAllUniformLocations();
			void loadLight(Light * light);
			void loadShineVariables(float shineDamper, float reflectivity);
			virtual ~WaterShader();
		};
	}
}

#endif
