#include "Camera.h"

namespace prometheus
{
	Camera::Camera()
	{
	}

	Camera::~Camera()
	{
	}
	glm::mat4 Camera::getView()
	{
		return viewingMatrix;
	}
	glm::mat4 Camera::getProjection()
	{
		return projectionMatrix;
	}
	glm::vec3 Camera::getCameraPos()
	{
		return cameraPosition;
	}
	void Camera::setCameraPos(glm::vec3 newPosition)
	{
	}
	void Camera::setProjection(glm::mat4 newProjection)
	{
	}
	void Camera::setView(glm::mat4 newView)
	{
	}
}