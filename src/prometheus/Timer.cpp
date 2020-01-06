#include "Timer.h"

namespace prometheus
{
	Timer::Timer()
	{
		startTime = SDL_GetTicks();
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
}