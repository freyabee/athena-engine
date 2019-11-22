#include "Core.h"
#include "Entity.h"
#include "Resources.h"
#include <iostream>


namespace prometheus
{
	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->running = false;
		rtn->self = rtn;
		rtn->context = rend::Context::initialize();
		rtn->resources = std::make_shared<Resources>();
		rtn->resources->core = rtn;

		return rtn;
	}

	void Core::start()
	{
		running = true;

		while (running)
		{
			for (std::vector<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); ++it)
			{
				//std::cout << "LOG: GAME LOOP" << std::endl;
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
		//rtn->addComponent<prometheus::Transform>();
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
	std::shared_ptr<rend::Context> Core::getContext()
	{
		return context;
	}
	std::shared_ptr<Resources> Core::getResources()
	{
		return resources;
	}

}

