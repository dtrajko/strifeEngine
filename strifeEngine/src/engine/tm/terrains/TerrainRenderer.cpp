#include "TerrainRenderer.h"

namespace engine { namespace tm { namespace terrains {

	TerrainRenderer::TerrainRenderer(Window * window, glm::mat4 projectionMatrix)
	{
		m_Shader = new TerrainShader(m_VertexFile, m_FragmentFile);
		m_Shader->start();
		m_Shader->bindAttributes();
		m_ProjectionMatrix = projectionMatrix;
		m_Shader->loadMatrix("projectionMatrix", m_ProjectionMatrix);
		m_Shader->stop();
	}

	void TerrainRenderer::init(IScene * scene)
	{
	}

	glm::mat4 TerrainRenderer::getProjectionMatrix(Window * window)
	{
		return m_ProjectionMatrix;
	}

	void TerrainRenderer::prepare(Window * window)
	{
	}

	void TerrainRenderer::render(Window * window, IScene * scene, glm::mat4 & viewMatrix, glm::vec4 clipPlane)
	{
		m_Shader->start();
		m_Shader->loadClipPlane(clipPlane);
		m_Shader->loadLight(scene->getLight());
		m_Shader->loadMatrix("viewMatrix", viewMatrix);

		std::vector<ITerrain *> terrains = scene->getTerrains();
		for (ITerrain * terrain : terrains)
		{
			renderTerrain(terrain, scene);
		}
		m_Shader->stop();
	}

	void TerrainRenderer::renderTerrain(ITerrain * terrain, IScene * scene)
	{
		RawModel * rawModel = terrain->getModel();
		glBindVertexArray(rawModel->getVaoID());
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);

		m_TransformationMatrix = Maths::createTransformationMatrix(
			glm::vec3(terrain->getX(), 0, terrain->getZ()), 0, 0, 0, glm::vec3(1));
		m_Shader->loadMatrix("transformationMatrix", m_TransformationMatrix);

		ModelTexture * texture = terrain->getTexture();
		m_Shader->loadShineVariables(texture->getShineDumper(), texture->getReflectivity());
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture->getID());
		// std::cout << "TerrainRenderer textureID: " << texture->getID() << std::endl;

		glDrawElements(GL_TRIANGLES, rawModel->getVertexCount(), GL_UNSIGNED_INT, 0);

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(2);
		glBindVertexArray(0);
	}

	void TerrainRenderer::cleanUp()
	{
		m_Shader->cleanUp();
	}

	TerrainRenderer::~TerrainRenderer()
	{
	}

} } }
