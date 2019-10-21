#pragma once
#ifndef _COMPONENT_H_
#define _COMPONENT_H_
//Includes
#include <memory>
namespace prometheus
{
	class Entity;
	class Core;


	class Component
	{
		//friend class can access private and protected members of another class which is declaed as friends.
		friend class Entity;

	public:
		//virtuals = a function declared in a base class that is re-defined in a derived class (override)
		virtual ~Component();

		std::shared_ptr<Core> getCore();
		std::shared_ptr<Entity> getEntity();

	private:
		std::weak_ptr<Entity> entity;

	};
}


#endif // !_COMPONENT_H_
