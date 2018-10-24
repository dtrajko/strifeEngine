#include "Loader.h"

namespace engine
{
	namespace tm
	{
		namespace loaders
		{
			Loader::Loader()
			{

			}

			int Loader::loadTexture(const std::string & filePath)
			{
				float bias = 0.0f;
				int textureID = NULL;
				Texture * texture = new Texture(filePath);
				textureID = texture->GetID();
				textures.push_back(textureID);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_LOD_BIAS, bias);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
				return textureID;
			}

			RawModel * Loader::loadToVAO(
				float * positions, unsigned int positionsCount, 
				float * textureCoords, unsigned int textureCoordsCount,
				unsigned int * indices, unsigned int indicesCount)
			{
				unsigned int vaoID = createVAO();
				bindIndicesBuffer(indices, indicesCount);
				storeDataInAttributeList(0, 3, positions, positionsCount);
				storeDataInAttributeList(1, 2, textureCoords, textureCoordsCount);
				unbindVAO();
				return new RawModel(vaoID, indicesCount);
			}

			RawModel * Loader::loadToVAO(
				float * positions, unsigned int positionsCount,
				float * textureCoords, unsigned int textureCoordsCount,
				float * normals, unsigned int normalsCount,
				unsigned int * indices, unsigned int indicesCount)
			{
				unsigned int vaoID = createVAO();
				bindIndicesBuffer(indices, indicesCount);
				storeDataInAttributeList(0, 3, positions, positionsCount);
				storeDataInAttributeList(1, 2, textureCoords, textureCoordsCount);
				storeDataInAttributeList(2, 3, normals, normalsCount);
				unbindVAO();
				return new RawModel(vaoID, indicesCount);
			}

			unsigned int Loader::createVAO()
			{
				unsigned int vaoID;
				glGenVertexArrays(1, &vaoID);
				vaos.push_back(vaoID);
				glBindVertexArray(vaoID);
				return vaoID;
			}

			void Loader::storeDataInAttributeList(int attrNumber, unsigned int coordSize, float * data, unsigned int count)
			{
				unsigned int vboID;
				glGenBuffers(1, &vboID);
				vbos.push_back(vboID);
				glBindBuffer(GL_ARRAY_BUFFER, vboID);
				glBufferData(GL_ARRAY_BUFFER, count * sizeof(float), data, GL_STATIC_DRAW);
				glVertexAttribPointer(attrNumber, coordSize, GL_FLOAT, GL_FALSE, 0, 0);
				glBindBuffer(GL_ARRAY_BUFFER, 0);
			}

			void Loader::bindIndicesBuffer(unsigned int * indices, unsigned int count)
			{
				unsigned int vboID;
				glGenBuffers(1, &vboID);
				vbos.push_back(vboID);
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboID);
				glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), indices, GL_STATIC_DRAW);
			}

			void Loader::unbindVAO()
			{
				glBindVertexArray(0);
			}

			std::vector<unsigned int> Loader::getVAOs()
			{
				return vaos;
			}

			std::vector<unsigned int> Loader::getVBOs()
			{
				return vbos;
			}

			void Loader::cleanUp()
			{
				for (const unsigned int vaoID : vaos)
				{
					glDeleteVertexArrays(1, &vaoID);
				}
				for (const unsigned int vboID : vbos)
				{
					glDeleteVertexArrays(1, &vboID);
				}
				for (const unsigned int textureID : textures)
				{
					glDeleteTextures(1, &textureID);
				}
			}

			Loader::~Loader()
			{

			}
		}
	}
}
