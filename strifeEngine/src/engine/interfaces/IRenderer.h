#ifndef _I_RENDERER_H
#define _I_RENDERER_H

#include "IScene.h"
#include "../../engine/graph/Window.h"
#include "../../vendor/glm/glm.hpp"
#include "../../vendor/glm/gtc/matrix_transform.hpp"

namespace engine
{
	namespace interfaces
	{
		class IRenderer
		{
		protected:

		public:
			virtual void init(IScene * scene) = 0;
			virtual glm::mat4 getProjectionMatrix(Window * window) = 0;
			virtual void prepare(Window * window) = 0;
			virtual void render(Window * window, IScene * scene) = 0;
			virtual void cleanUp() = 0;
		};
	}
}

#endif // !_I_RENDERER_H
