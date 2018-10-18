#include "RawModel.h"

namespace engine
{
	namespace tm
	{
		namespace models
		{
			RawModel::RawModel(int _vaoID, unsigned int _vertexCount)
			{
				vaoID = _vaoID;
				vertexCount = _vertexCount;
			}

			int RawModel::getVaoID()
			{
				return vaoID;
			}

			unsigned int RawModel::getVertexCount()
			{
				return vertexCount;
			}

			RawModel::~RawModel()
			{

			}
		}
	}
}
