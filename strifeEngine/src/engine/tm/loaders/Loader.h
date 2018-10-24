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
				RawModel * loadToVAO(
					float * positions, unsigned int positionsCount,
					float * textureCoords, unsigned int textureCoordsCount,
					unsigned int * indices, unsigned int indicesCount);
				RawModel * loadToVAO(
					float * positions, unsigned int positionsCount,
					float * textureCoords, unsigned int textureCoordsCount,
					float * normals, unsigned int normalsCount,
					unsigned int * indices, unsigned int indicesCount);
				unsigned int createVAO();
				std::vector<unsigned int> getVAOs();
				std::vector<unsigned int> getVBOs();
				void cleanUp();
				virtual ~Loader();

			private:
				void bindIndicesBuffer(unsigned int * indices, unsigned int count);
				void storeDataInAttributeList(int attrNumber, unsigned int coordSize, float * data, unsigned int count);
				void unbindVAO();
			};
		}
	}
}
