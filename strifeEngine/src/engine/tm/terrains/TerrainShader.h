#pragma once

#include <iostream>
#include "../../../vendor/glm/glm.hpp"
#include "../../../vendor/glm/gtc/matrix_transform.hpp"
#include "../../../engine/tm/shaders/ShaderProgram.h"
#include "../../../engine/tm/entities/Light.h"

using namespace engine::tm::shaders;
using namespace engine::tm::entities;

namespace engine { namespace tm { namespace terrains {

	class TerrainShader : public ShaderProgram
	{
	public:
		TerrainShader(const std::string& vertexFile, const std::string& fragmentFile);
		void bindAttributes();
		void loadClipPlane(glm::vec4 clipPlane);
		void loadLight(Light * light);
		void loadShineVariables(float shineDamper, float reflectivity);
		virtual ~TerrainShader();
	};

} } }
