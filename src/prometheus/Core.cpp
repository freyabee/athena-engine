#include "Core.h"
#include "Entity.h"
#include "Resources.h"
#include <iostream>
#include "Screen.h"

namespace prometheus
{
	std::shared_ptr<Core> Core::initialize()
	{
		

		//store pointer to core
		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->running = false;
		//set self
		rtn->self = rtn;

		//initialize window
		int windowHeight = 480;
		int windowWidth = 640;
		rtn->screen = std::make_shared<prometheus::Screen>(windowWidth, windowHeight);

		//set rend context ref
		rtn->context = rend::Context::initialize();
		//set resource pool ref
		rtn->resources = std::make_shared<Resources>();
		rtn->resources->core = rtn;


		/*
				AUDIO
				TODO
				-Abstract out to AudioContext class

		*/

		//set device to be new device
		rtn->device = alcOpenDevice(NULL);

		//If problem creating new device throw exception
		if (!rtn->device)
		{
			throw std::exception();
		}

		//create context passing in device
		rtn->audioContext = alcCreateContext(rtn->device, NULL);

		//if context not init throw exception
		if (!rtn->audioContext)
		{
			alcCloseDevice(rtn->device);
			throw std::exception();
		}


		if (!alcMakeContextCurrent(rtn->audioContext))
		{
			alcDestroyContext(rtn->audioContext);
			alcCloseDevice(rtn->device);
			throw std::exception();
		}





		return rtn;
	}

	Core::~Core()
	{
		//Cleanup raw audiocontext and device pointers 
		//and make current context null

		alcMakeContextCurrent(NULL);
		alcDestroyContext(audioContext);
		alcCloseDevice(device);

	}

	
	void Core::start()
	{
		running = true;

		while (running)
		{
			screen->ClearWindow();
			for (std::vector<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); ++it)
			{
				//std::cout << "LOG: GAME LOOP" << std::endl;
				(*it)->onTick();
				(*it)->onDisplay();
				

			}
			screen->SwapWindow();
		}
	}

	void Core::stop()
	{
	}

	std::shared_ptr<Entity> Core::addEntity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
		entities.push_back(rtn);
		rtn->self = rtn;
		rtn->core = self;
		//rtn->addComponent<prometheus::Transform>();
		std::cout << "LOG: Entity made" << std::endl;

		return rtn;
	}
	std::shared_ptr<Environment> Core::getEnvironment()
	{
		return environment;
	}
	std::shared_ptr<Keyboard> Core::getKeyboard()
	{
		return keyboard;
	}
	std::shared_ptr<rend::Context> Core::getContext()
	{
		return context;
	}
	std::shared_ptr<Resources> Core::getResources()
	{
		return resources;
	}

	std::shared_ptr<Screen> Core::getScreen()
	{
		return screen;
	}

	ALCcontext * Core::getAudioContext()
	{
		return audioContext;
	}

}

