#include "RawModel.h"
#include "TexturedModel.h"

namespace engine
{
	namespace tm
	{
		namespace models
		{
			TexturedModel::TexturedModel(RawModel* model, ModelTexture* texture)
			{
				rawModel = model;
				modelTexture = texture;
			}

			RawModel* TexturedModel::getRawModel()
			{
				return rawModel;
			}

			ModelTexture* TexturedModel::getTexture()
			{
				return modelTexture;
			}

			TexturedModel::~TexturedModel()
			{

			}
		}
	}
}
