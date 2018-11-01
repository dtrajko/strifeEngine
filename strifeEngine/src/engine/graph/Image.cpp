#include "Image.h"

namespace engine
{
	namespace graph
	{
		Image::Image(const std::string & heightMap)
		{
			m_Buffer = SOIL_load_image(heightMap.c_str(), &m_Width, &m_Height, &m_Channels, SOIL_LOAD_RGBA);
		}

		unsigned char * Image::getBuffer()
		{
			return m_Buffer;
		}

		int Image::getWidth()
		{
			return m_Width;
		}

		int Image::getHeight()
		{
			return m_Height;
		}

		int Image::getChannels()
		{
			return m_Channels;
		}

		int Image::getRed(int x, int z)
		{
			return (int) m_Buffer[((z * m_Width + x) * m_Channels) + 0];
		}

		int Image::getGreen(int x, int z)
		{
			return (int) m_Buffer[((z * m_Width + x) * m_Channels) + 1];
		}

		int Image::getBlue(int x, int z)
		{
			return (int) m_Buffer[((z * m_Width + x) * m_Channels) + 2];
			
		}

		int Image::getAlpha(int x, int z)
		{
			return (int) m_Buffer[((z * m_Width + x) * m_Channels) + 3];
		}

		Image::~Image()
		{

		}
	}
}
