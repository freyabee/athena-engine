#pragma once
#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <glm/glm.hpp>
namespace prometheus
{
	class Camera
	{
	public:
		Camera();
		~Camera();

		glm::mat4 GetView();
		glm::mat4 GetProjection();
		glm::vec3 GetCameraPos();

		void SetCameraPos(glm::vec3 _cameraPosition);
		void SetProjection(glm::mat4 _projectionMatrix);
		void SetView(glm::mat4 _viewingMatrix);

	private:
		glm::mat4 viewingMatrix;
		glm::mat4 projectionMatrix;
		glm::vec3 cameraPosition;
	};


}
#endif // !_CAMERA_H_
