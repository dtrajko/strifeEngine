#include "ChernoShader.h"

namespace engine
{
	namespace helloWorld
	{
		ChernoShader::ChernoShader(std::string& vertexFile, std::string& fragmentFile)
			: ShaderProgram(vertexFile, fragmentFile)
		{

		}

		ChernoShader::~ChernoShader()
		{

		}
	}
}
