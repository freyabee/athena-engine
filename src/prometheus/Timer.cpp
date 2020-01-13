#include "Timer.h"

namespace prometheus
{
	Timer::Timer()
	{
		startTime = SDL_GetTicks();
		currentTime = startTime;
	}
	Timer::~Timer()
	{

	}
	Uint32 Timer::GetTimeMs()
	{
		return SDL_GetTicks() - startTime;
	}
	float Timer::GetTimeS()
	{
		float rtn = GetTimeMs() / 1000;
		return rtn;
	}
	float Timer::GetDeltaTime()
	{
		return deltaTime;
	}
	void Timer::OnTick()
	{
		lastTime = currentTime;
		currentTime = GetTimeMs();
		deltaTime = (currentTime - lastTime);
	}
}