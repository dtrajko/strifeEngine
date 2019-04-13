#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "../../../vendor/glm/glm.hpp"
#include "../../../vendor/glm/gtc/matrix_transform.hpp"
#include "../../../vendor/glm/gtc/type_ptr.hpp"
#include "GL/glew.h"

namespace engine
{
	namespace tm
	{
		namespace shaders
		{
			class ShaderProgram
			{
			protected:
				unsigned int programID;
				unsigned int vertexShaderID;
				unsigned int fragmentShaderID;
				std::unordered_map<std::string, int> uniformLocationCache;

			public:
				ShaderProgram(const std::string & vertexFile, const std::string & fragmentFile);
				void start();
				void stop();
				void cleanUp();
				std::stringstream parseShader(const std::string & filepath);
				unsigned int loadShader(const std::string & file, unsigned int type);
				void bindAttributes();
				void bindAttribute(int attribute, std::string variableName);
				int getUniformLocation(const std::string& name);
				void loadFloat(const std::string & locationName, float value);
				void loadInt(const std::string& locationName, int value);
				void loadBool(const std::string & locationName, bool value);
				void loadVec4f(const std::string& locationName, glm::vec4 vector);
				void loadVec3f(const std::string& locationName, glm::vec3 vector);
				void loadMatrix(const std::string& name, glm::mat4 matrix);
				virtual ~ShaderProgram();
			};
		}
	}
}
