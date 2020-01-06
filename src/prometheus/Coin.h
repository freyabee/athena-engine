#pragma once
#ifndef _COIN_H_
#define _COIN_H_
#endif // !_COIN_H_

#include <iostream>
#include "Component.h"
namespace prometheus
{ 
	class Coin : public Component
	{
	public:
		Coin();
		~Coin();

		void onDisplay();
		void onTick();
		void onInit();

	private:
		float angleRotation;

	};
}