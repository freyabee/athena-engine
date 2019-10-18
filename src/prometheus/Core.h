#pragma once
#ifndef _CORE_H_
#define _CORE_H_

//Includes
#include <memory>
#include <vector>

class Entity;
class Keyboard;
class Environment;
//Body
class Core
{
public:
	Core();
	~Core();

	static std::shared_ptr<Core> initialize();
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
