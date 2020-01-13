#include "Keyboard.h"
#include "Mouse.h"
#include "Core.h"
#include "Camera.h"
#include "Timer.h"

namespace prometheus
{
	Camera::Camera()
	{
		projectionMatrix = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);
	}
	Camera::Camera(std::shared_ptr<Keyboard> _keyboard, std::shared_ptr<Mouse> _mouse, std::shared_ptr<Timer> _timer)
	{
		mouse = _mouse;
		keyboard = _keyboard;
		timer = _timer;
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
		//HandleKeyboardInput();
		HandleMouseInput();
		viewingMatrix = glm::lookAt(cameraPosition, (cameraPosition + cameraFront), cameraUp);
	}
	bool Camera::Initialize()
	{
		projectionMatrix = glm::perspective(glm::radians(45.f), 1.0f, 0.1f, 100.0f);
		cameraPosition = glm::vec3(0.0f, 3.0f, 3.0f);
		cameraFront = glm::vec3(0.f, 0.f, -1.f);
		cameraUp = glm::vec3(0.f, 1.f, 0.f);

		yaw = 0;
		pitch = 0;
		viewingMatrix = glm::lookAt(cameraPosition, (cameraPosition + cameraFront), cameraUp);
		return true;
	}

	std::weak_ptr<Core> Camera::GetCore()
	{
		return core.lock();
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
		float sens = 0.05f;
		glm::ivec2 offset = mouse->GetRelativeMousePosition();


		float xOffset = sens * offset.x;
		float yOffset = sens * offset.y;

		yaw += xOffset;
		pitch += -yOffset;

		if (pitch > 89.f)
		{
			pitch = 89.f;
		}
		if (pitch < -89.f)
		{
			pitch = -89.f;
		}


		glm::vec3 tmp;
		tmp.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
		tmp.y = sin(glm::radians(pitch));
		tmp.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));

		//std::cout << pitch << std::endl;
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
	void Camera::Follow(glm::vec3 _goalPosition, glm::vec3 _offset)
	{
		glm::vec3 goal = _goalPosition + _offset;
		float lerp = 0.1f;
		glm::vec3 pos = cameraPosition;
		glm::vec3 diff(0.f);

		diff = (goal - pos)*0.1f;
		cameraPosition += diff;
		//std::cout << diff.x << "," << diff.y << "," << diff.z << std::endl;

		//viewingMatrix = glm::lookAt(cameraPosition+_offset, _goalPosition, cameraUp);
	}
}