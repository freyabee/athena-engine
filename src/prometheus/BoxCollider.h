#include "Component.h"
#include <glm/glm.hpp>

namespace prometheus
{
	///  Class defining box collider component.
	///
	///
	class BoxCollider : public Component
	{
	public:
		/// Initializes box collider component.
		/// Sets size and and orgin.
		void OnInit();
		/// Set offset transform.
		/// @param offset New collider offset.
		void SetOffset(const glm::vec3& offset);
		/// Set size.
		/// @ param 
		void SetSize(const glm::vec3& size);

	private:
		/// Handles functions called every tick.
		/// Calls collide box.
		void OnTick();
		/// Handles collisions between current box collider and static meshes in scene.
		void CollideStaticMesh();

		void CollideBox();

		glm::vec3 size;
		glm::vec3 offset;
		glm::vec3 lastPosition;

		bool IsColliding(glm::vec3 position, glm::vec3 size);
		glm::vec3 GetCollisionResponse(glm::vec3 position, glm::vec3 size);
	};
}

