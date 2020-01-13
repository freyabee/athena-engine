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
	class Core;

	class MeshRenderer : public Component
	{

	public:
		MeshRenderer();
		~MeshRenderer();
		
		/*GETTERS*/
	
		/*SETTERS*/
		void SetModel(std::shared_ptr<Model> _model);
		void SetMaterial(std::shared_ptr<Material> _mat);
		bool LoadModel(std::string _modelPath, std::string _texturePath, std::string _shader);
		bool LoadSkybox(std::string _modelPath, std::string _shader, std::vector<std::string> _texturepaths);
	private:
		std::weak_ptr<Core> core;
		std::weak_ptr<Entity> entity;
		std::shared_ptr<Model> model;
		std::shared_ptr<Material> material;
		int windowHeight;
		int windowWidth;

		void OnDisplay();
		void OnTick();
		void OnInit();
		
		
	};
}

#endif // !_MESHRENDERER_H_
