#ifndef _MASTER_RENDERER_H
#define _MASTER_RENDERER_H

#include "../interfaces/IMasterRenderer.h"
#include "../interfaces/IScene.h"
#include "../helloWorld/SimpleShader.h"
#include "../tm/toolbox/Maths.h"
#include "../../engine/tm/entities/Entity.h"
#include "../../vendor/glm/glm.hpp"
#include "../../vendor/glm/gtc/matrix_transform.hpp"

using namespace engine::interfaces;
using namespace engine::tm::entities;
using namespace engine::tm::toolbox;

namespace engine
{
	namespace helloWorld
	{
		class MasterRenderer : public IMasterRenderer
		{
		private:
			float RED = 0.2f;
			float GREEN = 0.1f;
			float BLUE = 0.3f;
			SimpleShader * shader;
			glm::mat4 projectionMatrix;
			glm::mat4 viewMatrix;
			glm::mat4 transformationMatrix;

		public:
			MasterRenderer(Window * window);
			void init(IScene * scene);
			glm::mat4 createProjectionMatrix(Window * window);
			glm::mat4 getProjectionMatrix(Window * window);
			void prepare(Window * window);
			void render(Window * window, IScene * scene);
			void renderModel(Entity * entity);
			void cleanUp();
			virtual ~MasterRenderer();
		};
	}
}

#endif
