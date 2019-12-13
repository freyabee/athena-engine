#include "Component.h"
#include "Transform.h"
#include "Entity.h"
namespace prometheus
{
	std::shared_ptr<Core> Entity::getCore()
	{
		return core.lock();
	}

	Entity::Entity()
	{
		transform = addComponent<Transform>();
	}

	std::shared_ptr<Transform> Entity::GetTransform()
	{
		return transform.lock();
	}

	void Entity::onTick()
	{
		for (std::vector<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); ++it)
		{
			(*it)->onTick();
		}

		

	}

	void Entity::onDisplay()
	{
		for (std::vector<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); ++it)
		{
			(*it)->onDisplay();
		}
	}
}
