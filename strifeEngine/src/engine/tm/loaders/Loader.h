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
			public:
				std::vector<unsigned int> vaos = {};
				std::vector<unsigned int> vbos = {};
				std::vector<unsigned int> textures = {};

			public:
				Loader();
				int loadTexture(const std::string & filePath);
				RawModel * loadToVAO(float * positions, unsigned int positionsCount, unsigned int * indices, unsigned int indicesCount);
				RawModel * loadToVAO(float * vertices, unsigned int verticesCount,
					unsigned int * textureCoords, unsigned int textureCoordsCount,
					unsigned int * indices, unsigned int indicesCount);
				unsigned int createVAO();
				void storeDataInAttributeList(int attributeNumber, float * data, unsigned int count);
				void bindIndicesBuffer(unsigned int * indices, unsigned int count);
				std::vector<unsigned int> getVAOs();
				std::vector<unsigned int> getVBOs();
				void unbindVAO();
				void cleanUp();
				virtual ~Loader();

			private:
				void storeDataInAttrListUInt(int attrNumber, int size, unsigned int * data, unsigned int count);
				void storeDataInAttrListFloat(int attrNumber, int size, float * data, unsigned int count);
			};
		}
	}
}
