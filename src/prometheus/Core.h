#pragma once
#ifndef _CORE_H_
#define _CORE_H_

//Includes
#include "Environment.h"
#include "Entity.h"
#include "Keyboard.h"
#include <memory>
#include <vector>

//Body
class Core
{
public:
	Core();
	~Core();

	std::shared_ptr<Core> initialize();
	void start();
	void stop();
	std::shared_ptr<Entity> addEntity();

private:
	std::shared_ptr<Environment> environment;
	std::vector<std::shared_ptr<Entity>> entities;
	std::shared_ptr<Keyboard> keyboard;
	bool running;
};

#endif // !_CORE_H_
