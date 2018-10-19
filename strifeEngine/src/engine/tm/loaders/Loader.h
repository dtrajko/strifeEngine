#pragma once

#include <vector>
#include <iostream>
#include <GL/glew.h>
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
			private:
				std::vector<unsigned int> vaos;
				std::vector<unsigned int> vbos;

			public:
				Loader();
				int loadTexture(const std::string & filePath);
				RawModel * loadToVAO(
					float * positions, unsigned int positionsCount,
					unsigned int * textureCoords, unsigned int textureCoordsCount,
					unsigned int * indices, unsigned int indicesCount);
				unsigned int createVAO();
				std::vector<unsigned int> getVAOs();
				std::vector<unsigned int> getVBOs();
				void unbindVAO();
				void cleanUp();
				virtual ~Loader();

			private:
				void bindIndicesBuffer(unsigned int * indices, unsigned int count);
				void storeDataInAttrListUInt(int attrNumber, int size, unsigned int * data, unsigned int count);
				void storeDataInAttrListFloat(int attrNumber, int size, float * data, unsigned int count);
			};
		}
	}
}
