#pragma once
#ifndef _GUI_H_
#define _GUI_H_
#endif // !_GUI_H_
#include <memory>
#include <string>
#include <rend/rend.h>
#include <glm/glm.hpp>

namespace prometheus
{
	class Model;
	class Material;
	class Core;
	class Texture;

	/// Manages rendering of GUI elements to screen.
	///
	/// Holds projections, shaders and meshes and textures for GUI elements.
	class Gui
	{
	public:
		/// Constructor taking a pointer to the core as a parameter.
		/// Sets the member variable core to parameter core.
		/// @param core Pointer to current instance of core.
		Gui(std::shared_ptr<Core> core);
		~Gui();

		/// Functio to create mesh and shader for GUI element.
		/// Creates a shader in the active context and pushes mesh coordinates to the buffer.
		void OnInit();

		/// Returns a pointer to the current instance of core.
		/// Uses core.lock() to return pointer to active core instance.
		/// @returns Pointer to current active core instance.
		std::shared_ptr<Core> GetCore();

		/// Assigns texture to mesh, finishes shader and renders GUI element.
		/// Takes in position and texture and pushes them to shader and mesh. 
		/// @param position Position of the GUI element on screen.
		/// @param texture Pointer to rend::Texture instance.
		void Texture(glm::vec4 position, std::shared_ptr<rend::Texture> texture);
	private:
		/// Pointer to GUI mesh.
		std::shared_ptr<rend::Mesh> mesh;
		/// Pointer to GUI shader.
		std::shared_ptr<rend::Shader> shader;
		/// Camera projection used for shader.
		glm::mat4 projection;
		/// Weak pointer to active core instance.
		std::weak_ptr<Core> core;

	};

}
