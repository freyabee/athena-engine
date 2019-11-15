#pragma once
#ifndef _MESHRENDERER_H_
#define _MESHRENDERER_H_
#include <iostream>
#include "Component.h"
#include "Screen.h"
#include "GL/glew.h"
#include <rend/rend.h>
namespace prometheus
{
	class MeshRenderer : public Component
	{
	public:
		MeshRenderer();
		~MeshRenderer();
		

	private:
		std::shared_ptr<rend::Context> context;
		std::shared_ptr<rend::Shader> shader;
		std::shared_ptr<rend::Mesh> shape;

		int windowHeight;
		int windowWidth;

		void onDisplay();
		void onTick();
		void onInit();
		std::shared_ptr<prometheus::Screen> screen;
		
	};
}

#endif // !_MESHRENDERER_H_
