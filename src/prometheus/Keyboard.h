#pragma once

#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include <vector>
#include <SDL2/SDL.h>

namespace prometheus
{
	class Keyboard
	{
	public:
		Keyboard();
		~Keyboard();

		bool GetKey(int _key);
		bool GetKeyDown(int _key);
		bool GetKeyUp(int _key);

		void OnTick();

		void IsKey(int _key);
		void IsKeyPressed(int _key);
		void IsKeyReleased(int _key);

		void ClearPressedReleasedKeys();

	private:
		std::vector<int> keys;
		std::vector<int> pressedKeys;
		std::vector<int> releasedKeys;

		const Uint8* keystate;

	};
}


#endif // !_KEYBOARD_H_