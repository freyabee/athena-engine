#include "Coin.h"

Coin::Coin(std::shared_ptr<prometheus::Entity> player)
{
	angleRotation = 0.f;
	this->player = player;
}
Coin::~Coin()
{

}
void Coin::OnDisplay()
{

}
void Coin::OnTick()
{
	float randomX = rand() % 10 + (-5);
	float randomY = rand() % 19 + (-9);

	if (player->GetComponent<prometheus::BoxCollider>()->GetTriggerCollided())
	{
		GetTransform()->SetLocalPosition(glm::vec3(randomX, 0, randomY));
	}

	float speed = 1.f;
	GetTransform()->AddRotation(glm::vec3(0.f, 0.f, speed * 1.f));

}
void Coin::OnInit()
{
	GetTransform()->SetLocalRotation(glm::vec3(90.f, 0.f, 0.f));
	GetTransform()->SetLocalPosition(glm::vec3(0.f, 1.f, 0.f));
}
