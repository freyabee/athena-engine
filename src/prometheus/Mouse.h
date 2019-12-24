#pragma once
#ifndef _MOUSE_H_
#define _MOUSE_H_
#endif // !_MOUSE_H_

#include <iostream>
#include <glm/glm.hpp>

namespace prometheus
{
	class Mouse
	{
	public:
		Mouse();
		Mouse(int _screenWidth, int _screenHeight);
		~Mouse();

		void OnTick();

		void ShowCursor();
		void HideCursor();

		glm::ivec2 GetRelativeMousePosition();

		
	private:
		int xPos;
		int yPos;
		int screenWidth;
		int screenHeight;
	};
}

