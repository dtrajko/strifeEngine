#pragma once

#include <string>
#include "../models/RawModel.h"
#include "Loader.h"

using namespace engine::tm::models;

namespace engine
{
	namespace tm
	{
		namespace loaders
		{
			class OBJLoader
			{
			public:
				static RawModel * loadOBJModel(std::string fileName, Loader * loader);
				static void processVertex();
			};
		}
	}
}
