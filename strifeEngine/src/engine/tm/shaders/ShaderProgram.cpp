#include "ShaderProgram.h"
#include "GL/glew.h"

namespace engine
{
	namespace tm
	{
		namespace shaders
		{
			ShaderProgram::ShaderProgram(std::string & vertexFile, std::string & fragmentFile)
			{
				programID = glCreateProgram();
				std::cout << "ProgramID: " << programID << std::endl;
				vertexShaderID = loadShader(vertexFile, GL_VERTEX_SHADER);
				fragmentShaderID = loadShader(fragmentFile, GL_FRAGMENT_SHADER);
				glAttachShader(programID, vertexShaderID);
				glAttachShader(programID, fragmentShaderID);
				bindAttributes();
				glLinkProgram(programID);
				glValidateProgram(programID);
				getAllUniformLocations();
			}

			void ShaderProgram::start()
			{
				glUseProgram(programID);
			}

			void ShaderProgram::stop()
			{
				glUseProgram(0);
			}

			void ShaderProgram::cleanUp()
			{
				stop();
				glDetachShader(programID, vertexShaderID);
				glDetachShader(programID, fragmentShaderID);
				glDeleteShader(vertexShaderID);
				glDeleteShader(fragmentShaderID);
				glDeleteProgram(programID);
			}

			std::stringstream ShaderProgram::parseShader(const std::string& file)
			{
				std::ifstream stream(file);
				std::string line;
				std::stringstream shaderSource;
				while (getline(stream, line))
				{
					shaderSource << line << "\n";
				}
				return shaderSource;
			}

			unsigned int ShaderProgram::loadShader(std::string& file, unsigned int type)
			{
				std::stringstream shaderSourceStream = parseShader(file);

				std::string shaderType;
				switch (type)
				{
				case GL_VERTEX_SHADER:
					shaderType = "vertex";
					break;
				case GL_FRAGMENT_SHADER:
					shaderType = "fragment";
					break;
				default:
					shaderType = "n/a";
				}

				unsigned int shaderID = glCreateShader(type);
				const std::string& shaderSource = shaderSourceStream.str();
				const char * shaderSourceChar = shaderSource.c_str();

				glShaderSource(shaderID, 1, &shaderSourceChar, nullptr);
				glCompileShader(shaderID);
				int result;
				glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);
				if (result == GL_FALSE)
				{
					int length;
					glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &length);
					char * message = new char[length];
					glGetShaderInfoLog(shaderID, length, &length, message);
					std::cout << message << std::endl;
					std::cout << "ShaderProgram: Could not compile " << shaderType << " shader [" << file << "]" << std::endl;
					glDeleteShader(shaderID);
					return 0;
				}

				std::cout << shaderType << " shader [ ID: " << shaderID << " ]" << std::endl;
				std::cout << shaderSource << std::endl;

				return shaderID;
			}

			void ShaderProgram::bindAttribute(int attribute, std::string variableName)
			{
				glBindAttribLocation(programID, attribute, variableName.c_str());
			}

			void ShaderProgram::loadMatrix(const std::string& locationName, glm::mat4 matrix)
			{
				glUniformMatrix4fv(getUniformLocation(locationName), 1, GL_FALSE, &matrix[0][0]);
			}

			void ShaderProgram::bindAttributes()
			{

			}

			void ShaderProgram::getAllUniformLocations()
			{

			}

			int ShaderProgram::getUniformLocation(const std::string& name)
			{
				if (uniformLocationCache.find(name) != uniformLocationCache.end())
					return uniformLocationCache[name];

				int location = glGetUniformLocation(programID, name.c_str());
				if (location == -1)
				{
					std::cout << "Name: " << name << ", programID: " << programID << ", Location: " << location << std::endl;
					std::cout << "Warning: uniform '" << name << "' doesn't exist!" << std::endl;
				}

				uniformLocationCache[name] = location;
				return location;
			}

			ShaderProgram::~ShaderProgram()
			{

			}
		}
	}
}
