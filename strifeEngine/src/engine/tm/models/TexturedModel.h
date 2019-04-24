#pragma once

#include "./RawModel.h"
#include "../../../engine/tm/textures/ModelTexture.h"
#include "../../../engine/graph/TextureAtlas.h"

using namespace engine::tm::models;
using namespace engine::tm::textures;
using namespace engine::graph;

namespace engine
{
	namespace tm
	{
		namespace models
		{
			class TexturedModel
			{
			private:
				RawModel * rawModelCubeMesh;
				ModelTexture* modelTexture;

			public:
				TexturedModel(RawModel * _rawModel, ModelTexture * _modelTexture);
				RawModel* getRawModel();
				ModelTexture* getTexture();
				~TexturedModel();
			};
		}
	}
}
