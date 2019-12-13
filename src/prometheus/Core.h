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

	class Core
	{
	public:
		//Functions		
		static std::shared_ptr<Core> initialize();
		~Core();
		void start();
		void stop();
		std::shared_ptr<Entity> addEntity();

		std::shared_ptr<Environment> getEnvironment();
		std::shared_ptr<Keyboard> getKeyboard();
		std::shared_ptr<rend::Context> getContext();
		std::shared_ptr<Resources> getResources();
		std::shared_ptr<Screen> getScreen();
		ALCcontext* getAudioContext();

	private:
		//Variables
		std::shared_ptr<Environment> environment;
		std::vector<std::shared_ptr<Entity>> entities;//Vec holding entities in this core
		std::shared_ptr<Keyboard> keyboard;
		std::shared_ptr<rend::Context> context;
		std::shared_ptr<Screen> screen;
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
