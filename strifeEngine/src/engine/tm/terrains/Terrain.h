#pragma once

#include <iostream>
#include "../../../engine/graph/Image.h"
#include "../../../engine/interfaces/ITerrain.h"
#include "../../../engine/tm/models/RawModel.h"
#include "../../../engine/tm/loaders/Loader.h"
#include "../../../engine/tm/textures/ModelTexture.h"
#include "../../../vendor/glm/glm.hpp"
#include "../../../vendor/glm/gtc/matrix_transform.hpp"

using namespace engine::graph;
using namespace engine::interfaces;
using namespace engine::tm::models;
using namespace engine::tm::loaders;
using namespace engine::tm::textures;

namespace engine
{
	namespace tm
	{
		namespace terrains
		{
			class Terrain : public ITerrain
			{
			private:
				const float m_Size = 400;
				const float MAX_HEIGHT = 40;
				const float MAX_PIXEL_COLOR = 255;

				unsigned int m_VertexCount = 32;
				float m_X;
				float m_Z;
				RawModel * m_Model;
				ModelTexture * m_Texture;

			public:
				Terrain(float gridX, float gridZ, Loader * loader, ModelTexture * texture, const std::string & heightMap);
				float getX();
				float getZ();
				RawModel * getModel();
				ModelTexture * getTexture();
				TerrainTexturePack * getTexturePack();
				TerrainTexture * getBlendMap();
				float getHeightOfTerrain(float coordX, float coordZ);
				float getWaterHeight();

			private:
				RawModel * generateTerrain(Loader * loader, const std::string & heightMap);
				void generateTerrainIndices(unsigned int * indices);
				float getHeight(int x, int z, Image * image);
				glm::vec3 calculateNormal(int x, int z, Image * image);
			};
		}
	}
}
