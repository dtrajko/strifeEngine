#include "SimpleShader.h"

namespace engine
{
	namespace helloWorld
	{
		SimpleShader::SimpleShader(std::string& vertexFile, std::string& fragmentFile)
			: ShaderProgram(vertexFile, fragmentFile)
		{

		}

		void SimpleShader::bindAttributes()
		{
			bindAttribute(0, "position");
			bindAttribute(1, "textureCoords");
		}

		SimpleShader::~SimpleShader()
		{

		}
	}
}
