#pragma once

#include <string>
#include "SOIL\src\SOIL.h"

namespace engine
{
	namespace graph
	{
		class Image
		{
		private:
			unsigned char * m_Buffer;
			int m_Width;
			int m_Height;
			int m_Channels;

		public:
			Image(const std::string & heightMap);
			unsigned char * getBuffer();
			int getWidth();
			int getHeight();
			int getChannels();
			int getRed(int x, int z);
			int getGreen(int x, int z);
			int getBlue(int x, int z);
			int getAlpha(int x, int z);
			~Image();
		};
	}
}
