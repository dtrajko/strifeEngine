#pragma once

#include "../../tm/models/RawModel.h"
#include "../../tm/loaders/Loader.h"
#include "../../tm/textures/ModelTexture.h"

using namespace engine::tm::models;
using namespace engine::tm::loaders;
using namespace engine::tm::textures;

namespace engine
{
	namespace tm
	{
		namespace terrains
		{
			class Terrain
			{
			private:
				float m_Size = 800;
				unsigned int m_VertexCount = 128;
				float m_X;
				float m_Z;
				RawModel * m_Model;
				ModelTexture * m_Texture;

			public:
				Terrain(int gridX, int gridZ, Loader * loader, ModelTexture * texture);
				RawModel * generateTerrain(Loader * loader);
				void generateTerrainIndices(unsigned int * indices);
				float getX();
				float getZ();
				RawModel * getModel();
				ModelTexture * getTexture();
			};
		}
	}
}
