#include "mathutil.h"

#include "Material.h"
#include "Core.h"
#include "Model.h"


namespace prometheus
{
	void Material::load(std::string path)
	{
		shader = core.lock()->getContext()->createShader();
		shader->parse(src);
	}

	void Material::setModel(std::shared_ptr<Model> model)
	{
		shader->setMesh(model->getMesh());
	}

	void Material::setUniform()
	{
		rotate(radians(90), vec3(0, 1, 0));

		shader->setUniform("u_Projection", glm::perspective(glm::radians(45.0F), 1.0f, 0.1f, 100.0f));
		// later get this from transform
		shader->setUniform("u_Model",
			translate(vec3(0, 0, -10)) *
			
		);
	}

	std::shared_ptr<rend::Shader> Material::getMaterial()
	{
		return shader;
	}

}