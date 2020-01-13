#include "BoxCollider.h"
#include "Core.h"
#include "Transform.h"
#include "Entity.h"

namespace prometheus
{
	void BoxCollider::OnInit()
	{
		size = glm::vec3(1, 1, 1);
		lastPosition = GetTransform()->GetLocalPosition();
	}

	void BoxCollider::SetOffset(const glm::vec3& offset)
	{
		this->offset = offset;
	}

	void BoxCollider::SetSize(const glm::vec3& size)
	{
		this->size = size;
	}

	void BoxCollider::OnTick()
	{
		//CollideStaticMesh();
		CollideBox();
	}

	void BoxCollider::CollideBox()
	{
		std::vector<std::shared_ptr<Entity> > boxColliderEntities;

		GetCore()->GetEntities<BoxCollider>(boxColliderEntities);

		glm::vec3 newPosition = GetTransform()->GetLocalPosition() + offset;

		for (std::vector<std::shared_ptr<Entity> >::iterator it = boxColliderEntities.begin();
			it != boxColliderEntities.end(); it++)
		{
			if (*it == GetEntity())
			{
				continue;
			}
			std::shared_ptr<BoxCollider> otherCollider = (*it)->GetComponent<BoxCollider>();
			glm::vec3 sp = otherCollider->GetCollisionResponse(newPosition, size);
			newPosition = sp;
			newPosition = newPosition - offset;
			GetTransform()->SetLocalPosition(newPosition);
			lastPosition = newPosition;
			
		}
	}

	void BoxCollider::CollideStaticMesh()
	{
		/*
		std::vector<std::sr1::shared_ptr<Entity> > smces;

		//GetCore()->GetEntities<StaticModelCollider>(smces);

		glm::vec3 np = GetTransform()->GetLocalPosition() + offset;

		for (std::vector<std::sr1::shared_ptr<Entity> >::iterator it = smces.begin();
		it != smces.end(); it++)
		{
		//std::sr1::shared_ptr<StaticModelCollider> smc = (*it)->getComponent<StaticModelCollider>();

		bool solved = false;
		glm::vec3 sp = smc->GetCollisionResponse(np, size, solved);

		if (solved)
		{
		np = sp;
		}
		else
		{
		np = lastPosition + offset;
		}

		np = np - offset;
		GetTransform()->SetLocalPosition(np);
		lastPosition = np;
		}
		*/
		
	}

	bool BoxCollider::IsColliding(glm::vec3 position, glm::vec3 size)
	{
		glm::vec3 a = GetTransform()->GetLocalPosition() + offset;
		glm::vec3& as = this->size;
		glm::vec3& b = position;
		glm::vec3& bs = size;

		if (a.x > b.x) // a right of b
		{
			if (a.x - as.x > b.x + bs.x) // left edge of a greater than right edge of b (not colliding)
			{
				return false;
			}
		}
		else
		{
			if (b.x - bs.x > a.x + as.x)
			{
				return false;
			}
		}

		if (a.z > b.z) // a front of b
		{
			if (a.z - as.z > b.z + bs.z) // back edge of a greater than front edge of b (not colliding)
			{
				return false;
			}
		}
		else
		{
			if (b.z - bs.z > a.z + as.z)
			{
				return false;
			}
		}

		if (a.y > b.y) // a above b
		{
			if (a.y - as.y > b.y + bs.y) // bottom edge of a greater than top edge of b (not colliding)
			{
				return false;
			}
		}
		else
		{
			if (b.y - bs.y > a.y + as.y)
			{
				return false;
			}
		}

		return true;
	}

	glm::vec3 BoxCollider::GetCollisionResponse(glm::vec3 position, glm::vec3 size)
	{
		float amount = 0.1f;
		float step = 0.1f;

		while (true)
		{
			if (!IsColliding(position, size)) break;
			position.x += amount;
			if (!IsColliding(position, size)) break;
			position.x -= amount;
			position.x -= amount;
			if (!IsColliding(position, size)) break;
			position.x += amount;
			position.z += amount;
			if (!IsColliding(position, size)) break;
			position.z -= amount;
			position.z -= amount;
			if (!IsColliding(position, size)) break;
			position.z += amount;
			position.y += amount;
			if (!IsColliding(position, size)) break;
			position.y -= amount;
			position.y -= amount;
			if (!IsColliding(position, size)) break;
			position.y += amount;
			amount += step;
		}

		return position;
	}
}


