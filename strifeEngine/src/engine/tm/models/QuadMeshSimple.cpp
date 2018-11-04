#include "QuadMeshSimple.h"

namespace engine
{
	namespace tm
	{
		namespace models
		{
			QuadMeshSimple::QuadMeshSimple()
			{

			}

			float * QuadMeshSimple::getVertices()
			{
				return (float *)&vecVertices[0];
			}

			float * QuadMeshSimple::getTextureCoords()
			{
				return (float *)&vecTextureCoords[0];
			}

			unsigned int * QuadMeshSimple::getIndices()
			{
				return (unsigned int *)&vecIndices[0];
			}

			unsigned int QuadMeshSimple::getVerticesCount()
			{
				return vecVertices.size();
			}

			unsigned int QuadMeshSimple::getTextureCoordsCount()
			{
				return vecTextureCoords.size();
			}

			unsigned int QuadMeshSimple::getIndicesCount()
			{
				return vecIndices.size();
			}

			QuadMeshSimple::~QuadMeshSimple()
			{

			}
		}
	}
}
