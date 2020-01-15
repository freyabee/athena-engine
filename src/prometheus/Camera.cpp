#include "Keyboard.h"
#include "Mouse.h"
#include "Core.h"
#include "Camera.h"
#include "Timer.h"

namespace prometheus
{
	Camera::Camera()
	{
		//projectionMatrix = glm::perspective(glm::radians(70.0f), 1.0f, 0.1f, 100.0f);
	}
	Camera::Camera(std::shared_ptr<Keyboard> keyboard, std::shared_ptr<Mouse> mouse, std::shared_ptr<Timer> timer)
	{
		this->mouse = mouse;
		this->keyboard = keyboard;
		this->timer = timer;
	}
	Camera::Camera(glm::vec3 position,  glm::vec3 target, std::shared_ptr<Keyboard> keyboard, std::shared_ptr<Mouse> mouse)
	{
		this->cameraPosition = position;
		this->cameraTarget = target;
		this->keyboard = keyboard;
	}

	Camera::~Camera()
	{

	}
	void Camera::OnTick()
	{
		//HandleKeyboardInput();
		HandleMouseInput();

		glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1), glm::radians(-playerHeading.y - 180.0f), glm::vec3(0, 1, 0));
		// player position, creates matrix
		glm::mat4 translationMatrix = glm::translate(glm::mat4(1), playerPosition);

		//Building viewing matrix
		viewingMatrix = glm::mat4(1);
		//Applying rotation of mouse control to the viewing matrix
		viewingMatrix = glm::rotate(viewingMatrix, glm::radians(-pitch), glm::vec3(1, 0, 0)); // Allows player to rotate camera using player object as pivot
		viewingMatrix = glm::rotate(viewingMatrix, glm::radians(yaw), glm::vec3(0,1,0));
		//Translating camera away from player by offset
		viewingMatrix = glm::translate(viewingMatrix, offset); // Provides offset away from player object
		//rotating the matrix in the same direction that the player is facing. 
		viewingMatrix = viewingMatrix * rotationMatrix; // Orient towards player direction
		//Moving to players position. 
		viewingMatrix = glm::translate(viewingMatrix, -playerPosition); // Move to player's position
	}
	bool Camera::Initialize()
	{
		projectionMatrix = glm::perspective(glm::radians(70.f), 1.0f, 0.1f, 100.0f);
		cameraPosition = glm::vec3(0.0f, 3.0f, 3.0f);
		cameraFront = glm::vec3(0.f, 0.f, -1.f);
		cameraUp = glm::vec3(0.f, 1.f, 0.f);

		yaw = 0;
		pitch = 0;
		viewingMatrix = glm::lookAt(cameraPosition+offset, playerPosition, cameraUp);
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

		if (pitch > 45.f)
		{
			pitch = 45.f;
		}
		if (pitch < -45.f)
		{
			pitch = -45.f;
		}
		if (yaw > 45.f)
		{
			yaw = 45.f;
		}
		if (yaw < -45.f)
		{
			yaw = -45.f;
		}

		glm::vec3 tmp;
		tmp.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
		tmp.y = sin(glm::radians(pitch));
		tmp.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));

		//std::cout << pitch << std::endl;
		cameraFront = glm::normalize(tmp);
	}
	void Camera::SetCameraPos(glm::vec3 cameraPosition)
	{
		this->cameraPosition = cameraPosition;
	}
	void Camera::SetProjection(glm::mat4 projectionMatrix)
	{
		this->projectionMatrix = projectionMatrix;
	}
	void Camera::SetView(glm::mat4 viewingMatrix)
	{
		this->viewingMatrix = viewingMatrix;
	}
	void Camera::Follow(glm::vec3 goalPosition, glm::vec3 offset, glm::vec3 heading)
	{
		this->playerPosition = goalPosition;
		playerHeading = heading;
		this->offset = offset;
		glm::vec3 goal = goalPosition + offset;
		float lerp = 0.1f;
		glm::vec3 pos = cameraPosition;
		glm::vec3 diff(0.f);

		diff = (goal - pos)*0.1f;
		cameraPosition += diff;


		//std::cout << diff.x << "," << diff.y << "," << diff.z << std::endl;


		//viewingMatrix = glm::lookAt(cameraPosition+_offset, _goalPosition, cameraUp);
	}
}