#include "Core.h"
#include "Entity.h"

namespace prometheus
{
	std::shared_ptr<Core> Core::initialize()
	{
		return std::shared_ptr<Core>();
	}

	void Core::start()
	{
	}

	void Core::stop()
	{
	}

	std::shared_ptr<Entity> Core::addEntity()
	{
		std::shared_ptr<Entity> tempEntity;
		entities.push_back(tempEntity);
		return std::shared_ptr<Entity>(tempEntity);
	}
}

