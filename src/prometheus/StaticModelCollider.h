#include "Component.h"
#include <sr1/zero_initialized>
#include <sr1/memory>

#include <vector>

namespace prometheus
{
	class MeshRenderer;

	struct Extent
	{
		glm::vec3 max;
		glm::vec3 min;
	};

	struct ColliderColumn
	{
		glm::vec3 position;
		glm::vec3 size;
		std::vector<qsoft::Face> faces;
		bool IsColliding(glm::vec3 position, glm::vec3 size);
		void GetColliding(glm::vec3 position, glm::vec3 size, std::vector<qsoft::Face>& collisions);
	};

	class StaticModelCollider : public Component
	{
		std::vector<std::sr1::shared_ptr<ColliderColumn> > cols;
		Extent extent;
		std::sr1::zero_initialized<float> resolution;
		std::sr1::zero_initialized<float> tryStep;
		std::sr1::zero_initialized<float> maxStep;
		std::sr1::zero_initialized<float> tryInc;
		std::sr1::zero_initialized<float> maxInc;
		std::vector<qsoft::Face> collisions;
		void GenerateExtent();
		void AddFace(qsoft::Face face);
		glm::vec3 FaceNormal(qsoft::Face& face);

	public:
		void onInit();
		Extent GetExtent();
		bool IsColliding(qsoft::Face& face, glm::vec3 position, glm::vec3 size);
		bool IsColliding(glm::vec3 position, glm::vec3 size);
		void GetColliding(glm::vec3 position, glm::vec3 size);
		glm::vec3 GetCollisionResponse(glm::vec3 position, glm::vec3 size, bool& solved);

	};

}
