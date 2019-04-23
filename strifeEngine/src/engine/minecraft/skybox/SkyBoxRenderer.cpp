#include "SkyBoxRenderer.h"

namespace engine { namespace minecraft { namespace skybox {

	SkyBoxRenderer::SkyBoxRenderer(Window * window, glm::mat4 projectionMatrix)
	{
		m_Shader = new SkyBoxShader(m_VertexFile, m_FragmentFile);
		m_Shader->start();
		m_Shader->bindAttributes();
		m_Shader->connectTextureUnits();
		m_ProjectionMatrix = projectionMatrix;
		m_Shader->loadMatrix("projectionMatrix", m_ProjectionMatrix);
		m_Shader->stop();
	}

	void SkyBoxRenderer::init(IScene * scene)
	{

	}

	glm::mat4 SkyBoxRenderer::getProjectionMatrix(Window * window)
	{
		return m_ProjectionMatrix;
	}

	void SkyBoxRenderer::render(Window * window, IScene * scene, glm::mat4 & viewMatrix)
	{
		m_Shader->start();
		m_Shader->loadMatrix("viewMatrix", viewMatrix);
		m_Shader->loadInt("hasTexture", true);
		m_Shader->loadVec3f("color", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
		m_Shader->loadVec3f("ambientLight", glm::vec3(1.0f));
		SkyBox * skyBox = scene->getSkyBox();
		renderSkyBox(skyBox);
		m_Shader->stop();
	}

	void SkyBoxRenderer::render(Window * window, IScene * scene, glm::mat4 & viewMatrix, glm::vec4 clipPlane)
	{
		render(window, scene, viewMatrix);
	}

	void SkyBoxRenderer::prepare(Window * window)
	{
	}

	void SkyBoxRenderer::renderSkyBox(SkyBox * skyBox)
	{
		Mesh * skyBoxMesh = skyBox->getMesh();

		int vaoID = skyBoxMesh->getVaoID();
		glBindVertexArray(vaoID);
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);

		glm::vec3 position = skyBox->getPosition();

		rotationOffsetY += 0.01f;
		rotationOffsetY = std::fmodf(rotationOffsetY, 360.f);

		m_TransformationMatrix = Maths::createTransformationMatrix(position, 1.f, rotationOffsetY, 1.f, skyBox->getScale());
		m_Shader->loadMatrix("transformationMatrix", m_TransformationMatrix);

		TextureAtlas * texture = skyBox->getMesh()->getMaterial()->getTexture();
		if (texture != nullptr) {
			int textureID = texture->getID();
			// std::cout << "SkyBoxRenderer textureID: " << textureID << std::endl;
			texture->bind();
		}

		TextureAtlas * normalMap = skyBox->getMesh()->getMaterial()->getNormalMap();
		if (normalMap != nullptr) {
			int normalMapID = normalMap->getID();
			// std::cout << "SkyBoxRenderer normalMapID: " << normalMapID << std::endl;
			glActiveTexture(GL_TEXTURE1);
			glBindTexture(GL_TEXTURE_2D, normalMapID);		
		}

		int vertexCount = skyBoxMesh->getVertexCount();
		glDrawElements(GL_TRIANGLES, vertexCount, GL_UNSIGNED_INT, 0);

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(2);
		glBindVertexArray(0);
	}

	void SkyBoxRenderer::cleanUp()
	{
		m_Shader->cleanUp();
	}

	SkyBoxRenderer::~SkyBoxRenderer()
	{
	}

} } }
