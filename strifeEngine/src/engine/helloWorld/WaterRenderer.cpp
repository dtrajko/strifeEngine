#include "WaterRenderer.h"

namespace engine
{
	namespace helloWorld
	{
		WaterRenderer::WaterRenderer(Window * window, glm::mat4 projectionMatrix)
		{
			m_Shader = new WaterShader(m_VertexFile, m_FragmentFile);
			m_FBOs = new WaterFrameBuffers(window);
			m_Shader->start();
			m_Shader->bindAttributes();
			m_Shader->connectTextureUnits();
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

		void WaterRenderer::prepare(Window * window, IScene * scene, glm::mat4 & viewMatrix, WaterTile * waterTile, RawModel * rawModel)
		{
			m_Shader->start();
			m_Shader->loadMatrix("viewMatrix", viewMatrix);
			moveFactor += WAVE_SPEED * 0.05f;
			moveFactor = std::fmodf(moveFactor, 1.);
			m_Shader->loadMoveFactor(moveFactor);
			m_Shader->loadLight(scene->getLight());

			glBindVertexArray(rawModel->getVaoID());
			glEnableVertexAttribArray(0);

			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, m_FBOs->getReflectionTexture());
			glActiveTexture(GL_TEXTURE1);
			glBindTexture(GL_TEXTURE_2D, waterTile->getDuDvTexture());
			glActiveTexture(GL_TEXTURE2);
			glBindTexture(GL_TEXTURE_2D, waterTile->getNormalMap());

			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		}

		void WaterRenderer::render(Window * window, IScene * scene, glm::mat4 & viewMatrix)
		{
			std::vector<WaterTile *> waterTiles = scene->getWaterTiles();
			for (WaterTile * waterTile : waterTiles)
			{
				RawModel * rawModel = waterTile->getModel();
				prepare(window, scene, viewMatrix, waterTile, rawModel);
				renderWaterTile(scene, waterTile, rawModel);
			}
			unbind();
		}

		void WaterRenderer::render(Window * window, IScene * scene, glm::mat4 & viewMatrix, glm::vec4 clipPlane)
		{
			render(window, scene, viewMatrix);
		}

		void WaterRenderer::renderWaterTile(IScene * scene, WaterTile * waterTile, RawModel * rawModel)
		{
			m_TransformationMatrix = Maths::createTransformationMatrix(
				glm::vec3(waterTile->getX(), waterTile->getY(), waterTile->getZ()), 0, 0, 0, WaterTile::TILE_SIZE);
			m_Shader->loadMatrix("transformationMatrix", m_TransformationMatrix);

			glDrawArrays(GL_TRIANGLES, 0, rawModel->getVertexCount());
		}

		void WaterRenderer::unbind()
		{
			glDisable(GL_BLEND);
			glDisableVertexAttribArray(0);
			glBindVertexArray(0);
			m_Shader->stop();
		}

		WaterFrameBuffers * WaterRenderer::getFBOs() const
		{
			return m_FBOs;
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
