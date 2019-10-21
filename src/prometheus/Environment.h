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

		float getDeltaTime();
	private:
		float deltaTime();

	};
}


#endif // !_ENVIRONMENT_H_
