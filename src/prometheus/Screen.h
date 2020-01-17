#pragma once
#ifndef _SCREEN_H_
#define _SCREEN_H_
#include "SDL2/SDL.h"
#include <rend/rend.h>
namespace prometheus
{
	/// Class to manage the initialisation and functions of the screen.
	/// Initialises the screen and manages destroying, swapping and clearing the window.
	/// Class holds information about window and provides accesss functions.
	class Screen
	{
	public:
		/// Constructor passing in width and height of new window.
		/// Window of w width and h height is initialised.
		Screen(int w, int h);
		~Screen();
		/// Handles destroying SDL window and quitting the program.
		/// Invokes SDL_DestroyWindow() and SDL_Quit()
		void DestroyScreen();
		
		/// Swaps current window with buffer object.
		/// Invokes SDL_GL_SwapWindow();
		void SwapWindow();

		/// Clears current window buffer to white.
		void ClearWindow();

		/// Returns window dimensions.
		/// Returns an ivec2 containing the x and y pixel dimensions of the window.
		glm::ivec2 GetWindowDimensions();
	private:
		/// Window height in pixels.
		int windowHeight;

		/// Window width in pixels.
		int windowWidth;

		/// Raw pointer to the SDL_Window object.
		SDL_Window* window;
	};

}



#endif // !_SCREEN_H_
