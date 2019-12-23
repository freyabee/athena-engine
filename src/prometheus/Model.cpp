#include <fstream>
#include <iostream>

#include "Model.h"
#include "Core.h"




namespace prometheus
{
	void Model::Load(std::string path)
	{
		std::shared_ptr<rend::Context> context = core.lock()->GetContext();
		mesh = context->createMesh();

		std::ifstream f(path);
		std::string line;

		while (!f.eof())
		{
			std::getline(f, line);
			obj += line + "\n";
		}

		mesh->parse(obj);
	}
	std::shared_ptr<rend::Mesh> Model::GetMesh()
	{
		return mesh;
	}
}