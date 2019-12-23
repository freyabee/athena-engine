#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "mathutil.h"
#include "Core.h"
#include "Model.h"
#include "Material.h"

namespace prometheus
{
	void Material::Load(std::string _path)
	{
		shader = core.lock()->GetContext()->createShader();
		shader->parse(_path);
	}
	void Material::LoadShader(std::string _path)
	{
		shader = core.lock()->GetContext()->createShader();
		shader->parse(_path);
	}


	void Material::LoadTexture(std::string _path)
	{
		texture = core.lock()->GetContext()->createTexture();
		int w = 0;
		int h = 0;
		int bpp = 0;
		unsigned char *data = stbi_load("../resources/images/curuthers.png", &w, &h, &bpp, 3);



		if (!data)
		{
			throw rend::Exception("Failed to open image");
		}

		texture->setSize(w, h);

		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				int r = y * w * 3 + x * 3;

				texture->setPixel(x, y, glm::vec3(
					data[r] / 255.0f,
					data[r + 1] / 255.0f,
					data[r + 2] / 255.0f));
			}
		}

		stbi_image_free(data);
	}

	void Material::SetModel(std::shared_ptr<Model> _model)
	{
		shader->setMesh(_model->GetMesh());

	}

	void Material::SetUniform(glm::mat4 _modelMat)
	{
		//rotate(90, vec3(0, 1, 0));


		shader->setUniform("u_Projection", glm::perspective(glm::radians(45.0F), 1.0f, 0.1f, 100.0f));
		// later get this from transform
		//shader->setUniform("u_Model", glm::mat4(1.0f));
		shader->setUniform("u_Model", _modelMat);
		//shader->setUniform("u_Model", translate(vec3(0, 0, -10)));
	}


	std::shared_ptr<rend::Shader> Material::GetShader()
	{
		return shader;
	}

	std::shared_ptr<rend::Texture> Material::GetTexture()
	{
		return texture;
	}


}