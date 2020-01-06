#pragma once
#ifndef _TIMER_H_
#define _TIMER_H_
#endif // !_TIMER_H_
#include <SDL2/SDL.h>

namespace prometheus
{
	class Timer
	{
	public:
		Timer();
		~Timer();
		Uint32 GetTimeMs();
		float GetTimeS();
	private:
		Uint32 startTime;

	};
}