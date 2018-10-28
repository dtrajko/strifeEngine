#pragma once

#include "ICamera.h"
#include "../../engine/graph/Input.h"
#include "../../engine/tm/loaders/Loader.h"
#include "../../engine/tm/entities/Entity.h"
#include "../../engine/tm/entities/Light.h"
#include "../../engine/interfaces/ITerrain.h"

using namespace engine::graph;
using namespace engine::tm::loaders;
using namespace engine::tm::entities;
using namespace engine::interfaces;

namespace engine
{
	namespace interfaces
	{
		class IScene
		{
		public:
			virtual void init(Window * window) = 0;
			virtual void update(float interval, Window * window) = 0;
			virtual void render(Window * window) = 0;
			virtual void cleanUp() = 0;
			virtual ICamera * getCamera() = 0;
			virtual Loader * getLoader() = 0;
			virtual Entity * getEntity() = 0;
			virtual RawModel * getModel() = 0;
			virtual Light * getLight() = 0;
			virtual TexturedModel * getTexturedModel() = 0;
			virtual std::vector<ITerrain *> getTerrains() = 0;
		};
	}
}
