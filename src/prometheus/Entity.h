#pragma once
#ifndef _ENTITY_H_
#define _ENTITY_H_

//Includes
#include <vector>
#include <memory>
class Component;
class Core;
//Body
namespace prometheus
{
	class Entity
	{
		friend class Core;
	public:
		//Functions
		std::shared_ptr<Core> getCore();

		//Templated add components
		template<typename T> std::shared_ptr<T> addComponent()
		{
			return std::shared_ptr<T>();
		}
		template<typename T, typename A> std::shared_ptr<T> addComponent(A _a)
		{
			return std::shared_ptr<T>();
		}
		template<typename T, typename A, typename B> std::shared_ptr<T> addComponent(A _a, B _b)
		{
			return std::shared_ptr<T>();
		}
		template<typename T, typename A, typename B, typename C> std::shared_ptr<T> addComponent(A _a, B _b, C _c)
		{
			return std::shared_ptr<T>();
		}

	private:
		//Variables
		std::vector<std::shared_ptr<Component>> components;
		std::weak_ptr<Core> core;

		//Functions
		void tick();
		void display();

	};

}

#endif // !_ENTITY_H_