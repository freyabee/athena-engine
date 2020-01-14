#pragma once
#ifndef _GUI_H_
#define _GUI_H_
#endif // !_GUI_H_
#include <memory>
#include <string>
#include <rend/rend.h>
#include <glm/glm.hpp>

/// Manages rendering of GUI elements to screen.
///
/// Holds projections, shaders and meshes and textures for GUI elements.

namespace prometheus
{
	class Model;
	class Material;
	class Core;
	class Texture;


	class Gui
	{
	public:
		Gui();
		~Gui();
		void OnInit();
		std::shared_ptr<Core> GetCore();
		void Texture(glm::vec4 position, std::shared_ptr<rend::Texture> texture);
	private:
		std::shared_ptr<rend::Mesh> mesh;
		std::shared_ptr<rend::Shader> shader;
		glm::mat4 projection;
		std::weak_ptr<Core> core;

	};

}
