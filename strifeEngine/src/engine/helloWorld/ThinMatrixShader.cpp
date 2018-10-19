#include "ThinMatrixShader.h"

namespace engine
{
	namespace helloWorld
	{
		ThinMatrixShader::ThinMatrixShader(std::string& vertexFile, std::string& fragmentFile)
			: ShaderProgram(vertexFile, fragmentFile)
		{

		}

		ThinMatrixShader::~ThinMatrixShader()
		{

		}
	}
}
