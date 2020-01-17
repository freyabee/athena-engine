#pragma once
#ifndef _TIMER_H_
#define _TIMER_H_
#endif // !_TIMER_H_
#include <SDL2/SDL.h>

namespace prometheus
{
	/// Timer class to measure performance of engine and initialisation.
	/// Contains classes to measure and manage timer.
	class Timer
	{
	public:
		/// Constructor initialise timer object.
		/// Sets startTime and currenTime variable to current time using SDL_GetTicks().
		Timer();
		~Timer();
		/// Returns time since start of timer object in ms.
		Uint32 GetTimeMs();
		/// Returns time since start of timer object in seconds.
		float GetTimeS();
		/// Returns time between OnTick() calls.
		float GetDeltaTime();
		/// Calculates delta time and sets currentTime variable.
		void OnTick();

	private:
		/// Time when Timer object first initialised
		Uint32 startTime;
		/// Time between OnTick() calls.
		float deltaTime;
		/// Time of last OnTick() call.
		float lastTime;
		/// Time of current OnTick() call.
		float currentTime;
	};
}