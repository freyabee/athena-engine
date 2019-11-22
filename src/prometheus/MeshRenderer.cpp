#include "MeshRenderer.h"

#include "Screen.h"
#include "Model.h"
#include "Material.h"
namespace prometheus
{
	MeshRenderer::MeshRenderer()
	{
		windowHeight = 480;
		windowWidth = 640;





		screen = std::make_shared<prometheus::Screen>(windowWidth, windowHeight);
		std::string s = "PLACEHOLDER";
		try
		{
			//model->load(s);
		}
		catch (const std::exception&)
		{
			std::cout << "ERROR: Model Load Failed" << std::endl;
		}
		try
		{
			//material->load(s);
		}
		catch (const std::exception&)
		{
			std::cout << "ERROR: Material Load Failed" << std::endl;
		}
		



		std::cout << "End of constructor reached" << std::endl;
		bool quit = false;

	}
	MeshRenderer::~MeshRenderer()
	{
		screen->DestroyScreen();
	}
	void MeshRenderer::setModel(std::shared_ptr<Model> _model)
	{
		this->model = _model;
	}
	void MeshRenderer::setMaterial(std::shared_ptr<Material> _mat)
	{
		this->material = _mat;
	}
	void MeshRenderer::onInit()
	{
	}
	void MeshRenderer::onDisplay()
	{
		screen->ClearWindow();
		material->setUniform();
		material->setModel(model);
		material->getMaterial()->render();
		screen->SwapWindow();
	}
	void MeshRenderer::onTick()
	{
	}
}