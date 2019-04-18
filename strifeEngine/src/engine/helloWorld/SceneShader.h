#ifndef _SCENE_SHADER_H
#define _SCENE_SHADER_H

#include <iostream>
#include "../../engine/tm/shaders/ShaderProgram.h"
#include "../../vendor/glm/glm.hpp"
#include "../../vendor/glm/gtc/matrix_transform.hpp"
#include "../../engine/tm/entities/Light.h"

using namespace engine::tm::shaders;
using namespace engine::tm::entities;

namespace engine { namespace helloWorld {

	class SceneShader : public ShaderProgram
	{
	public:
		SceneShader(const std::string& vertexFile, const std::string& fragmentFile);
		virtual ~SceneShader();
	};

} }

#endif
