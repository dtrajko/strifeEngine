#include "SceneShader.h"

namespace engine { namespace helloWorld {

	SceneShader::SceneShader(const std::string& vertexFile, const std::string& fragmentFile) : ShaderProgram(vertexFile, fragmentFile)
	{

	}

	SceneShader::~SceneShader()
	{

	}

} }
