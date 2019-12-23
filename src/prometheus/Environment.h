#pragma once
#ifndef _ENVIRONMENT_H_
#define _ENVIRONMENT_H_

namespace prometheus
{
	class Environment
	{
	public:
		Environment();
		~Environment();

		void Initialize();
		float GetDeltaTime();
		float GetIdealTime();
		void SetDeltaTime(float _deltaTime);
		void UpdateDeltaTime();
		void SleepOffTime();


	private:
		float deltaTime;
		float lastTime;
		float idealFPS;
		float idealTime;
	};
}


#endif // !_ENVIRONMENT_H_
