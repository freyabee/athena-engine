#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "mathutil.h"
#include "Core.h"
#include "Model.h"
#include "Material.h"
#include "Camera.h"



namespace prometheus
{
	void Material::Load(std::string path)
	{
		shader = core.lock()->GetContext()->createShader();
		texture = core.lock()->GetContext()->createTexture();
	}
	void Material::LoadShader(std::string shaderPath)
	{
		shader = core.lock()->GetContext()->createShader();
		shader->ParseFromPath(shaderPath);
	}
	void Material::LoadTexture(std::string texturePath)
	{
		texture = core.lock()->GetContext()->createTexture();
		int w = 0;
		int h = 0;
		int bpp = 0;
		unsigned char *data = stbi_load(texturePath.c_str(), &w, &h, &bpp, 3);



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

	void Material::LoadTexture(std::string texturePath, std::shared_ptr<Core> core)
	{
		this->core = core;
		texture = core->GetContext()->createTexture();
		int w = 0;
		int h = 0;
		int bpp = 0;
		stbi_set_flip_vertically_on_load(true);
		unsigned char *data = stbi_load(texturePath.c_str(), &w, &h, &bpp, 4);



		if (!data)
		{
			throw rend::Exception("Failed to open image");
		}

		try
		{
			texture->setSize(w, h);
			for (int y = 0; y < h; y++)
			{
				for (int x = 0; x < w; x++)
				{
					int r = y * w * 4 + x * 4;

					texture->setPixel(x, y, glm::vec4(
						data[r] / 255.0f,
						data[r + 1] / 255.0f,
						data[r + 2] / 255.0f,
						data[r + 3] / 255.0f));
				}
			}
			
		}
		catch (std::exception&e)
		{
			std::cout << "Problem writing pixels to texture: " << e.what() << std::endl;
		}
		

		if (data)
		{
			stbi_image_free(data);
		}
		
	}



	void Material::SetModel(std::shared_ptr<Model> model)
	{
		shader->setMesh(model->GetMesh());

	}

	void Material::SetUniform(glm::mat4 modelMat)
	{
		shader->setUniform("u_Projection", GetCamera()->GetProjection());
		shader->setUniform("u_View", GetCamera()->GetView());
		shader->setUniform("u_Model", modelMat);
	}

	std::shared_ptr<rend::Shader> Material::GetShader()
	{
		return shader;
	}

	std::shared_ptr<rend::Texture> Material::GetTexture()
	{
		return texture;
	}

	std::shared_ptr<Camera> Material::GetCamera()
	{
		return core.lock()->GetCamera();
	}


}