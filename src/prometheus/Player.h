#pragma once
#ifndef  _PLAYER_H_
#define _PLAYER_H_
#endif // ! _PLAYER_H_

#include <iostream>
#include "Component.h"

namespace prometheus
{
	class Player : public Component
	{
	public:
		Player();
		~Player();

		void HandleInput();
		void PlayerRotation();
		void PlayerMovement();
	private:
		void onDisplay();
		void onTick();
		void onInit();

		std::shared_ptr<Keyboard> keyboard;
		float xAngle = 0.f;
		float yAngle = 0.f;

	};
}