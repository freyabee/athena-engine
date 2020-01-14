#pragma once
#ifndef _GUI_H_
#define _GUI_H_
#endif // !_GUI_H_
#include <memory>
#include <string>

/// Manages rendering of GUI elements to screen.
///
/// Holds projections, shaders and meshes and textures for GUI elements.
namespace prometheus
{
	class Model;
	class Material;
	class Core;

	class Gui
	{
	public:
		Gui();
		~Gui();
		void LoadButtonMesh(std::string path);
		void LoadButtonMaterial(std::string shaderPath, std::string texturePath);
		std::shared_ptr<Core> GetCore();
	private:
		std::shared_ptr<Model> model;
		std::shared_ptr<Material> material;
		std::weak_ptr<Core> core;

	};

}
