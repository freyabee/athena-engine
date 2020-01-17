#pragma once
#ifndef _ENTITY_H_
#define _ENTITY_H_


#include <vector>
#include <memory>
#include "Component.h"
#include <glm/glm.hpp>
#include <exception>

namespace prometheus
{
	class Core;
	class Transform;

	/// Class to create entities in the scenee.
	///
	/// Holds functions for the creation of entities, and the adding of different types of components to the entity.
	class Entity
	{
		friend class Core;


	public:
		
		/// Returns a pointer to current active core instance.
		///
		/// @returns Pointer to core instance.
		std::shared_ptr<Core> GetCore();
		
		/// Entity constructor.
		///
		/// Adds transform component to entity automatically.
		Entity();

		/// Entity constructor with optional naming string.
		/// Sets entityName to the input parameter.
		/// @param entityName New entityName string.
		Entity(std::string entityName);
		
		/// Adds component to entity.
		/// Adds component type T to entity and sets component's entity to self.
		/// @returns Pointer to component type T
		template<typename T> std::shared_ptr<T> addComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->SetEntity(self);
			components.push_back(rtn);
			return rtn;
		}

		/// Adds component to entity.
		/// Takes component type T with one parameter type A and adds to entity.
		/// Sets component's entity to self.
		/// @returns Pointer to component type T
		template<typename T, typename A> std::shared_ptr<T> addComponent(A _a)
		{
			std::shared_ptr<T> rtn = std::make_shared<T>(_a);
			rtn->SetEntity(self);
			components.push_back(rtn);
			return rtn;
		}

		/// Adds component to entity.
		/// Takes component type T with two parameter types A and B and adds to entity.
		/// Sets component's entity to self.
		/// @returns Pointer to component type T.
		template<typename T, typename A, typename B> std::shared_ptr<T> addComponent(A _a, B _b)
		{
			std::shared_ptr<T> rtn = std::make_shared<T>(_a, _b);
			rtn->SetEntity(self);
			components.push_back(rtn);
			return rtn;
		}

		/// Adds component to entity.
		/// Takes component type T with three parameter types, A, B and C and adds to entity.
		/// Sets component's entity to self.
		/// @retruns Pointer to component type T.
		template<typename T, typename A, typename B, typename C> std::shared_ptr<T> addComponent(A _a, B _b, C _c)
		{
			std::shared_ptr<T> rtn = std::make_shared<T>(_a, _b, _c);
			rtn->SetEntity(self);
			components.push_back(rtn);
			return rtn;
		}
		/// Retrieves reference to component of type T from entity.
		///
		/// @returns shared_ptr of type T
		template<typename T> std::shared_ptr<T> GetComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			for (auto it = components.begin(); it != components.end(); it++)
			{
				rtn = std::dynamic_pointer_cast<T>(*it);

				if (rtn)
				{
					return rtn;
				}
			}
			throw std::exception("Component not found");
		}

		/// Checks vector of components in entity for component of type T.
		///
		/// @returns boolean denoting presence of component of type T in entity component vector.
		/// @see GetComponent()
		template<typename T> bool HasComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			for (auto it = components.begin(); it != components.end(); it++)
			{
				rtn = std::dynamic_pointer_cast<T>(*it);

				if (rtn)
				{
					return true;
				}
			}
			return false;
		}
		/// Sets position of entity transform to input.
		/// Calls transform's SetLocalRotation with input.
		/// @param position Vec3 holding new local position.
		void SetPosition(glm::vec3 position);

		/// Sets rotation of entity transform to input.
		/// Calls transform's SetLocalRotation function with input.
		/// @param rotation Vec3 holding new local rotation.
		void SetRotation(glm::vec3 rotation);

		/// Gets pointer to entity's transform.
		/// Returns pointer to entity's transform.
		/// @returns Pointer to entity's transform.
		std::shared_ptr<Transform> GetTransform();

		/// Get unique entity name.
		/// Returns entity name string.
		/// @returns entityName string.
		std::string GetEntityName();

	private:
		/// Reference to current instance of core.
		std::weak_ptr<Core> core;
		
		/// Weak pointer to entity's transform.
		std::weak_ptr<Transform> transform;

		/// Weak pointer to self.
		std::weak_ptr<Entity> self;

		/// Vector of pointers to components.
		/// Holds pointers to componenets that have been added to the entity.
		std::vector<std::shared_ptr<Component>> components;
		
		/// String holding meaninful name of entity.
		std::string entityName;
		
		/// Calls OnTick for every component attached to entity.
		/// Iterates through components vector calling components Component::OnTick() function.
		void OnTick();

		/// Calls OnDisplay for every component attached to entity.
		/// Iterates through components vector calling components Component::OnDisplay function.
		void OnDisplay();

		/// Calls OnInit for every component attached to entity.
		/// Iterates through components vector calling components Component::OnInit() function.
		void OnInit();

		/// Calls OnGUI for every component attached to entity.
		/// Iterates through components vector calling components Component::OnGUI() function.
		void OnGUI();

		/// Calls OnEarlyUpdate for every component attached to entity.
		/// Iterates through components vector calling components Component::OnEarlyUpdate() function.
		void OnEarlyUpdate();
		
	};

}

#endif // !_ENTITY_H_