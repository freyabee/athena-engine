#include <iostream>
#include <prometheus/prometheus.h>

int main()
{
	//Initialize core object
	std::shared_ptr<prometheus::Core> core = prometheus::Core::initialize();
	std::shared_ptr<prometheus::Entity> entity = core->addEntity();


	//Create entity
	
	//Initialize openGL window
	std::cout << "Welcome to Prometheus" << std::endl;
	system("pause");
	return 0;
}
