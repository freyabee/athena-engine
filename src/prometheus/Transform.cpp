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

	void Transform::Translate(glm::vec3 amount)
	{
		glm::mat4 translationMatrix = glm::translate(glm::mat4(1.f), amount);
		glm::vec4 pos = { localPosition.x, localPosition.y, localPosition.z, 1.0f };
		glm::vec4 transformedPos = translationMatrix * pos;
		localPosition = { transformedPos.x, transformedPos.y, transformedPos.z };
		ApplyTransformations();
	}
	void Transform::Scale(glm::vec3 amount)
	{
		glm::mat4 scalingMatrix = glm::scale(amount);
		glm::vec4 scale = { localScale.x, localScale.y, localScale.z, 1.0f };
		glm::vec4 transformedScale = scalingMatrix * scale;
		localScale = { transformedScale.x, transformedScale.y, transformedScale.z };
		ApplyTransformations();
	}
	void Transform::Rotate(float angle, glm::vec3 axis)
	{		
		glm::mat4 rotationMatrix = glm::rotate(glm::radians(angle), axis);

		glm::mat4 translationMatrix = glm::translate(glm::mat4(1.f), localPosition);
		modelMatrix = translationMatrix * rotationMatrix;
	}

	void Transform::SetLocalPosition(glm::vec3 position)
	{
		localPosition = position;
		ApplyTransformations();
	}
	void Transform::SetLocalPosition(float x, float y, float z)
	{
		SetLocalPosition(glm::vec3(x, y, z));
		ApplyTransformations();
	}
	void Transform::SetLocalRotation(glm::vec3 rotation)
	{
		localRotation = rotation;
		ApplyTransformations();
	}
	void Transform::SetLocalRotation(float x, float y, float z)
	{
		SetLocalRotation(glm::vec3(x, y, z));
		ApplyTransformations();
	}
	void Transform::SetLocalScale(glm::vec3 scale)
	{
		localScale = scale;
		ApplyTransformations();
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
	void Transform::Move(glm::vec3 difference)
	{
		localPosition = { localPosition.x + difference.x, localPosition.y + difference.y, localPosition.z + difference.z };
		ApplyTransformations();
	}
	void Transform::AddRotation(glm::vec3 amount)
	{
		localRotation = { localRotation.x + amount.x, localRotation.y + amount.y, localRotation.z + amount.z };
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