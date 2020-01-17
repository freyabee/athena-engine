#include "MeshRenderer.h"
#include "Entity.h"
#include "Screen.h"
#include "Model.h"
#include "Transform.h"
#include "Material.h"
#include "Resources.h"
#include "Model.h"
#include "Core.h"
#include "Camera.h"
namespace prometheus
{
	MeshRenderer::MeshRenderer()
	{
	}
	MeshRenderer::~MeshRenderer()
	{
	}
	void MeshRenderer::SetModel(std::shared_ptr<Model> model)
	{
		this->model = model;
	}
	void MeshRenderer::SetMaterial(std::shared_ptr<Material> mat)
	{
		try
		{
			std::cout << "Loading material to mesh renderer: ";
			this->material = mat;
			model->GetMesh()->setTexture("u_Texture", mat->GetTexture());
			std::cout << "success" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "failed with error " << e.what() << std::endl;
		}
		
	}
	bool MeshRenderer::LoadModel(std::string modelPath, std::string texturePath, std::string shaderPath)
	{
		try
		{
			std::cout << "Loading model at " << modelPath << ": ";
			std::shared_ptr<prometheus::Model> model = GetEntity()->GetCore()->GetResources()->load<prometheus::Model>(modelPath);
			this->model = model;
			std::cout << "success" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "failed with error " << e.what() << std::endl;
		}

		try
		{
			std::cout << "Loading shader at " << shaderPath << ": ";
			std::shared_ptr<prometheus::Material> material = GetEntity()->GetCore()->GetResources()->load<prometheus::Material>(shaderPath);
			this->material = material;
			material->LoadShader(shaderPath);
			std::cout << "success" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "failed with error " << e.what() << std::endl;
		}
		
		try
		{
			std::cout << "Loading texture at " << texturePath << ": ";
			material->LoadTexture(texturePath);
			model->GetMesh()->setTexture("u_Texture", material->GetTexture());
			std::cout << "success" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "failed with error " << e.what() << std::endl;
		}
		return true;

	}
	bool MeshRenderer::LoadSkybox(std::string modelPath, std::string shader, std::vector<std::string> texturepaths)
	{
		std::shared_ptr<prometheus::Model> model = GetEntity()->GetCore()->GetResources()->load<prometheus::Model>(modelPath);
		this->model = model;
		std::cout << "Model at '" << modelPath << "' loaded successfully." << std::endl;

		std::shared_ptr<prometheus::Material> _material = GetEntity()->GetCore()->GetResources()->load<prometheus::Material>(shader);
		material = material;
		material->LoadShader(shader);
		return true;
	}

	void MeshRenderer::OnInit()
	{

	}
	void MeshRenderer::OnDisplay()
	{
		material->SetUniform(GetEntity()->GetTransform()->GetModelMatrix());
		material->SetModel(model);
		material->GetShader()->render();
	}
	void MeshRenderer::OnTick()
	{
	}
}