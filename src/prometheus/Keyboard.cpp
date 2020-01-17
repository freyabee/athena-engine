#include "Keyboard.h"
#include <iostream>


namespace prometheus
{
	Keyboard::Keyboard()
	{
		keystate = SDL_GetKeyboardState( NULL );   
	}

	Keyboard::~Keyboard()
	{
	}

	bool Keyboard::GetKey(SDL_Keycode key)
	{
		SDL_Scancode scan = SDL_GetScancodeFromKey(key);
		if (keystate[scan])
		{
			return true;
		}
		return false;
	}
	/*
	bool Keyboard::GetKeyDown(int _keyCode)
	{
		return false;
	}

	bool Keyboard::GetKeyUp(int _keyCode)
	{
		return false;
	}
	*/

	void Keyboard::OnTick()
	{
		SDL_PumpEvents();
	}

	/*
	void Keyboard::IsKey(int _key)
	{

	}
	void Keyboard::IsKeyPressed(int _key)
	{

	}
	void Keyboard::IsKeyReleased(int _key)
	{

	}

	void Keyboard::ClearPressedReleasedKeys()
	{

	}
	*/
	

}


