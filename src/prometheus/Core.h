#pragma once
#ifndef _CORE_H_
#define _CORE_H_

//Includes
#include <AL/al.h>
#include <AL/alc.h>
#include <memory>
#include <vector>
#include <rend/rend.h>

namespace prometheus
{
	class Entity;
	class Keyboard;
	class Environment;
	class Transform;
	class Resources;
	class Screen;
	class Camera;
	class Mouse;
	class Timer;
	class Gui;
	class AudioContext;

	/// Core holds references to all singleton instances and game loop.
	///
	/// Core initialises and manages references to all game objects in scene and class singletons such as Screen, Camera, etc.
	class Core
	{
	public:
		/// Initialises all references to singleton instances.
		///
		/// Initialises and stores singleton classes as shared pointers to instances.
		static std::shared_ptr<Core> initialize();

		~Core();

		/// Stars game loop, all program functionality called from here.
		///
		/// Entities in scene are iterated through and OnInit, OnTick, OnDisplay and OnGUI functions called on them once per frame.
		void start();
		/// Stops game loop.
		void stop();
		/// Adds entity to vector of scene entities.
		/// Sets core entity to self and adds to entities vector.
		/// @returns Reference to created entity.
		std::shared_ptr<Entity> addEntity();

		/// Get environment instance.
		/// @returns Pointer to  core environment instance.
		std::shared_ptr<Environment> GetEnvironment();
		
		/// Get keyboard instance.
		/// @returns pointer to core keyboard instance.
		std::shared_ptr<Keyboard> GetKeyboard();

		/// Get context instance.
		/// @returns pointer to core context instance.
		std::shared_ptr<rend::Context> GetContext();

		/// Get resources instance.
		/// @returns pointer to core resources instance.
		std::shared_ptr<Resources> GetResources();

		/// Get screen instance.
		/// @returns pointer to core screen instance.
		std::shared_ptr<Screen> GetScreen();

		/// Get camera instance. 
		/// @returns pointer to core camera instance.
		std::shared_ptr<Camera> GetCamera();

		/// Get timer instance.
		/// @returns pointer to core timer instance.
		std::shared_ptr<Timer> GetTimer();
		
		/// Get GUI instance.
		/// @returns pointer to core GUI instance.
		std::shared_ptr<Gui> GetGUI();
		
		/// Get audio context instance.
		/// @returns pointer to core audio context instance.
		std::shared_ptr<AudioContext> GetAudioContext();
		

		/// Template to iterate through entities and find if component of type T is found in each.
		/// @param [in] Pointer to empty vector of entities.
		/// @param [out] Pointer to vector of entities in which component T is found.
		template<typename T>
		void GetEntities(std::vector<std::shared_ptr<Entity>>& vector)
		{
			bool componentFound;

			for (auto it = entities.begin(); it != entities.end(); it++)
			{
				componentFound = (*it)->HasComponent<T>();
				if (componentFound)
				{
					vector.emplace_back(*it);
				}
			}
		}


	private:
		/// Pointer to core environment instance.
		std::shared_ptr<Environment> environment;

		/// Vector holding pointers to entities in scene.
		std::vector<std::shared_ptr<Entity>> entities;

		/// Pointer to core keyboard instance.
		std::shared_ptr<Keyboard> keyboard;
		
		/// Pointer to core context instance.
		std::shared_ptr<rend::Context> context;

		/// Pointer to core screen instance.
		std::shared_ptr<Screen> screen;

		/// Pointer to core camera instance.
		std::shared_ptr<Camera> camera;

		/// Pointer to core mouse instance.
		std::shared_ptr<Mouse> mouse;

		/// Pointer to core timer instance.
		std::shared_ptr<Timer> timer;

		/// Pointer to core GUI instance.
		std::shared_ptr<Gui> gui;

		/// Pointer to core audio context instance.
		std::shared_ptr<AudioContext> audioContext;

		/// Pointer to core resources instance.
		std::shared_ptr<Resources> resources;
		
		/// Weak pointer to the self instance.
		std::weak_ptr<Core> self;

		/// Bool denoting if game loop is running or not.
		bool running;
	};
}

#endif // !_CORE_H_
