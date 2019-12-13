#include "Environment.h"
#include <SDL2/SDL.h>
#include <iostream>
namespace prometheus
{
	Environment::Environment()
	{
	}

	Environment::~Environment()
	{
	}


	void Environment::Initialize()
	{
		lastTime = SDL_GetTicks();
		idealFPS = 60.f;
	}

	float Environment::GetDeltaTime()
	{
		return deltaTime;
	}

	void Environment::SetDeltaTime(float _deltaTime)
	{
		deltaTime = _deltaTime;
	}


	void Environment::UpdateDeltaTime()
	{
		float time = SDL_GetTicks();
		float diff = time - lastTime;
		deltaTime = diff / 1000.f;
		lastTime = time;
		//std::cout << "DT:" << deltaTime << std::endl;
		SleepOffTime();
	}

	void Environment::SleepOffTime()
	{
		float idealTime = 1.0f / idealFPS;

		if (idealTime > deltaTime)
		{
			SDL_Delay((idealTime - deltaTime)*1000.f);
		}
	}

}

