#include "Transform.h"

namespace prometheus
{
	Transform::Transform()
	{
		localPosition = glm::vec3(0.f, 0.f, -10.f);
		modelMatrix = glm::translate(glm::mat4(1.f), localPosition);
	}

	Transform::~Transform()
	{
	}

	void Transform::translate(glm::vec3 _amount)
	{
		glm::mat4 translationMatrix = glm::translate(glm::mat4(), _amount);
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
		modelMatrix = modelMatrix * rotationMatrix;
	}

	void Transform::SetLocalPosition(glm::vec3 _position)
	{
		localPosition = _position;
		modelMatrix = glm::translate(glm::mat4(1.f), localPosition);
	}
	void Transform::SetLocalRotation(glm::vec3 _rotation)
	{
		localPosition = _rotation;

	}
	void Transform::SetLocalScale(glm::vec3 _scale)
	{
		localScale = _scale;
	}
	void Transform::Move(glm::vec3 _amount)
	{
		localPosition = localPosition + _amount;
		modelMatrix = glm::translate(glm::mat4(1.f), localPosition);
	}
	std::unique_ptr<glm::mat4> Transform::GetModelMatrix()
	{
		return std::make_unique<glm::mat4>(modelMatrix);
	}
}