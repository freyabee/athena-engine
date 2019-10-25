#pragma once
#ifndef _TRIANGLERENDERER_H_
#define _TRIANGLEREDERER_H_
#include <iostream>
#include "Component.h"
#include "SDL2/SDL.h"
#include "GL/glew.h"
namespace prometheus
{
	class TriangleRenderer : public Component
	{
	public:
		TriangleRenderer();
		~TriangleRenderer();
		

	private:
		int windowHeight;
		int windowWidth;
		GLuint programId;
		GLuint vboId;
		GLuint vaoId;
		void onDisplay();
		void onTick();
		void onInit();
		SDL_Window* window;
	};
}

#endif // !_TRIANGLERENDERER_H_
