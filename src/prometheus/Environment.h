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
		void SetDeltaTime(float _deltaTime);
		void UpdateDeltaTime();
		void SleepOffTime();


	private:
		float deltaTime;
		float lastTime;
		float idealFPS;

	};
}


#endif // !_ENVIRONMENT_H_
