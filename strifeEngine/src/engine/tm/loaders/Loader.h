#pragma once

#include "../../graph/Texture.h"
#include "../../tm/models/RawModel.h"

using namespace engine::graph;
using namespace engine::tm::models;

namespace engine
{
	namespace tm
	{
		namespace loaders
		{
			class Loader
			{
			public:
				Loader();
				int loadTexture(const std::string & fileFullPath);
				RawModel * loadToVAO(float * positions, unsigned int * textureCoords, unsigned int * indices);
				int createVAO();
				virtual ~Loader();
			};
		}
	}
}
