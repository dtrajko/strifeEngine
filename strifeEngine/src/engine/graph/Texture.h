#pragma once

#include <GLFW/glfw3.h>
#include "SOIL\src\SOIL.h"
#include <string>
#include <iostream>

namespace engine
{
	namespace graph
	{
		class Texture
		{
		protected:
			int m_ID;
			int m_Width;
			int m_Height;

		public:
			Texture();
			Texture(int id);
			Texture(std::string path);
			virtual ~Texture();

			int getID();
			int getWidth();
			int getHeight();

		protected:
			bool getTextureParams();

		};
	}
}
