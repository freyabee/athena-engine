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
#include "AudioContext.h"

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
		std::cout << "failed ";
		std::cout << e.what() << std::endl;
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
			std::cout << "failed ";
			std::cout << e.what() << std::endl;
		}
		try 
		{
			std::cout << "Initializing render context: ";
			rtn->context = rend::Context::initialize();
			std::cout << "success" << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "failed ";
			std::cout << e.what() << std::endl;
		}
		
		try 
		{
			//Initialising pools of resources
			std::cout << "Initialising resources: ";
			rtn->resources = std::make_shared<Resources>();
			rtn->resources->core = rtn;
			std::cout << "success" << std::endl;
		}
		catch (const std::exception & e)
		{
			std::cout << "failed ";
			std::cout << e.what() << std::endl;
		}

		

		try
		{
			std::cout << "Initialising environment: ";
			rtn->environment = std::make_shared<Environment>();
			std::cout << "success" << std::endl;
		}
		catch(std::exception & e)
		{
			std::cout << "failed ";
			std::cout << e.what() << std::endl;
		}

		try
		{
			std::cout << "Initialising keyboard: ";
			rtn->keyboard = std::make_shared<Keyboard>();
			std::cout << "success" << std::endl;
		}
		catch (std::exception&e)
		{
			std::cout << "failed ";
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::cout << "Initialising mouse: ";
			rtn->mouse = std::make_shared<Mouse>(windowWidth, windowHeight);
			std::cout << "success" << std::endl;
		}
		catch (std::exception&e)
		{
			std::cout << "failed ";
			std::cout << e.what() << std::endl;
		}

		try
		{
			std::cout << "Initialising camera: ";
			rtn->camera = std::make_shared<Camera>(rtn->keyboard, rtn->mouse, rtn->timer);
			std::cout << "success" << std::endl;
		}
		catch (std::exception&e)
		{
			std::cout << "failed ";
			std::cout << e.what() << std::endl;
		}

		try
		{
			std::cout << "Initialising gui: ";
			rtn->gui = std::make_shared<Gui>(rtn);
			std::cout << "success" << std::endl;
		}
		catch (std::exception&e)
		{
			std::cout << "failed ";
			std::cout << e.what() << std::endl;
		}

		try
		{
			std::cout << "Initialising audio context: ";
			rtn->audioContext = std::make_shared<AudioContext>();
			std::cout << "success" << std::endl;
		}
		catch (std::exception&e)
		{
			std::cout << "failed ";
			std::cout << e.what() << std::endl;
		}
		std::cout << "Core initalization completed in " << rtn->timer->GetTimeS() << "s." << std::endl;

		return rtn;
	}

	Core::~Core()
	{

	}

	
	void Core::start()
	{
		running = true;
		environment->OnInit();
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
			for (std::vector<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); ++it)
			{
				
				try
				{
					(*it)->OnEarlyUpdate();
				}
				catch (std::exception& e)
				{
					std::cout << "Error calling OnEarlyUpdate: " << e.what() << std::endl;
				}
			}


			for (std::vector<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); ++it)
			{
				try
				{
					(*it)->OnTick();
				}
				catch (std::exception& e)
				{
					std::cout << "Error calling OnTick: " << e.what() << std::endl;
				}
			}

			camera->OnTick();

			for (std::vector<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); ++it)
			{
				try
				{
					(*it)->OnDisplay();
				}
				catch (std::exception& e)
				{
					std::cout << "Error calling OnDisplay: " << e.what() << std::endl;
				}
			}

			for (std::vector<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); ++it)
			{
				try
				{
					(*it)->OnGUI();
				}
				catch (std::exception& e)
				{
					std::cout << "Error calling OnGUI: " << e.what() << std::endl;
				}
			}

			if (keyboard->GetKey(SDLK_ESCAPE))
			{
				stop();
				break;
			}
			screen->SwapWindow();
			environment->UpdateDeltaTime();
		}
	}

	void Core::stop()
	{
		screen->DestroyScreen();
	}

	std::shared_ptr<Entity> Core::addEntity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
		entities.push_back(rtn);
		rtn->self = rtn;
		rtn->core = self;
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


	std::shared_ptr<Timer> Core::GetTimer()
	{
		return timer;
	}

	std::shared_ptr<Gui> Core::GetGUI()
	{
		return gui;
	}

	std::shared_ptr<AudioContext> Core::GetAudioContext()
	{
		return audioContext;
	}

}

