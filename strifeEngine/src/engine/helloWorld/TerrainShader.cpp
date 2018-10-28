#include "TerrainShader.h"

namespace engine
{
	namespace helloWorld
	{
		TerrainShader::TerrainShader(std::string& vertexFile, std::string& fragmentFile) : ShaderProgram(vertexFile, fragmentFile)
		{
		}

		void TerrainShader::bindAttributes()
		{
			bindAttribute(0, "position");
			bindAttribute(1, "textureCoords");
			bindAttribute(2, "normal");
		}

		void TerrainShader::getAllUniformLocations()
		{

		}

		void TerrainShader::loadLight(Light * light)
		{
			loadVec3f("lightPosition", light->getPosition());
			loadVec3f("lightColor", light->getColor());
		}

		void TerrainShader::loadShineVariables(float shineDamper, float reflectivity)
		{
			loadFloat("shineDamper", shineDamper);
			loadFloat("reflectivity", reflectivity);
		}

		TerrainShader::~TerrainShader()
		{

		}
	}
}
