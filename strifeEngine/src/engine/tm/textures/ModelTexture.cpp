#include "ModelTexture.h"

namespace engine
{
	namespace tm
	{
		namespace textures
		{
			ModelTexture::ModelTexture(int id)
			{
				textureID = id;
			}

			int ModelTexture::getID()
			{
				return textureID;
			}

			ModelTexture::~ModelTexture()
			{

			}

		}
	}
}
