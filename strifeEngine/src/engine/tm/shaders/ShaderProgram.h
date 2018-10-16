#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

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

			public:
				ShaderProgram(std::string & vertexFile, std::string & fragmentFile);
				std::stringstream parseShader(const std::string & filepath);
				unsigned int loadShader(std::string & file, unsigned int type);
				void bindAttributes();
				void getAllUniformLocations();
				void bindAttribute(int attribute, std::string variableName);
				virtual ~ShaderProgram();
			};
		}
	}
}
