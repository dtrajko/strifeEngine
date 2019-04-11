#include "WaterShader.h"

namespace engine
{
	namespace helloWorld
	{
		WaterShader::WaterShader(const std::string & vertexFile, const std::string & fragmentFile) : ShaderProgram(vertexFile, fragmentFile)
		{

		}

		void WaterShader::bindAttributes()
		{
			bindAttribute(0, "position");
			bindAttribute(1, "textureCoords");
			bindAttribute(2, "normal");
		}

		void WaterShader::getAllUniformLocations()
		{

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
	}
}
