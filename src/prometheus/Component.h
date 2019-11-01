#pragma once
#ifndef _COMPONENT_H_
#define _COMPONENT_H_
//Includes
#include <memory>

namespace prometheus
{
	class Core;
	class Entity;
	class Keyboard;
	class Environment;


	class Component
	{
		//friend class can access private and protected members of another class which is declaed as friends.
		friend class Entity;

	public:
		//virtuals = a function declared in a base class that is re-defined in a derived class (override)
		~Component();

		std::shared_ptr<Core> getCore();
		std::shared_ptr<Entity> getEntity();
		std::shared_ptr<Keyboard> getKeyboard();
		std::shared_ptr<Environment> getEnvironment();

	protected:
		std::weak_ptr<Entity> entity;
		virtual void onInit() {};
		virtual void onBegin() {};
		virtual void onTick() {};
		virtual void onDisplay() {};

	};
}


#endif // !_COMPONENT_H_
