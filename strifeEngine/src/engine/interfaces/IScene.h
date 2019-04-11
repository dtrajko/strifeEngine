#pragma once

#include "ICamera.h"
#include "../../engine/graph/Input.h"
#include "../../engine/tm/loaders/Loader.h"
#include "../../engine/tm/entities/Entity.h"
#include "../../engine/tm/entities/Light.h"
#include "../../engine/tm/water/WaterTile.h"
#include "../../engine/interfaces/ITerrain.h"

using namespace engine::graph;
using namespace engine::tm::loaders;
using namespace engine::tm::entities;
using namespace engine::tm::water;
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
			virtual std::vector<Entity *> getEntities() = 0;
			virtual std::vector<ITerrain *> getTerrains() = 0;
			virtual std::vector<WaterTile *> getWaterTiles() = 0;
			virtual Light * getLight() = 0;
		};
	}
}
