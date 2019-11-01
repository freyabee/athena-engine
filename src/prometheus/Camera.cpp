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
}