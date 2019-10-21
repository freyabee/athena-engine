#pragma once
#ifndef _CORE_H_
#define _CORE_H_

//Includes
#include <memory>
#include <vector>

namespace prometheus
{
	class Entity;
	class Keyboard;
	class Environment;


	class Core
	{
	public:
		//Functions
		static std::shared_ptr<Core> initialize();
		void start();
		void stop();
		std::shared_ptr<Entity> addEntity();

	private:
		//Variables
		std::shared_ptr<Environment> environment;
		std::vector<std::shared_ptr<Entity>> entities; //Vec holding entities in this core
		std::shared_ptr<Keyboard> keyboard;
		std::weak_ptr<Core> self;
		bool running;
	};
}

#endif // !_CORE_H_
