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
		public:
			Texture();
			Texture(int _id);
			Texture(std::string path);
			virtual ~Texture();

			int GetID();
			int GetWidth();
			int GetHeight();

		private:
			bool GetTextureParams();
			int id;
			int width;
			int height;

		};
	}
}
