#include "Component.h"
#include "Entity.h"

namespace prometheus
{
	Component::~Component() {}

	std::shared_ptr<Entity> Component::getEntity()
	{
		return entity.lock();
	}

	std::shared_ptr<Core> Component::getCore()
	{
		return getEntity()->getCore();
	}
}
