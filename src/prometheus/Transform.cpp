#include "Transform.h"

namespace prometheus
{
	Transform::Transform()
	{
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
	void Transform::rotate(glm::vec3 _amount)
	{
		//TODO: Finish this function with glm rotations
	}
	void Transform::setLocalPosition(glm::vec3 _position)
	{

		localPosition = _position;
	}
	void Transform::setLocalRotation(glm::vec3 _rotation)
	{
		localPosition = _rotation;
	}
	void Transform::setLocalScale(glm::vec3 _scale)
	{
		localScale = _scale;
	}
}