#include "Keyboard.h"
#include "Entity.h"
#include "Resources.h"
#include <iostream>
#include "Screen.h"
#include "Environment.h"
#include "Transform.h"
#include "Camera.h"
#include "Mouse.h"
#include "Timer.h"
#include "Gui.h"
#include "Core.h"

namespace prometheus
{
	std::shared_ptr<Core> Core::initialize()
	{

		std::cout << "Core initalization starting:" << std::endl;

		std::shared_ptr<Core> rtn = std::make_shared<Core>();

		std::cout << "Initialising self"<< std::endl;
		rtn->running = false;
		rtn->self = rtn;

		
		try
		{
			std::cout << "Initialising timer: ";

			rtn->timer = std::make_shared<Timer>();

			std::cout << "success" << std::endl;
		}
		catch (const std::exception& e)
		{
		std::cout << "failure" << std::endl;
		std::cout << &e << std::endl;
		}
		
		int windowHeight =800;
		int windowWidth = 800;

		try
		{
			std::cout << "Initialising window: ";
			
			rtn->screen = std::make_shared<prometheus::Screen>(windowWidth, windowHeight);

			std::cout << "success" << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "failed" << std::endl;
			std::cout << &e << std::endl;
		}


		

		/* Initialise Rend Context */
		rtn->context = rend::Context::initialize();
		/* Initialise pool of resources*/
		rtn->resources = std::make_shared<Resources>();
		rtn->resources->core = rtn;

		/* Initialize environment */
		rtn->environment = std::make_shared<Environment>();
		/* Initialize Keyboard */
		rtn->keyboard = std::make_shared<Keyboard>();
		/* Initialize Mouse */
		rtn->mouse = std::make_shared<Mouse>(windowWidth, windowHeight);
		/* Initialize Camera */
		rtn->camera = std::make_shared<Camera>(rtn->keyboard, rtn->mouse, rtn->timer);

		rtn->gui = std::make_shared<Gui>(rtn);
		/*
				AUDIO
				TODO
				-Abstract out to AudioContext class
		*/

		//Set device to be new device
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

		
		
		
		std::cout << "Core initalization completed in " << rtn->timer->GetTimeS() << "s." << std::endl;

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
		environment->Initialize();
		camera->Initialize();
		gui->OnInit();

		for (std::vector<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); ++it)
		{
			(*it)->OnInit();
		}


		while (running)
		{
			mouse->OnTick();
			keyboard->OnTick();
			
			timer->OnTick();

			screen->ClearWindow();
			//On tick
			for (std::vector<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); ++it)
			{
				//std::cout << "LOG: GAME LOOP" << std::endl;
				(*it)->OnTick();
			}

			camera->OnTick();

			for (std::vector<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); ++it)
			{
					//std::cout << "LOG: GAME LOOP" << std::endl;
					(*it)->OnDisplay();
				
			}

			for (std::vector<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); ++it)
			{
				//std::cout << "LOG: GAME LOOP" << std::endl;
				(*it)->OnGUI();
			}
			
			screen->SwapWindow();
			environment->UpdateDeltaTime();



			if (keyboard->GetKey(SDLK_ESCAPE))
			{
				screen->DestroyScreen();
				break;
			}



			//check for key and store bool in key variable
			//bool key = ;
			//std::cout << key << std::endl;
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
	std::shared_ptr<Environment> Core::GetEnvironment()
	{
		return environment;
	}
	std::shared_ptr<Keyboard> Core::GetKeyboard()
	{
		return keyboard;
	}
	std::shared_ptr<rend::Context> Core::GetContext()
	{
		return context;
	}
	std::shared_ptr<Resources> Core::GetResources()
	{
		return resources;
	}

	std::shared_ptr<Screen> Core::GetScreen()
	{
		return screen;
	}

	std::shared_ptr<Camera> Core::GetCamera()
	{
		return camera;
	}

	ALCcontext * Core::GetAudioContext()
	{
		return audioContext;
	}

	std::shared_ptr<Timer> Core::GetTimer()
	{
		return timer;
	}

	std::shared_ptr<Gui> Core::GetGUI()
	{
		return gui;
	}

}

