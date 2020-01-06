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
	class Material : public	Resource
	{
	public:
		void Load(std::string _path);

		void LoadShader(std::string _path);
		void LoadTexture(std::string _path);

		void SetModel(std::shared_ptr<Model> _model);
		void SetUniform(glm::mat4 _modelMat);

		std::shared_ptr<rend::Shader> GetShader();
		std::shared_ptr<rend::Texture> GetTexture();
		std::shared_ptr<Camera> GetCamera();

	private:
		std::shared_ptr<rend::Shader> shader;
		std::shared_ptr<rend::Texture> texture;

	};
}
#endif // !_MATERIAL_H_
