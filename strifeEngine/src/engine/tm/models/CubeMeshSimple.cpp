#include "CubeMeshSimple.h"

namespace engine
{
	namespace tm
	{
		namespace models
		{
			CubeMeshSimple::CubeMeshSimple()
			{
			}

			float * CubeMeshSimple::getVertices()
			{
				return (float *) &vecVertices[0];
			}

			float * CubeMeshSimple::getTextureCoords()
			{
				return (float *) &vecTextureCoords[0];
			}

			unsigned int * CubeMeshSimple::getIndices()
			{
				return (unsigned int *) &vecIndices[0];
			}

			unsigned int CubeMeshSimple::getVerticesCount()
			{
				return vecVertices.size();
			}

			unsigned int CubeMeshSimple::getTextureCoordsCount()
			{
				return vecTextureCoords.size();
			}

			unsigned int CubeMeshSimple::getIndicesCount()
			{
				return vecIndices.size();
			}

			CubeMeshSimple::~CubeMeshSimple()
			{

			}
		}
	}
}
