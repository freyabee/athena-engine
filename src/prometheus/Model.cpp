#include <fstream>
#include <iostream>
#include "Model.h"
#include "Core.h"




namespace prometheus
{
	void Model::Load(std::string path)
	{
		try
		{
			std::shared_ptr<rend::Context> context = core.lock()->GetContext();
			mesh = context->createMesh();

			std::ifstream file(path);
			std::string line;

			if (!file.is_open())
			{
				throw (rend::Exception("Failed to open model at : " + path));
			}
			else
			{
				while (!file.eof())
				{
					std::getline(file, line);
					obj += line + "\n";
				
				}
				mesh->parse(obj);
			}
		}
		catch (std::exception & e)
		{
			std::cout << "Problem parsing model " << path << " : " << e.what() << std::endl;
		}
		
	}
	std::shared_ptr<rend::Mesh> Model::GetMesh()
	{
		return mesh;
	}
}