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
		void rotate(float _angle, glm::vec3 _axis);
		void SetLocalPosition(glm::vec3 _position);
		void SetLocalPosition(float _x, float _y, float _z);
		void SetLocalRotation(glm::vec3 _rotation);
		void SetLocalRotation(float _x, float _y, float _z);
		void SetLocalScale(glm::vec3 _scale);
		void ApplyTransformations();


		void Move(glm::vec3 _difference);
		void AddRotation(glm::vec3 _amount);
		glm::mat4 GetModelMatrix();
		glm::vec3 GetLocalPosition();
		glm::vec3 GetLocalRotation();
	private:

		glm::vec3 localPosition;
		glm::vec3 localRotation;
		glm::vec3 localScale;
		glm::mat4 modelMatrix;
	};
}
#endif // !TRANSFORM_H_
