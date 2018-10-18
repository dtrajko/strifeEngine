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

			int Loader::loadTexture(const std::string & fileFullPath)
			{
				float bias = 0.0f;
				int textureID = -1;
				Texture * texture = new Texture(fileFullPath);
				textureID = texture->GetID();
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
				return textureID;
			}

			RawModel * Loader::loadToVAO(float * positions, unsigned int * textureCoords, unsigned int * indices)
			{
				int vaoID = createVAO();
				// bindIndicesBuffer(indices);
				// storeDataInAttributeList(0, 3, positions);
				// storeDataInAttributeList(1, 2, textureCoords);
				// unbindVAO();
				// return new RawModel(vaoID, indices.length);
				return nullptr;
			}

			int Loader::createVAO()
			{
				int vaoID = -1; // glGenVertexArrays();
				// TODO: vaos.add(vaoID);
				// glBindVertexArray(vaoID);
				return vaoID;
			}

			Loader::~Loader()
			{

			}
		}
	}
}
