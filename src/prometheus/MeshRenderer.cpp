#include "MeshRenderer.h"
#include "Entity.h"
#include "Screen.h"
#include "Model.h"
#include "Transform.h"
#include "Material.h"
#include "Resources.h"
#include "Model.h"
#include "Core.h"
namespace prometheus
{
	MeshRenderer::MeshRenderer()
	{
	}
	MeshRenderer::~MeshRenderer()
	{
	}
	void MeshRenderer::SetModel(std::shared_ptr<Model> _model)
	{
		this->model = _model;
	}
	void MeshRenderer::SetMaterial(std::shared_ptr<Material> _mat)
	{
		this->material = _mat;
		model->GetMesh()->setTexture("u_Texture", _mat->GetTexture());
	}
	bool MeshRenderer::LoadModel(std::string _modelPath, std::string _texturePath, std::string _shader)
	{
		std::shared_ptr<prometheus::Model> _model = GetEntity()->GetCore()->GetResources()->load<prometheus::Model>(_modelPath);
		this->model = _model;
		std::cout << "Model at '" << _modelPath << "' loaded successfully." << std::endl;


		std::shared_ptr<prometheus::Material> _material = GetEntity()->GetCore()->GetResources()->load<prometheus::Material>(_shader);
		this->material = _material;
		this->material->LoadShader(_shader);
		this->material->LoadTexture(_texturePath);
		std::cout << "Material at '" << _texturePath << "' loaded successfully." << std::endl;

		model->GetMesh()->setTexture("u_Texture", material->GetTexture());
	

		std::cout << "End of constructor reached" << std::endl;
		return true;
	}
	void MeshRenderer::onInit()
	{

	}
	void MeshRenderer::onDisplay()
	{
		
		material->SetUniform(*GetEntity()->GetTransform()->GetModelMatrix());
		material->SetModel(model);
		material->GetShader()->render();

		
	}
	void MeshRenderer::onTick()
	{
	}
}