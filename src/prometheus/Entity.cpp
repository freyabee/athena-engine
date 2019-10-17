#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

std::shared_ptr<Core> Entity::getCore()
{
	return std::shared_ptr<Core>();
}

void Entity::tick()
{
}

void Entity::display()
{
}