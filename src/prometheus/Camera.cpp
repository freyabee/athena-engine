#include "Keyboard.h"
#include "Mouse.h"

#include "Camera.h"


namespace prometheus
{
	Camera::Camera()
	{
		projectionMatrix = glm::perspective(glm::radians(110.0f), 1.0f, 0.1f, 100.0f);
	}
	Camera::Camera(std::shared_ptr<Keyboard> _keyboard, std::shared_ptr<Mouse> _mouse)
	{
		mouse = _mouse;
		keyboard = _keyboard;
	}
	Camera::Camera(glm::vec3 _position,  glm::vec3 _target, std::shared_ptr<Keyboard> _keyboard, std::shared_ptr<Mouse> _mouse)
	{
		cameraPosition = _position;
		cameraTarget = _target;
		keyboard = _keyboard;
	}

	Camera::~Camera()
	{

	}
	void Camera::OnTick()
	{
		HandleKeyboardInput();
		viewingMatrix = glm::lookAt(cameraPosition, (cameraPosition + cameraFront), cameraUp);
	}
	bool Camera::Initialize()
	{
		/* Get opposite direction vector to camera pointing.
		cameraDirection = glm::normalize(cameraPosition - cameraTarget);
		// Define right vector.
		glm::vec3 up = glm::vec3(0.f, 1.f, 0.f);
		glm::vec3 front = glm::vec3(0.f, 1.f, -1.f);

		glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));
		glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);
		glm::mat4 view = glm::lookAt(cameraPosition, (cameraPosition + front), up);
		*/
		projectionMatrix = glm::perspective(glm::radians(110.0f), 1.0f, 0.1f, 100.0f);
		cameraPosition = glm::vec3(0.0f, 1.0f, 3.0f);
		cameraFront = glm::vec3(0.f, 0.f, -1.f);
		cameraUp = glm::vec3(0.f, 1.f, 0.f);

		yaw = 0;
		pitch = 0;
		viewingMatrix = glm::lookAt(cameraPosition, (cameraPosition + cameraFront), cameraUp);
		return true;


		std::cout << "Initialization Complete" << std::endl;
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
	void Camera::HandleKeyboardInput()
	{
		float cameraSpeed = 0.05f;
		if (keyboard->GetKey(SDLK_w))
		{
			cameraPosition += cameraSpeed * cameraFront;
		}
		if (keyboard->GetKey(SDLK_s))
		{
			cameraPosition -= cameraSpeed * cameraFront;
		}
		if (keyboard->GetKey(SDLK_a))
		{
			cameraPosition -= glm::normalize(glm::cross(cameraFront, cameraUp))*cameraSpeed;
		}
		if (keyboard->GetKey(SDLK_d))
		{
			cameraPosition += glm::normalize(glm::cross(cameraFront, cameraUp))*cameraSpeed;
		}
	}
	void Camera::HandleMouseInput()
	{
		float sens = 1.f;
		glm::ivec2 offset = mouse->GetRelativeMousePosition();


		float xOffset = sens * offset.x;
		float yOffset = sens * offset.y;

		yaw += xOffset;
		pitch += yOffset;

		/*
		if (pitch > 89.f)
		{
			pitch = 89.f;
		}
		if (pitch < -89.f)
		{
			pitch = -89.f;
		}
		*/

		glm::vec3 tmp;
		tmp.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
		tmp.y = sin(glm::radians(pitch));
		tmp.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));

		std::cout << "reached" << std::endl;
		cameraFront = glm::normalize(tmp);
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