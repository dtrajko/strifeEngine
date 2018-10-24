#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include "../models/RawModel.h"
#include "Loader.h"
#include "../../../vendor/glm/glm.hpp"
#include "../../../vendor/glm/gtc/matrix_transform.hpp"
#include "../../../vendor/glm/gtc/type_ptr.hpp"

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
