#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "../../../vendor/glm/glm.hpp"
#include "../../../vendor/glm/gtc/matrix_transform.hpp"
#include "../../../vendor/glm/gtc/type_ptr.hpp"

namespace engine
{
	namespace tm
	{
		namespace shaders
		{
			class ShaderProgram
			{
			private:
				unsigned int programID;
				unsigned int vertexShaderID;
				unsigned int fragmentShaderID;
				std::unordered_map<std::string, int> uniformLocationCache;

			public:
				ShaderProgram(std::string & vertexFile, std::string & fragmentFile);
				void start();
				void stop();
				void cleanUp();
				std::stringstream parseShader(const std::string & filepath);
				unsigned int loadShader(std::string & file, unsigned int type);
				void bindAttributes();
				void bindAttribute(int attribute, std::string variableName);
				void getAllUniformLocations();
				int getUniformLocation(const std::string& name);
				void loadFloat(const std::string & locationName, float value);
				void loadInt(const std::string& locationName, int value);
				void loadVector(const std::string& locationName, glm::vec4 vector);
				void loadMatrix(const std::string& name, glm::mat4 matrix);
				virtual ~ShaderProgram();
			};
		}
	}
}