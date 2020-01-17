

#pragma once
#ifndef _MOUSE_H_
#define _MOUSE_H_
#endif // !_MOUSE_H_

#include <iostream>
#include <glm/glm.hpp>

namespace prometheus
{
	/// Handles mouse input and access.
	/// Finds mouse position and provides access functions for mouse coordinate data.
	/// Provides addtional functions such as changing mouse display mode.
	class Mouse
	{
	public:

		///Constructor for mouse
		Mouse();
		/// Constructor for mouse, passing in screen dimensions.
		/// screenWidth and screenHeight member variables set from input.
		/// Mouse is set to relative mode by calling the Mouse::HideCursor() function.

		Mouse(int screenWidth, int screenHeight);
		~Mouse();

		/// Mouse on OnTick() function, overloads Component::OnTick();
		void OnTick();
		/// Calls SDL to show cursor and turns off relative mouse mode.
		void ShowCursor();
		/// Calls SDL to hide cursor and turns on relative mouse mode.
		void HideCursor();
		/// Retrieves relative mouse state and returns ivec2 containing coordinates.
		/// Sets member variables xPos and yPos to x and y relative mouse coordinates.
		/// @returns Ivec2 containing relative mouse coordinates in the x and y direction.
		glm::ivec2 GetRelativeMousePosition();

		
	private:
		/// Relative position in the x axis.
		int xPos;
		/// Relative mouse position in the y axis.
		int yPos;
		/// Screen width in pixels.
		int screenWidth;
		/// Screen height in pixels.
		int screenHeight;
	};
}

