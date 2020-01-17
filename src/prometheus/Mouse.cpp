#include "Mouse.h"
#include <SDL2/sdl.h>

namespace prometheus
{
	Mouse::Mouse()
	{
	}
	Mouse::Mouse(int screenWidth, int screenHeight)
	{

		this->screenWidth = screenWidth;
		this->screenHeight = screenHeight;
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
		try
		{
			SDL_ShowCursor(1);
			SDL_SetRelativeMouseMode(SDL_FALSE);
		}
		catch (std::exception& e)
		{

			throw std::exception(e);
		}
		
	}
	void Mouse::HideCursor()
	{
		try
		{
			SDL_ShowCursor(0);
			SDL_SetRelativeMouseMode(SDL_TRUE);
		}
		catch (std::exception& e)
		{

			throw std::exception(e);
		}
		
	}
	glm::ivec2 Mouse::GetRelativeMousePosition()
	{
		try
		{
			SDL_GetRelativeMouseState(&xPos, &yPos);
			return glm::ivec2(xPos, yPos);
		}
		catch (std::exception& e)
		{

			throw std::exception(e);
		}

	}
}