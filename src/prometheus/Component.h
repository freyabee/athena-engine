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
	class Transform;
	class Camera;

	/// Class defining component instance.
	///
	/// Components are part of the entity-component system. Component is a virtual function that will be inherited from to build new components.
	class Component
	{
		//friend class can access private and protected members of another class which is declared as friends.
		friend class Entity;

	public:
		//virtuals = a function declared in a base class that is re-defined in a derived class (override)
		~Component();
		
		/// Get current core instance.
		/// @returns Pointer to current core instance.
		std::shared_ptr<Core> GetCore();
		/// Get entity that this component is parented to.
		/// @returns Pointer to parent entity.
		std::shared_ptr<Entity> GetEntity();
		/// Get keyboard instance in core.
		/// @returns Pointer to keyboard instance in core.
		std::shared_ptr<Keyboard> GetKeyboard();
		/// Get environment instance in core.
		/// @returns Pointer to environment instance in core.
		std::shared_ptr<Environment> GetEnvironment();
		/// Get screen instance in core.
		/// @returns Pointer to screen instance in core.
		std::shared_ptr<Screen> GetScreen();
		/// Get transform of parent entity.
		/// @returns Pointer to parent entity's transform.
		std::shared_ptr<Transform> GetTransform();
		/// Get camera instance in core.
		/// @returns Pointer to camera instance in core.
		std::shared_ptr<Camera> GetCamera();

	protected:
		/// Virtual initialisation function
		/// Called at the begininning of game loop in core.
		virtual void OnInit() {};
		/// Virtual on tick function.
		/// Will be overridden in child classes, called in the tick loop in core game loop.
		virtual void OnTick() {};
		/// Virtual on display function.
		/// Will be overriden in child classes, called after tick loop in core game loop.
		virtual void OnDisplay() {};
		/// Virtual on GUI function.
		/// Will be overriden in child classes, called after tick and display loop in game loop.
		virtual void OnGUI() {};

		/// Virtual on early update function.
		/// Will be overidden in child classes, called before on tick in game loop.
		virtual void OnEarlyUpdate() {};

	private:
		/// Set parent entity from input.
		/// @param entity New parent entity.
		void SetEntity(std::weak_ptr<Entity> entity);
		/// Reference to parent entity.
		std::weak_ptr<Entity> entity;

	};
}


#endif // !_COMPONENT_H_
