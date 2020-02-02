#pragma once

#include "../interfaces/IGameLogic.h"
#include "../interfaces/IScene.h"
#include "../../engine/graph/Input.h"
#include "../minecraft/SceneMC.h"


using namespace engine::interfaces;
using namespace engine::graph;
using namespace engine::minecraft;


class engine::minecraft::SceneMC;
class engine::graph::Window;


namespace engine
{
	namespace minecraft
	{
		class Minecraft : public IGameLogic
		{
		public:
			Minecraft();
			void init(Window * window);
			void update(float interval, Window * window);
			void render(Window * window);
			void cleanUp();
			virtual ~Minecraft();

		public:
			IScene* scene;
		};
	}
}
