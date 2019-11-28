#pragma once
#ifndef _MESHRENDERER_H_
#define _MESHRENDERER_H_
#include <iostream>
#include "Component.h"
#include "GL/glew.h"
#include <rend/rend.h>



namespace prometheus
{
	class Model;
	class Screen;
	class Material;


	class MeshRenderer : public Component
	{
	public:
		MeshRenderer();
		~MeshRenderer();
		

		void setModel(std::shared_ptr<Model> _model);
		void setMaterial(std::shared_ptr<Material> _mat);
	private:
		std::shared_ptr<Model> model;
		std::shared_ptr<Material> material;
		int windowHeight;
		int windowWidth;

		void onDisplay();
		void onTick();
		void onInit();
		
		
	};
}

#endif // !_MESHRENDERER_H_
