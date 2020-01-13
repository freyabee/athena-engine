#include "Component.h"
#include <glm/glm.hpp>

namespace prometheus
{
	class BoxCollider : public Component
	{
	public:
		void OnInit();
		void SetOffset(const glm::vec3& offset);
		void SetSize(const glm::vec3& size);

	private:
		void OnTick();

		void CollideStaticMesh();
		void CollideBox();

		glm::vec3 size;
		glm::vec3 offset;
		glm::vec3 lastPosition;

		bool IsColliding(glm::vec3 position, glm::vec3 size);
		glm::vec3 GetCollisionResponse(glm::vec3 position, glm::vec3 size);
	};
}

