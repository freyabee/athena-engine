#include "Coin.h"

#include "Entity.h"
#include "Transform.h"
#include "Core.h"
#include "Timer.h"
namespace prometheus
{
	Coin::Coin()
	{
		angleRotation = 0.f;
	}
	Coin::~Coin()
	{

	}
	void Coin::onDisplay()
	{

	}
	void Coin::onTick()
	{
		float speed = 1.f;
		GetTransform()->AddRotation(glm::vec3(0.f, 0.f, speed * 1.f));

	}
	void Coin::onInit()
	{
		GetTransform()->SetLocalRotation(glm::vec3(90.f, 0.f, 0.f));
		GetTransform()->SetLocalPosition(glm::vec3(0.f, 1.f, 0.f));
	}
}