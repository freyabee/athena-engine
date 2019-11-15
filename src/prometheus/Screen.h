#pragma once
#ifndef _SCREEN_H_
#define _SCREEN_H_
#include "SDL2/SDL.h"
#include <rend/rend.h>
namespace prometheus
{
	class Screen
	{
	public:
		Screen(int _w, int _h);
		~Screen();
		void DestroyScreen();
		void SwapWindow();
		void ClearWindow();
	private:
		int windowHeight;
		int windowWidth;
		SDL_Window* window;
	};

}



#endif // !_SCREEN_H_
