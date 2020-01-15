#pragma once
#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <glm/glm.hpp>
#include <rend/rend.h>
namespace prometheus
{
	class Core;
	class Keyboard;
	class Mouse;
	class Timer;

	/// Class handling camera creation and handling.
	/// Creates an instance of a camera and handles movement in 3D space and input from user.
	class Camera
	{
	public:
		/// Empty initialisation of camera.
		Camera();
		/// Initialises camera with position, target and references to input devices.
		///
		/// @param position Camera starting position.
		/// @param target Target for camera to point at.
		/// @param keyboard Reference to keyboard instance from core.
		/// @param mouse Reference to mouse instance from core.
		Camera(glm::vec3 position, glm::vec3 target, std::shared_ptr<Keyboard> keyboard, std::shared_ptr<Mouse> mouse);

		/// Initialises camera with input devices and timer.
		/// 
		/// @param keyboard Reference to keyboard instance from core.
		/// @param mouse Reference to mouse instance from core.
		/// @param timer Reference to timer instance from core.
		/// @see Keyboard Mouse Timer
		Camera::Camera(std::shared_ptr<Keyboard> keyboard, std::shared_ptr<Mouse> mouse, std::shared_ptr<Timer> timer);
		~Camera();

		/// Handles mouse input and updates viewing matrix accordingly once per tick.
		///
		/// Calls the HandleMouseInput function to get user input for camera rotation and updates viewing matrix.
		void OnTick();
		
		/// Initializes camera variables.
		///
		/// Sets projection matrix, camera position, front and up vector and viewing matrix.
		/// @returns true
		bool Initialize();
		
		/// Returns current core instance.
		/// @returns Pointer to core instance.
		std::weak_ptr<Core> GetCore();
		
		/// Get viewing matrix.
		/// @returns viewingMatrix
		glm::mat4 GetView();

		/// Get projection matrix.
		/// @returns projectionMatrix
		glm::mat4 GetProjection();

		/// Get camera position.
		/// @returns cameraPosition.
		glm::vec3 GetCameraPos();

		/// Handles keyboard input for moving the camera around.
		/// Not currently used.
		/// Polls keyboard for keys pressed and changes cameraPosition accordingly.
		/// @see Keyboard
		void HandleKeyboardInput();

		/// Handles mouse input for rotating camera.
		///
		/// Polls mouse for mouse movement and changes pitch and yaw. These valuees are used to construct a new front vector.
		void HandleMouseInput();

		/// Sets camera position from input.
		///
		/// @param cameraPosition New camera position.
		void SetCameraPos(glm::vec3 cameraPosition);

		/// Sets projection matrix from input.
		///
		/// @param projectionMatrix New projection matrix.
		void SetProjection(glm::mat4 projectionMatrix);

		/// Sets view matrix from input.
		///
		/// @param viewingMatrix New viewing matrix.
		void SetView(glm::mat4 viewingMatrix);

		/// Function allowing camera to follow object/player.
		///
		/// @param goalPosition Position of object to be followed.
		/// @param offset Desired offset for the camera in local space.
		/// @param heading Local rotation of object.
		void Follow(glm::vec3 goalPosition, glm::vec3 offset, glm::vec3 heading);

	private:
		/// Pointer to core instance.
		std::weak_ptr<Core> core;
		/// Pointer to mouse instance from Core.
		std::shared_ptr<Mouse> mouse;
		/// Pointer to keyboard instance from Core.
		std::shared_ptr<Keyboard> keyboard;
		/// Pointer to timer instance from Core.
		std::shared_ptr<Timer> timer;
		/// Viewing matrix for camera.
		glm::mat4 viewingMatrix;
		/// Projection matrix for camera.
		glm::mat4 projectionMatrix;
		/// Position of camera in world space.
		glm::vec3 cameraPosition;
		/// Target position for camera.
		glm::vec3 cameraTarget;
		/// Directional vector for camera.
		glm::vec3 cameraDirection;
		/// Up vector for current camera position/rotation.
		glm::vec3 cameraUp;
		/// Front vector for current camera position/rotation.
		glm::vec3 cameraFront;
		/// Offset from followed object.
		glm::vec3 offset;
		/// Last known position of player/goal object.
		glm::vec3 playerPosition;
		/// Last known rotation of player/ goal object.
		glm::vec3 playerHeading;

		/// Pitch of camera in degrees (Up Down rotation)
		float pitch;
		/// Yaw of camera in degrees (Left right rotation)
		float yaw;
	};


}
#endif // !_CAMERA_H_
