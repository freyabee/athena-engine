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
		screenWidth = _screenWidth;
		screenHeight = _screenHeight;
		HideCursor();
	}
	Mouse::~Mouse()
	{

	}
	void Mouse::OnTick()
	{
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
		return glm::ivec2(xPos, yPos);
	}
}