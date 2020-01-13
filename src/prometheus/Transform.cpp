#include "Transform.h"

namespace prometheus
{
	Transform::Transform()
	{
		localPosition = glm::vec3(0.f, 0.f, 0.f);
		localRotation = glm::vec3(0.f, 0.f, 0.f);
		modelMatrix = glm::translate(glm::mat4(1.f), localPosition);
	}

	Transform::~Transform()
	{
	}

	void Transform::translate(glm::vec3 _amount)
	{
		glm::mat4 translationMatrix = glm::translate(glm::mat4(1.f), _amount);
		glm::vec4 pos = { localPosition.x, localPosition.y, localPosition.z, 1.0f };
		glm::vec4 transformedPos = translationMatrix * pos;
		localPosition = { transformedPos.x, transformedPos.y, transformedPos.z };


	}
	void Transform::scale(glm::vec3 _amount)
	{
		glm::mat4 scalingMatrix = glm::scale(_amount);
		glm::vec4 scale = { localScale.x, localScale.y, localScale.z, 1.0f };
		glm::vec4 transformedScale = scalingMatrix * scale;
		localScale = { transformedScale.x, transformedScale.y, transformedScale.z };
	}
	void Transform::rotate(float _angle, glm::vec3 _axis)
	{		
		glm::mat4 rotationMatrix = glm::rotate(glm::radians(_angle), _axis);

		glm::mat4 translationMatrix = glm::translate(glm::mat4(1.f), localPosition);
		modelMatrix = translationMatrix * rotationMatrix;
	}

	void Transform::SetLocalPosition(glm::vec3 _position)
	{
		localPosition = _position;
		ApplyTransformations();
	}
	void Transform::SetLocalPosition(float _x, float _y, float _z)
	{
		SetLocalPosition(glm::vec3(_x, _y, _z));
	}
	void Transform::SetLocalRotation(glm::vec3 _rotation)
	{
		localRotation = _rotation;
		ApplyTransformations();
	}
	void Transform::SetLocalRotation(float _x, float _y, float _z)
	{
		SetLocalRotation(glm::vec3(_x, _y, _z));
	}
	void Transform::SetLocalScale(glm::vec3 _scale)
	{
		localScale = _scale;
	}
	void Transform::ApplyTransformations()
	{
		
		// There must be a better way to do this. 
		glm::mat4 rotationMatrix = glm::rotate(glm::radians(localRotation.x), glm::vec3(1.f, 0.f, 0.f));
		rotationMatrix *= glm::rotate(glm::radians(localRotation.y), glm::vec3(0.f, 1.f, 0.f));
		rotationMatrix *= glm::rotate(glm::radians(localRotation.z), glm::vec3(0.f, 0.f, 1.f));

		glm::mat4 translationMatrix = glm::translate(glm::mat4(1.f), localPosition);

		modelMatrix = translationMatrix * rotationMatrix;
	}
	void Transform::Move(glm::vec3 _difference)
	{
		localPosition = { localPosition.x + _difference.x, localPosition.y + _difference.y, localPosition.z + _difference.z };
		ApplyTransformations();
	}
	void Transform::AddRotation(glm::vec3 _amount)
	{
		
		localRotation = { localRotation.x + _amount.x, localRotation.y + _amount.y, localRotation.z + _amount.z };
		ApplyTransformations();
	}
	glm::mat4 Transform::GetModelMatrix()
	{
		//Change this to return by value
		return modelMatrix;
	}
	glm::vec3 Transform::GetLocalPosition()
	{
		return localPosition;
	}
	glm::vec3 Transform::GetLocalRotation()
	{
		return localRotation;
	}

}