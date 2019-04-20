#include "SkyBoxShader.h"

namespace engine { namespace minecraft { namespace skybox {

	SkyBoxShader::SkyBoxShader(const std::string& vertexFile, const std::string& fragmentFile) : ShaderProgram(vertexFile, fragmentFile)
	{

	}

	void SkyBoxShader::bindAttributes()
	{
		bindAttribute(0, "position");
		bindAttribute(1, "texCoord");
		bindAttribute(2, "vertexNormal");
	}

	void SkyBoxShader::connectTextureUnits()
	{
		loadInt("texture_sampler", 0);
	}

	SkyBoxShader::~SkyBoxShader()
	{

	}

} } }
