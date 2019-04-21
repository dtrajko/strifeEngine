#include "Texture.h"

namespace engine
{
	namespace graph
	{
		Texture::Texture()
		{
			m_ID = -1;
		}

		Texture::Texture(int id)
		{
			m_ID = id;
			if (!getTextureParams())
			{
				std::cout << "Texture: error loading image with ID [" << m_ID << "]" << std::endl;
			}
		}

		Texture::Texture(std::string path)
		{
			m_ID = SOIL_load_OGL_texture(path.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y & SOIL_FLAG_MULTIPLY_ALPHA);
			if (!getTextureParams())
			{
				std::cout << "Texture: error loading image [" << path << "]" << std::endl;
			}
		}

		bool Texture::getTextureParams()
		{
			if (m_ID > 0)
			{
				int mipLevel = 0;
				glBindTexture(GL_TEXTURE_2D, m_ID);
				glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_WIDTH, &m_Width);
				glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_HEIGHT, &m_Height);

				glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, m_Width, m_Height, 0, GL_RGBA, GL_FLOAT, nullptr);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
				// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
				// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

				return true;
			}

			return false;
		}

		Texture::~Texture()
		{

		}

		int Texture::getID()
		{
			return m_ID;
		}

		int Texture::getWidth()
		{
			return m_Width;
		}

		int Texture::getHeight()
		{
			return m_Height;
		}
	}
}
