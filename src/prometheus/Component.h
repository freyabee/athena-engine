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
	class Screen;

	class Component
	{
		//friend class can access private and protected members of another class which is declared as friends.
		friend class Entity;

	public:
		//virtuals = a function declared in a base class that is re-defined in a derived class (override)
		~Component();
		std::shared_ptr<Core> GetCore();
		std::shared_ptr<Entity> GetEntity();
		std::shared_ptr<Keyboard> GetKeyboard();
		std::shared_ptr<Environment> GetEnvironment();
		std::shared_ptr<Screen> GetScreen();
	protected:
		
		virtual void onInit() {};
		virtual void onBegin() {};
		virtual void onTick() {};
		virtual void onDisplay() {};

	private:
		void SetEntity(std::weak_ptr<Entity> _entity);
		std::weak_ptr<Entity> entity;

	};
}


#endif // !_COMPONENT_H_
