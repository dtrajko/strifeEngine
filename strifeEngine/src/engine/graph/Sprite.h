#pragma once

#include "GLFW\glfw3.h"
#include "Texture.h"

#include <iostream>
#include <string>

namespace engine
{
	namespace graph
	{
		class Sprite
		{
		public:
			Sprite();
			Sprite(std::string imagePath);
			Sprite(std::string imagePath, float _xPos, float _yPos);
			void Update();
			void Render();
			virtual ~Sprite();

		private:
			Texture texture;
			float xPos;
			float yPos;

		};
	}
}
