#pragma once

#include "RawModel.h"
#include "../textures/ModelTexture.h"

using namespace engine::tm::textures;

namespace engine
{
	namespace tm
	{
		namespace models
		{
			class TexturedModel
			{
			private:
				RawModel* rawModel;
				ModelTexture* modelTexture;

			public:
				TexturedModel(RawModel* model, ModelTexture* texture);
				RawModel* getRawModel();
				ModelTexture* getTexture();
				~TexturedModel();
			};
		}
	}
}
