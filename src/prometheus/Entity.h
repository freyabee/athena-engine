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
	class Transform;


	class Entity
	{
		friend class Core;


	public:
		
		std::shared_ptr<Core> GetCore();
		Entity();
		Entity(std::string _entityName);
		//Templated add components
		template<typename T> std::shared_ptr<T> addComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->SetEntity(self);
			components.push_back(rtn);
			return rtn;
		}
		template<typename T, typename A> std::shared_ptr<T> addComponent(A _a)
		{
			std::shared_ptr<T> rtn = std::make_shared<T>(_a);
			rtn->SetEntity(self);
			components.push_back(rtn);
			return rtn;
		}
		template<typename T, typename A, typename B> std::shared_ptr<T> addComponent(A _a, B _b)
		{
			std::shared_ptr<T> rtn = std::make_shared<T>(_a, _b);
			rtn->SetEntity(self);
			components.push_back(rtn);
			return rtn;
		}
		template<typename T, typename A, typename B, typename C> std::shared_ptr<T> addComponent(A _a, B _b, C _c)
		{
			std::shared_ptr<T> rtn = std::make_shared<T>(_a, _b, _c);
			rtn->SetEntity(self);
			components.push_back(rtn);
			return rtn;
		}


		std::shared_ptr<Transform> GetTransform();
		std::string GetEntityName();

	private:
		//Variables
		std::vector<std::shared_ptr<Component>> components;
		std::weak_ptr<Core> core;
		std::weak_ptr<Transform> transform;
		std::string entityName;
		//Functions
		void onTick();
		void onDisplay();
		std::weak_ptr<Entity> self;
	};

}

#endif // !_ENTITY_H_