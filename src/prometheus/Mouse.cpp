#include "Mouse.h"
#include <SDL2/sdl.h>

namespace prometheus
{
	Mouse::Mouse()
	{
		//Set mouse to relative mode
	}
	Mouse::Mouse(int _screenWidth, int _screenHeight)
	{
		std::cout << "Mouse instantiated" << std::endl;
		//Set mouse to relative mode
		screenWidth = _screenWidth;
		screenHeight = _screenHeight;

		HideCursor();

	}
	Mouse::~Mouse()
	{

	}
	void Mouse::OnTick()
	{
		//GetRelativeMousePosition();
	}
	void Mouse::ShowCursor()
	{
		SDL_ShowCursor(1);
		SDL_SetRelativeMouseMode(SDL_FALSE);
	}
	void Mouse::HideCursor()
	{
		SDL_ShowCursor(0);
		SDL_SetRelativeMouseMode(SDL_TRUE);
	}
	glm::ivec2 Mouse::GetRelativeMousePosition()
	{
		SDL_GetRelativeMouseState(&xPos, &yPos);
		//std::cout << xPos << "," << yPos << std::endl;
		return glm::ivec2(xPos, yPos);
	}
}