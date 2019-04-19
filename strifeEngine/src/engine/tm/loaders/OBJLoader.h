#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "../models/RawModel.h"
#include "Loader.h"
#include "../../../vendor/glm/glm.hpp"
#include "../../../vendor/glm/gtc/matrix_transform.hpp"
#include "../../../vendor/glm/gtc/type_ptr.hpp"
#include "../../../engine/utils/Util.h"

using namespace engine::tm::models;
using namespace engine::utils;

namespace engine { namespace tm { namespace loaders {

	class OBJLoader
	{
	public:
		static RawModel * loadOBJModel(std::string fileName, Loader * loader);
		static void processVertex(std::vector<std::string> vertexData,
			std::vector<unsigned int> & vecIndices, std::vector<glm::vec2> & vecTextureCoords, std::vector<glm::vec3> & vecNormals,
			float textureArray[], float normalsArray[]);
	};
		
} } }
