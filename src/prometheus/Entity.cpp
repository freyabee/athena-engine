#include "Entity.h"
namespace prometheus
{
	std::shared_ptr<Core> Entity::getCore()
	{
		return core.lock();
	}

	void Entity::tick()
	{
	}

	void Entity::display()
	{
	}
}
