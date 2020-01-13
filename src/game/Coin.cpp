#include "Coin.h"

Coin::Coin()
{
	angleRotation = 0.f;
}
Coin::~Coin()
{

}
void Coin::OnDisplay()
{

}
void Coin::OnTick()
{
	float speed = 1.f;
	GetTransform()->AddRotation(glm::vec3(0.f, 0.f, speed * 1.f));

}
void Coin::OnInit()
{
	GetTransform()->SetLocalRotation(glm::vec3(90.f, 0.f, 0.f));
	GetTransform()->SetLocalPosition(glm::vec3(0.f, 1.f, 0.f));
}
