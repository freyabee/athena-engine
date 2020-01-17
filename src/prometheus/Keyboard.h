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
		/// Constructor initialises keyboard instance.
		/// Sets initial keystate.
		Keyboard();
		~Keyboard();

		/// Returns bool if key matches input parameter key.
		/// Checks input key against Keyboard::keystate variable and returns bool if present.
		/// @param key SDL_Keycode to check keystate against.
		/// @returns boolean denoting whether key has been pressed.
		bool GetKey(SDL_Keycode key);

		/*
		bool GetKeyDown(int _key);
		bool GetKeyUp(int _key);
		*/
		/// Pumps SDL events updating the keystate variable.
		void OnTick();

		/*
		void IsKey(int _key);
		void IsKeyPressed(int _key);
		void IsKeyReleased(int _key);
		void ClearPressedReleasedKeys();
		*/

	private:
		/*
		std::vector<int> keys;
		std::vector<int> pressedKeys;
		std::vector<int> releasedKeys;
		*/


		/// Keystate holding array of keys pressed since last check.
		const Uint8* keystate;

	};
}


#endif // !_KEYBOARD_H_