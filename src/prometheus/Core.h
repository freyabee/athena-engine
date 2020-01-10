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

	class Core
	{
	public:
		//Functions		
		static std::shared_ptr<Core> initialize();
		~Core();
		void start();
		void stop();
		std::shared_ptr<Entity> addEntity();

		std::shared_ptr<Environment> GetEnvironment();
		std::shared_ptr<Keyboard> GetKeyboard();
		std::shared_ptr<rend::Context> GetContext();
		std::shared_ptr<Resources> GetResources();
		std::shared_ptr<Screen> GetScreen();
		std::shared_ptr<Camera> GetCamera();
		ALCcontext* GetAudioContext();
		std::shared_ptr<Timer> GetTimer();
		
		template<typename T>
		void GetEntities(std::vector<std::shared_ptr<Entity>>& _vector)
		{
			bool componentFound;

			for (auto it = entities.begin(); it != entities.end(); it++)
			{
				componentFound = (*it)->GetComponent<T>();
				if (componentFound)
				{
					_vector.emplace_back();
				}
			}
		}


	private:
		//Variables
		std::shared_ptr<Environment> environment;
		std::vector<std::shared_ptr<Entity>> entities;//Vec holding entities in this core
		std::shared_ptr<Keyboard> keyboard;
		std::shared_ptr<rend::Context> context;
		std::shared_ptr<Screen> screen;
		std::shared_ptr<Camera> camera;
		std::shared_ptr<Mouse> mouse;
		std::shared_ptr<Timer> timer;
		//audio
		ALCcontext* audioContext;
		ALCdevice* device;
		//resources
		std::shared_ptr<Resources> resources;
		//environment

		//core variables
		std::weak_ptr<Core> self;
		bool running;
	};
}

#endif // !_CORE_H_
