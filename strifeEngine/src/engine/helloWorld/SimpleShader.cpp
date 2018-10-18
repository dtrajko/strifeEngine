#include "SimpleShader.h"

namespace engine
{
	namespace helloWorld
	{
		SimpleShader::SimpleShader(std::string& vertexFile, std::string& fragmentFile)
			: ShaderProgram(vertexFile, fragmentFile)
		{

		}

		void SimpleShader::loadProjectionMatrix(glm::mat4 projMatrix)
		{
			loadMatrix("projectionMatrix", projMatrix);
		}

		SimpleShader::~SimpleShader()
		{

		}
	}
}
