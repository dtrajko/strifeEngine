#include "RawModel.h"
#include "TexturedModel.h"

namespace engine
{
	namespace tm
	{
		namespace models
		{
			TexturedModel::TexturedModel(RawModel * _rawModel, ModelTexture * _modelTexture)
			{
				rawModelCubeMesh = _rawModel;
				modelTexture = _modelTexture;
			}

			RawModel* TexturedModel::getRawModel()
			{
				return rawModelCubeMesh;
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
