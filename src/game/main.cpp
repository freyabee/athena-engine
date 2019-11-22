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
	
	//Load Resources
	std::shared_ptr<prometheus::Model> m1 = core->getResources()->load<prometheus::Model>("models/triangle");
	//TODO:  setMesh in mesh renderer
	renderer->setModel(m1);

	std::shared_ptr<prometheus::Material> mat1 = core->getResources()->load<prometheus::Material>("shaders/simple");
	renderer->setMaterial(mat1);

	core->start();
	//Create entity

	//Initialize openGL window
	std::cout << "Welcome to Prometheus" << std::endl;
	system("pause");
	return 0;
}
