#include <iostream>
#include <prometheus/prometheus.h>

int main()
{
	//Initialize core object
	std::shared_ptr<Core> core = Core::initialize();
	//Create entity?
	core->addEntity();

	//Initialize openGL window
	std::cout << "Welcome to Prometheus" << std::endl;
	system("pause");
	return 0;
}