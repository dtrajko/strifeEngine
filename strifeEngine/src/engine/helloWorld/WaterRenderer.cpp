#include "WaterRenderer.h"

namespace engine
{
	namespace helloWorld
	{
		WaterRenderer::WaterRenderer(Window * window, glm::mat4 projectionMatrix)
		{
			m_Shader = new WaterShader(m_VertexFile, m_FragmentFile);
			m_Shader->start();
			m_Shader->bindAttributes();
			m_ProjectionMatrix = projectionMatrix;
			m_Shader->loadMatrix("projectionMatrix", m_ProjectionMatrix);
			m_Shader->stop();
		}

		void WaterRenderer::init(IScene * scene)
		{
		}

		glm::mat4 WaterRenderer::getProjectionMatrix(Window * window)
		{
			return m_ProjectionMatrix;
		}

		void WaterRenderer::prepare(Window * window)
		{
		}

		void WaterRenderer::render(Window * window, IScene * scene, glm::mat4 & viewMatrix)
		{
			m_Shader->start();
			m_Shader->loadLight(scene->getLight());
			m_Shader->loadMatrix("viewMatrix", viewMatrix);

			std::vector<WaterTile *> waterTiles = scene->getWaterTiles();
			for (WaterTile * waterTile : waterTiles)
			{
				renderWaterTile(waterTile, scene);
			}
			m_Shader->stop();
		}

		void WaterRenderer::renderWaterTile(WaterTile * waterTile, IScene * scene)
		{
			RawModel * rawModel = waterTile->getModel();
			glBindVertexArray(rawModel->getVaoID());
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);
			glEnableVertexAttribArray(2);

			m_TransformationMatrix = Maths::createTransformationMatrix(
				glm::vec3(waterTile->getX(), waterTile->getY(), waterTile->getZ()), 0, 0, 0, WaterTile::TILE_SIZE);
			m_Shader->loadMatrix("transformationMatrix", m_TransformationMatrix);

			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, waterTile->getDuDvTexture());
			glActiveTexture(GL_TEXTURE1);
			glBindTexture(GL_TEXTURE_2D, waterTile->getNormalMap());

			glDrawArrays(GL_TRIANGLES, 0, rawModel->getVertexCount());
			// glDrawElements(GL_TRIANGLES, rawModel->getVertexCount(), GL_UNSIGNED_INT, 0);

			glDisableVertexAttribArray(0);
			glDisableVertexAttribArray(1);
			glDisableVertexAttribArray(2);
			glBindVertexArray(0);
		}

		void WaterRenderer::cleanUp()
		{
			m_Shader->cleanUp();
		}

		WaterRenderer::~WaterRenderer()
		{
		}

	}
}
