#include "SceneCherno.h"

namespace engine
{
	namespace helloWorld
	{
		SceneCherno::SceneCherno()
		{

		}

		void SceneCherno::init(Window * window)
		{
			masterRenderer = new MasterRendererCherno(window);
		}

		void SceneCherno::update(float interval, Input * input)
		{
		}

		void SceneCherno::render(Window * window)
		{
			masterRenderer->render(window, this);
		}

		Entity * SceneCherno::getEntity()
		{
			return entity;
		}

		void SceneCherno::cleanUp()
		{
			loader->cleanUp();
			masterRenderer->cleanUp();
		}

		ICamera * SceneCherno::getCamera()
		{
			return camera;
		}

		Loader * SceneCherno::getLoader()
		{
			return loader;
		}

		SceneCherno::~SceneCherno()
		{

		}
	}
}
