#include "Core.h"
#include "Entity.h"
#include <iostream>
namespace prometheus
{
	std::shared_ptr<Core> Core::initialize()
	{
		
		std::shared_ptr<Core> temp = std::make_shared<Core>();
		temp->running = false;
		temp->self = temp;

		return temp;
	}

	void Core::start()
	{
	}

	void Core::stop()
	{
	}

	std::shared_ptr<Entity> Core::addEntity()
	{
		std::shared_ptr<Entity> tempEntity = std::make_shared<Entity>();
		entities.push_back(tempEntity);
		tempEntity->self;
		std::cout << "LOG: Entity made" << std::endl;
		return std::shared_ptr<Entity>(tempEntity);
	}
}

