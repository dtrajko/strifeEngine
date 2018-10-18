#pragma once

namespace engine
{
	namespace tm
	{
		namespace models
		{
			class RawModel
			{
			private:
				int vaoID;
				unsigned int vertexCount;

			public:
				RawModel(int _vaoID, unsigned int _vertexCount);
				int getVaoID();
				unsigned int getVertexCount();
				~RawModel();
			};
		}
	}
}
