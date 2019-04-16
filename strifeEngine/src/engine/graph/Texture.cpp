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
			if (!GetTextureParams())
			{
				std::cout << "Texture: error loading image with ID [" << m_ID << "]" << std::endl;
			}
		}

		Texture::Texture(std::string path)
		{
			m_ID = SOIL_load_OGL_texture(path.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y & SOIL_FLAG_MULTIPLY_ALPHA);
			if (!GetTextureParams())
			{
				std::cout << "Texture: error loading image [" << path << "]" << std::endl;
			}
		}

		bool Texture::GetTextureParams()
		{
			if (m_ID > 0)
			{
				int mipLevel = 0;
				glBindTexture(GL_TEXTURE_2D, m_ID);
				glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_WIDTH, &m_Width);
				glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_HEIGHT, &m_Height);
				return true;
			}

			return false;
		}

		Texture::~Texture()
		{

		}

		int Texture::GetID()
		{
			return m_ID;
		}

		int Texture::GetWidth()
		{
			return m_Width;
		}

		int Texture::GetHeight()
		{
			return m_Height;
		}
	}
}
