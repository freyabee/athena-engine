#include "Component.h"
#include "Entity.h"
#include "Core.h"

namespace prometheus
{
	Component::~Component() {}

	void Component::setEntity(std::weak_ptr<Entity> _entity)
	{
		entity = _entity;
	}

	std::shared_ptr<Entity> Component::getEntity()
	{
		return entity.lock();
	}

	std::shared_ptr<Keyboard> Component::getKeyboard()
	{
		return getEntity()->getCore()->getKeyboard();
	}

	std::shared_ptr<Environment> Component::getEnvironment()
	{
		return getEntity()->getCore()->getEnvironment();
	}

	std::shared_ptr<Screen> Component::getScreen()
	{
		return getEntity()->getCore()->getScreen();
	}

	std::shared_ptr<Core> Component::getCore()
	{
		return getEntity()->getCore();
	}

}
