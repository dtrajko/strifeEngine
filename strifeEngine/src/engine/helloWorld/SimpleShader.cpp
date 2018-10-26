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
			std::cout << "SimpleShader::bindAttributes CALLED!" << std::endl;
			bindAttribute(0, "position");
			bindAttribute(1, "textureCoords");
			bindAttribute(2, "normal");
		}

		void SimpleShader::getAllUniformLocations()
		{

		}

		void SimpleShader::loadLight(Light * light)
		{
			loadVec3f("lightPosition", light->getPosition());
			loadVec3f("lightColor", light->getColor());
		}

		SimpleShader::~SimpleShader()
		{

		}
	}
}
