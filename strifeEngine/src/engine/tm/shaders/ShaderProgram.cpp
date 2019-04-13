#include "ShaderProgram.h"

namespace engine
{
	namespace tm
	{
		namespace shaders
		{
			ShaderProgram::ShaderProgram(const std::string & vertexFile, const std::string & fragmentFile)
			{
				vertexShaderID = loadShader(vertexFile, GL_VERTEX_SHADER);
				fragmentShaderID = loadShader(fragmentFile, GL_FRAGMENT_SHADER);
				programID = glCreateProgram();
				glAttachShader(programID, vertexShaderID);
				glAttachShader(programID, fragmentShaderID);
				bindAttributes();
				glLinkProgram(programID);
				glValidateProgram(programID);
				std::cout << "Program [ID=" << programID << "]" << std::endl;
			}

			void ShaderProgram::bindAttributes()
			{
				bindAttribute(0, "position");
				bindAttribute(1, "textureCoords");
				bindAttribute(2, "normal");
			}

			unsigned int ShaderProgram::loadShader(const std::string & file, unsigned int type)
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

				std::cout << shaderType << " shader [ID=" << shaderID << ", file='" << file << "']" << std::endl;
				// std::cout << shaderSource << std::endl;

				return shaderID;
			}

			int ShaderProgram::getUniformLocation(const std::string& uniformName)
			{
				if (uniformLocationCache.find(uniformName) != uniformLocationCache.end())
					return uniformLocationCache[uniformName];

				int location = glGetUniformLocation(programID, uniformName.c_str());
				if (location == -1)
				{
					std::cout << "Warning: uniform '" << uniformName << "' doesn't exist! [programID: " << programID  << ", location: " << location  << "]" << std::endl;
				}
				uniformLocationCache[uniformName] = location;
				return location;
			}

			void ShaderProgram::loadFloat(const std::string & locationName, float value)
			{
				glUniform1f(getUniformLocation(locationName), value);
			}

			void ShaderProgram::loadInt(const std::string& locationName, int value)
			{
				glUniform1i(getUniformLocation(locationName), value);
			}

			void ShaderProgram::loadBool(const std::string & locationName, bool value)
			{
				float toLoad = 0;
				if (value)
				{
					toLoad = 1;
				}
				int location = getUniformLocation(locationName);
				glUniform1f(location, toLoad);
			}

			void ShaderProgram::loadVec4f(const std::string& locationName, glm::vec4 vector)
			{
				int location = getUniformLocation(locationName);
				glUniform4f(location, vector.x, vector.y, vector.z, vector.w);
			}

			void ShaderProgram::loadVec3f(const std::string& locationName, glm::vec3 vector)
			{
				int location = getUniformLocation(locationName);
				glUniform3f(location, vector.x, vector.y, vector.z);
			}

			void ShaderProgram::loadMatrix(const std::string& name, glm::mat4 matrix)
			{
				glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
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

			void ShaderProgram::bindAttribute(int attribute, std::string variableName)
			{
				glBindAttribLocation(programID, attribute, variableName.c_str());
			}


			ShaderProgram::~ShaderProgram()
			{

			}
		}
	}
}
