#include "Minecraft.h"


namespace engine
{
	namespace minecraft
	{
		Minecraft::Minecraft()
		{
		}

		void Minecraft::init(Window * window)
		{
			std::cout << "Minecraft init" << std::endl;
			scene = new engine::minecraft::SceneMC(window);
		}

		void Minecraft::update(float interval, Window * window)
		{
			scene->update(interval, window);
		}

		void Minecraft::render(Window * window)
		{
			scene->render(window);
		}

		void Minecraft::cleanUp()
		{
			scene->cleanUp();
		}

		Minecraft::~Minecraft()
		{

		}
	}
}
