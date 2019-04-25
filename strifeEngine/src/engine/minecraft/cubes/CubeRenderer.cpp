#include "CubeRenderer.h"

namespace engine { namespace minecraft { namespace cubes {

	CubeRenderer::CubeRenderer(Window * window, glm::mat4 projectionMatrix)
	{
		m_Shader = new CubeShader(m_VertexFile, m_FragmentFile);
		m_Shader->start();
		m_Shader->bindAttributes();
		m_ProjectionMatrix = projectionMatrix;
		m_Shader->loadMatrix("projectionMatrix", m_ProjectionMatrix);
		m_Shader->stop();
	}

	void CubeRenderer::init(IScene * scene)
	{

	}

	glm::mat4 CubeRenderer::getProjectionMatrix(Window * window)
	{
		return m_ProjectionMatrix;
	}

	void CubeRenderer::render(Window * window, IScene * scene, glm::mat4 & viewMatrix, glm::vec4 clipPlane)
	{
		m_Shader->start();
		m_Shader->loadMatrix("viewMatrix", viewMatrix);
		// TODO: render model
		m_Shader->stop();
	}

	void CubeRenderer::prepare(Window * window)
	{
	}

	void CubeRenderer::renderModel()
	{
		int vaoID = 0;
		glBindVertexArray(vaoID);
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);

		glm::vec3 translation;
		m_TransformationMatrix = Maths::createTransformationMatrix(translation, 1.f, 1.f, 1.f, glm::vec3(1.f));
		m_Shader->loadMatrix("transformationMatrix", m_TransformationMatrix);

		int textureID = 0;
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, textureID);

		int vertexCount = 0;
		glDrawElements(GL_TRIANGLES, vertexCount, GL_UNSIGNED_INT, 0);

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(2);
		glBindVertexArray(0);
	}

	void CubeRenderer::cleanUp()
	{
		m_Shader->cleanUp();
	}

	CubeRenderer::~CubeRenderer()
	{
	}

} } }
