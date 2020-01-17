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

	/// Mesh renderer class loads meshes, textures and shaders and renders the model.
	class MeshRenderer : public Component
	{

	public:
		/// Mesh renderer constructor.
		MeshRenderer();
		~MeshRenderer();
		/// Sets model for mesh renderer to render.
		/// Model holds mesh information to be passed to renderer.
		/// @param model Instance of prometheus::Model class holding mesh data.
		void SetModel(std::shared_ptr<Model> model);

		/// Sets material  variable in mesh renderer.
		/// Material holds texture and shader information to be passed to renderer.
		/// @param mat Instance of prometheus::Material class holding texture and shader data.
		void SetMaterial(std::shared_ptr<Material> mat);

		/// Loads creates model and material instance in class and loads textures, meshes and shaders.
		/// @param modelPath Path to model in directory.
		/// @param texturePath Path to texture image in directory.
		/// @param shaderPath Path to shader file in directory.
		bool LoadModel(std::string modelPath, std::string texturePath, std::string shaderPath);

		/// Loads skybox specific model and material.
		/// @TODO Not yet finished.
		/// Returns bool depending if successful.
		bool LoadSkybox(std::string modelPath, std::string shader, std::vector<std::string> texturepaths);
	private:
		/// Pointer to current active instance of core.
		std::weak_ptr<Core> core;
		/// Pointer to parent entity.
		std::weak_ptr<Entity> entity;
		/// Pointer to instance of model.
		/// Contains relevant mesh to be rendered.
		std::shared_ptr<Model> model;
		/// Pointer to instance of material.
		/// Contains texture and shader to render mesh with.
		std::shared_ptr<Material> material;

		/// Window height
		int windowHeight;
		
		/// Window width
		int windowWidth;

		/// Mesh renderer OnDisplay function, overloads Component::OnDisplay()
		/// Material uniforms and model are set here, and rend::Shader::render() function called.
		/// @see rend::Shader::render()
		/// @see Component::OnDisplay()
		void OnDisplay();

		/// Mesh renderer OnTick function, overloads Component::OnTick()
		void OnTick();

		/// Mesh renderer OnInit function, overloads Componenent::OnInit()
		void OnInit();
		
		
	};
}

#endif // !_MESHRENDERER_H_
