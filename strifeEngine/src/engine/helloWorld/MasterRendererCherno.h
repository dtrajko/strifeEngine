#pragma once

#include "../interfaces/IMasterRenderer.h"
#include "../interfaces/IScene.h"
#include "../helloWorld/SimpleShader.h"
#include "../helloWorld/ChernoShader.h"
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
		class MasterRendererCherno : public IMasterRenderer
		{
		private:
			float RED = 1.0f;
			float GREEN = 0.4f;
			float BLUE = 0.2f;
			ChernoShader * shader;
			glm::mat4 projectionMatrix;

		public:
			MasterRendererCherno(Window * window);
			void init(IScene * scene);
			glm::mat4 createProjectionMatrix(Window * window);
			glm::mat4 getProjectionMatrix(Window * window);
			void prepare(Window * window);
			void render(Window * window, IScene * scene);
			void renderModel(Entity * entity);
			void cleanUp();
			virtual ~MasterRendererCherno();
		};
	}
}
