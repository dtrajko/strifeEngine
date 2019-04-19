#include "WaterShader.h"

namespace engine { namespace tm { namespace water {

	WaterShader::WaterShader(const std::string & vertexFile, const std::string & fragmentFile) : ShaderProgram(vertexFile, fragmentFile)
	{

	}

	void WaterShader::bindAttributes()
	{
		bindAttribute(0, "position");
	}

	void WaterShader::connectTextureUnits()
	{
		loadInt("reflectionTexture", 0);
		loadInt("refractionTexture", 1);
		loadInt("dudvMap", 2);
		loadInt("normalMap", 3);
		loadInt("depthMap", 4);
	}

	void WaterShader::loadMoveFactor(float moveFactor)
	{
		loadFloat("moveFactor", moveFactor);
	}

	void WaterShader::loadLight(Light * light)
	{
		loadVec3f("lightPosition", light->getPosition());
		loadVec3f("lightColor", light->getColor());
	}

	void WaterShader::loadShineVariables(float shineDamper, float reflectivity)
	{
		loadFloat("shineDamper", shineDamper);
		loadFloat("reflectivity", reflectivity);
	}

	WaterShader::~WaterShader()
	{

	}

} } }
