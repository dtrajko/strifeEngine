#include "EntityShader.h"

namespace engine
{
	namespace helloWorld
	{
		EntityShader::EntityShader(const std::string& vertexFile, const std::string& fragmentFile) : ShaderProgram(vertexFile, fragmentFile)
		{
		}

		void EntityShader::bindAttributes()
		{
			bindAttribute(0, "position");
			bindAttribute(1, "textureCoords");
			bindAttribute(2, "normal");
		}

		void EntityShader::getAllUniformLocations()
		{

		}

		void EntityShader::loadLight(Light * light)
		{
			loadVec3f("lightPosition", light->getPosition());
			loadVec3f("lightColor", light->getColor());
		}

		void EntityShader::loadShineVariables(float shineDamper, float reflectivity)
		{
			loadFloat("shineDamper", shineDamper);
			loadFloat("reflectivity", reflectivity);
		}

		EntityShader::~EntityShader()
		{

		}
	}
}
