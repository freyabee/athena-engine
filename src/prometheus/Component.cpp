#include "Component.h"
#include "Entity.h"
#include "Core.h"
#include "Transform.h"
namespace prometheus
{
	Component::~Component() {}

	void Component::SetEntity(std::weak_ptr<Entity> _entity)
	{
		entity = _entity;
	}



	std::shared_ptr<Entity> Component::GetEntity()
	{
		return entity.lock();
	}

	std::shared_ptr<Keyboard> Component::GetKeyboard()
	{
		return GetEntity()->GetCore()->GetKeyboard();
	}

	std::shared_ptr<Environment> Component::GetEnvironment()
	{
		return GetEntity()->GetCore()->GetEnvironment();
	}

	std::shared_ptr<Screen> Component::GetScreen()
	{
		return GetEntity()->GetCore()->GetScreen();
	}

	std::shared_ptr<Transform> Component::GetTransform()
	{
		return GetEntity()->GetTransform();
	}


	std::shared_ptr<Core> Component::GetCore()
	{
		return GetEntity()->GetCore();
	}

}
