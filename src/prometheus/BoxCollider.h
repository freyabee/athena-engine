#include "Component.h"
#include <glm/glm.hpp>
#include <string>
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

		/// Set unique ID for collider
		///
		/// @param uID String to be set to new ID.
		void SetUniqueID(std::string uID);

		/// Return if trigger has been collided in this update.
		///
		/// @returns if trigger has collided to another collider this tick.
		bool GetTriggerCollided();
		/// Set box collider to type trigger, changes trigger variable.
		/// @param b Bool denoting if box collider has been collided with this tick.
		void SetTrigger(bool b);
		/// Returns if collider is trigger.
		/// @returns Bool denoting if box collider is trigger.
		bool IsTrigger();
	private:
		/// Handles functions called every tick.
		/// Calls collide box.
		void OnTick();
		/// Handles functions called every tick, called before on tick.
		void OnEarlyUpdate();
		/// Handles collisions between current box collider and static meshes in scene.
		void CollideStaticMesh();

		void CollideBox();

		glm::vec3 size;
		glm::vec3 offset;
		glm::vec3 lastPosition;
		bool trigger = false;
		bool triggerCollided = false;
		std::string uniqueID;
		bool IsColliding(glm::vec3 position, glm::vec3 size);
		glm::vec3 GetCollisionResponse(glm::vec3 position, glm::vec3 size);
	};
}

