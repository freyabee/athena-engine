#pragma once
#ifndef _MATERIAL_H_
#define _MATERIAL_H_
#include <memory>
#include <string>
#include <rend/rend.h>
#include "Resource.h"


namespace prometheus
{
	class Model;
	class Camera;

	/// Class to load the texture and shader for an object.
	///
	/// Encapsulates and contains the shader and textures for models, interfacing with the rend classes.
	class Material : public	Resource
	{
	public:
		/// Initialises shader and texture objects.
		///
		/// @param Path
		void Load(std::string path);

		/// Initialises shader variable and loads shader from path.
		///
		/// Uses ParseFromPath function from the rend::Shader class to load shader from path.
		/// @param Path to shader of type string.
		void LoadShader(std::string shaderPath);

		/// Initialises texture variable and loads texture from texture path.
		///
		/// @param Path to texture of type string.
		void LoadTexture(std::string texturePath);

		/// Initialises texture variable and loads texture from texture path.
		///
		/// Uses core passed into function instead of core.lock(), used for non-entity textures such as GUI.
		void LoadTexture(std::string texturePath, std::shared_ptr<Core> core);

		/// Sets shader mesh
		///
		/// Retrieves mesh from prometheus::model and passes into shader.
		/// @param Path to texture of type string.
		/// @param Pointer to core instance.
		void SetModel(std::shared_ptr<Model> model);

		/// Sets projection, view and model uniforms in shader.
		///
		/// @param Model matrix
		void SetUniform(glm::mat4 modelMat);

		/// Returns pointer to shader.
		/// 
		/// @returns Smart pointer to rend::shader instance.
		std::shared_ptr<rend::Shader> GetShader();

		/// Returns pointer to texture.
		///
		/// @returns Smart pointer to rend::texture instance.
		std::shared_ptr<rend::Texture> GetTexture();

		/// Returns pointer to camera.
		///
		/// Calls the GetCamera() function in core.
		/// @returns Pointer to instance of camera from core.
		/// @see "Core.h"
		std::shared_ptr<Camera> GetCamera();

	private:
		/// Variable holding material's shader
		std::shared_ptr<rend::Shader> shader;
		/// Variable holding material's texture
		std::shared_ptr<rend::Texture> texture;

	};
}
#endif // !_MATERIAL_H_
