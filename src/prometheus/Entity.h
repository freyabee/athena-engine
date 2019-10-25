#pragma once
#ifndef _ENTITY_H_
#define _ENTITY_H_

//Includes
#include <vector>
#include <memory>

//Body
namespace prometheus
{
	class Component;
	class Core;
	class Entity
	{
		friend class Core;
	public:
		//Functions
		
		std::shared_ptr<Core> getCore();

		//Templated add components
		template<typename T> std::shared_ptr<T> addComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			components.push_back(rtn);
			return rtn;
		}
		template<typename T, typename A> std::shared_ptr<T> addComponent(A _a)
		{
			std::shared_ptr<T> rtn = std::make_shared<T>(_a);
			components.push_back(rtn);
			return rtn;
		}
		template<typename T, typename A, typename B> std::shared_ptr<T> addComponent(A _a, B _b)
		{
			std::shared_ptr<T> rtn = std::make_shared<T>(_a, _b);
			components.push_back(rtn);
			return rtn;
		}
		template<typename T, typename A, typename B, typename C> std::shared_ptr<T> addComponent(A _a, B _b, C _c)
		{
			std::shared_ptr<T> rtn = std::make_shared<T>(_a, _b, _c);
			components.push_back(rtn);
			return rtn;
		}

	private:
		//Variables
		std::vector<std::shared_ptr<Component>> components;
		std::weak_ptr<Core> core;

		//Functions
		void onTick();
		void onDisplay();
		std::weak_ptr<Entity> self;
	};

}

#endif // !_ENTITY_H_