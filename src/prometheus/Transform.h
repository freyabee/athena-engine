#pragma once
#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include "Component.h"
#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
namespace prometheus
{
	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		void translate(glm::vec3 _amount);
		void scale(glm::vec3 _amount);
		void rotate(glm::vec3 _amount);
		void setLocalPosition(glm::vec3 _position);
		void setLocalRotation(glm::vec3 _rotation);
		void setLocalScale(glm::vec3 _scale);


		std::unique_ptr<glm::mat4> GetModelMatrix();
	private:
		glm::vec3 localPosition;
		glm::vec3 localRotation;
		glm::vec3 localScale;
		glm::mat4 modelMatrix;
	};
}
#endif // !TRANSFORM_H_
