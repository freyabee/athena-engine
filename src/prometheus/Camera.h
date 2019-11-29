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

		glm::mat4 getView();
		glm::mat4 getProjection();
		glm::vec3 getCameraPos();

		void setCameraPos(glm::vec3 newPosition);
		void setProjection(glm::mat4 newProjection);
		void setView(glm::mat4 newView);

	private:
		glm::mat4 viewingMatrix;
		glm::mat4 projectionMatrix;
		glm::vec3 cameraPosition;
	};


}
#endif // !_CAMERA_H_
