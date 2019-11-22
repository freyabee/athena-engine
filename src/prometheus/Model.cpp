#include "Model.h"
#include "Core.h"

namespace prometheus
{
	void Model::load(std::string path)
	{
		std::shared_ptr<rend::Context> context = core.lock()->getContext();


		mesh = context->createMesh();
		mesh->parse(obj);
	}
	std::shared_ptr<rend::Mesh> Model::getMesh()
	{
		return mesh;
	}
}