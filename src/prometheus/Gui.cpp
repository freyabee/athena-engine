#include "Model.h"
#include "Core.h"
#include "Resources.h"
#include "Material.h"
#include <exception>
#include "Gui.h"

namespace prometheus
{
	Gui::Gui()
	{
	}
	Gui::~Gui()
	{
	}
	void Gui::LoadButtonMesh(std::string path)
	{
		std::shared_ptr<prometheus::Model> model = GetCore()->GetResources()->load<prometheus::Model>(path);
		this->model = model;
	}
	void Gui::LoadButtonMaterial(std::string shaderPath, std::string texturePath)
	{

		std::shared_ptr<prometheus::Material> material = GetCore()->GetResources()->load<prometheus::Material>(shaderPath);
		material->LoadShader(shaderPath);
		material->LoadTexture(texturePath);

	}
	std::shared_ptr<Core> Gui::GetCore()
	{
		return core.lock();
	}
}