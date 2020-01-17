#include "Component.h"
#include "Transform.h"
#include "Entity.h"

namespace prometheus
{
	std::shared_ptr<Core> Entity::GetCore()
	{
		return core.lock();
	}

	Entity::Entity()
	{
		transform = addComponent<Transform>();
	}

	Entity::Entity(std::string entityName)
	{
		transform = addComponent<Transform>();
		this->entityName = entityName;
	}

	void Entity::SetPosition(glm::vec3 position)
	{
		GetTransform()->SetLocalPosition(position);
	}

	void Entity::SetRotation(glm::vec3 rotation)
	{
		GetTransform()->SetLocalRotation(rotation);
	}

	std::shared_ptr<Transform> Entity::GetTransform()
	{
		return transform.lock();
	}

	std::string Entity::GetEntityName()
	{
		return entityName;
	}

	void Entity::OnTick()
	{
		for (std::vector<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); ++it)
		{
			(*it)->OnTick();
		}
	}

	void Entity::OnDisplay()
	{
		for (std::vector<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); ++it)
		{
			(*it)->OnDisplay();
		}
	}
	void Entity::OnInit()
	{
		for (std::vector<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); ++it)
		{
			(*it)->OnInit();
		}
	}
	void Entity::OnGUI()
	{
		for (std::vector<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); ++it)
		{
			(*it)->OnGUI();
		}
	}
	void Entity::OnEarlyUpdate()
	{
		for (std::vector<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); ++it)
		{
			(*it)->OnEarlyUpdate();
		}

	}
}
