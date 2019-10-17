#pragma once
#ifndef _ENVIRONMENT_H_
#define _ENVIRONMENT_H_


class Environment
{
public:
	Environment();
	~Environment();
	
	float getDeltaTime();
private:
	float deltaTime();

};

#endif // !_ENVIRONMENT_H_
