#pragma once
#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <glm/glm.hpp>
#include <rend/rend.h>
namespace prometheus
{
	class Keyboard;
	class Mouse;

	class Camera
	{
	public:
		Camera();
		Camera(glm::vec3 _position, glm::vec3 _target, std::shared_ptr<Keyboard> _keyboard, std::shared_ptr<Mouse> _mouse);
		Camera::Camera(std::shared_ptr<Keyboard> _keyboard, std::shared_ptr<Mouse> _mouse);
		~Camera();

		void OnTick();

		bool Initialize();
		glm::mat4 GetView();
		glm::mat4 GetProjection();
		glm::vec3 GetCameraPos();

		void HandleKeyboardInput();
		void HandleMouseInput();

		void SetCameraPos(glm::vec3 _cameraPosition);
		void SetProjection(glm::mat4 _projectionMatrix);
		void SetView(glm::mat4 _viewingMatrix);

	private:
		std::shared_ptr<Mouse> mouse;
		std::shared_ptr<Keyboard> keyboard;
		glm::mat4 viewingMatrix;
		glm::mat4 projectionMatrix;
		glm::vec3 cameraPosition;
		glm::vec3 cameraTarget;
		glm::vec3 cameraDirection;
		glm::vec3 cameraUp;
		glm::vec3 cameraFront;

		float pitch;
		float yaw;
	};


}
#endif // !_CAMERA_H_
