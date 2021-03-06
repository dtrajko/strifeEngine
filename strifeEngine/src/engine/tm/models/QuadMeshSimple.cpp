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
				return (unsigned int) vecVertices.size();
			}

			unsigned int QuadMeshSimple::getTextureCoordsCount()
			{
				return (unsigned int) vecTextureCoords.size();
			}

			unsigned int QuadMeshSimple::getIndicesCount()
			{
				return (unsigned int) vecIndices.size();
			}

			QuadMeshSimple::~QuadMeshSimple()
			{

			}
		}
	}
}
