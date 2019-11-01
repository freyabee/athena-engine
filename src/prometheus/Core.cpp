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
		running = true;

		while (running)
		{
			for (std::vector<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); ++it)
			{
				std::cout << "LOG: GAME LOOP" << std::endl;
				(*it)->onTick();
				(*it)->onDisplay();

			}
		}
	}

	void Core::stop()
	{
	}

	std::shared_ptr<Entity> Core::addEntity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
		entities.push_back(rtn);
		rtn->self;
		rtn->addComponent<Transform>();
		std::cout << "LOG: Entity made" << std::endl;

		return rtn;
	}
	std::shared_ptr<Environment> Core::getEnvironment()
	{
		return environment;
	}
	std::shared_ptr<Keyboard> Core::getKeyboard()
	{
		return keyboard;
	}
}

