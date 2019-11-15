#include <iostream>
#include <prometheus/prometheus.h>

int main()
{
	//Initialize core object
	std::shared_ptr<prometheus::Core> core = prometheus::Core::initialize();

	//Initialize entity within core
	std::shared_ptr<prometheus::Entity> entity = core->addEntity();
	
	//add mesh renderer as component
	std::shared_ptr<prometheus::MeshRenderer> renderer = entity->addComponent<prometheus::MeshRenderer>();

	//TODO: load mesh resources into mesh object

	std::shared_ptr<prometheus::Mesh> mesh;

	//TODO:  setMesh in mesh renderer


	core->start();
	//Create entity

	//Initialize openGL window
	std::cout << "Welcome to Prometheus" << std::endl;
	system("pause");
	return 0;
}
