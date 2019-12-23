#include "Camera.h"

namespace prometheus
{
	Camera::Camera()
	{
	}

	Camera::~Camera()
	{
	}
	glm::mat4 Camera::GetView()
	{
		return viewingMatrix;
	}
	glm::mat4 Camera::GetProjection()
	{
		return projectionMatrix;
	}
	glm::vec3 Camera::GetCameraPos()
	{
		return cameraPosition;
	}
	void Camera::SetCameraPos(glm::vec3 _cameraPosition)
	{
		cameraPosition = _cameraPosition;
	}
	void Camera::SetProjection(glm::mat4 _projectionMatrix)
	{
		projectionMatrix = _projectionMatrix;
	}
	void Camera::SetView(glm::mat4 _viewingMatrix)
	{
		viewingMatrix = _viewingMatrix;
	}
}