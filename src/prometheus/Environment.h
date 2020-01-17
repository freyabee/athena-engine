#pragma once
#ifndef _ENVIRONMENT_H_
#define _ENVIRONMENT_H_

namespace prometheus
{
	/// Handles time and FPS functions across the engine.
	/// Manages delta time and handles standardising loop time and FPS.
	class Environment
	{
	public:
		/// Constructor for environment object.
		Environment();

		/// Destructor for environment object.
		~Environment();

		/// Initializes environment instance, called at beginning of game loop.
		/// Called before entities are intialises, sets up FPS variables and sets baseline time.
		void OnInit();
		
		/// Gets delta time.
		/// Returns time since last tick.
		/// @returns Float delta time.
		float GetDeltaTime();

		/// Get ideal delta time.
		/// Returns the goal delta time calculated from goal FPS.
		/// @returns float ideal time.
		float GetIdealTime();

		/// Set delta time.
		/// Allows the setting of a delta time.
		/// @param deltaTime Time to set deltatime to.
		void SetDeltaTime(float deltaTime);

		/// Updates the current delta time.
		/// Gets current time and uses the last measure time to calculate deltatime.
		/// Sleeps off remaining time in Environment::SleepOffTime()
		void UpdateDeltaTime();

		/// Sleeps off remaining time if deltatime is less than idealTime.
		void SleepOffTime();


	private:
		/// Time between ticks.
		float deltaTime;
		/// Last time measured.
		float lastTime;
		/// Target number of FPS.
		float idealFPS;
		/// Target deltatime.
		float idealTime;
	};
}


#endif // !_ENVIRONMENT_H_
