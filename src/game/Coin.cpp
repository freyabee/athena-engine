#include "Coin.h"

Coin::Coin(std::shared_ptr<prometheus::Entity> player)
{
	angleRotation = 0.f;
	this->player = player;
	environment = this->player->GetCore()->GetEnvironment();
	speed = 40.f;
}
Coin::~Coin()
{

}
void Coin::SetSpeed(float speed)
{
	this->speed = speed;
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
		coinSound->Play();
		GetTransform()->SetLocalPosition(glm::vec3(randomX, 1.f, randomY));
	}
	float x = environment->GetDeltaTime();
	GetTransform()->AddRotation(glm::vec3(0.f, 0.f, (environment->GetDeltaTime()* speed * 1.f)));
	//std::cout << environment->GetDeltaTime()*speed * 1.f << std::endl;

}
void Coin::OnInit()
{
	GetTransform()->SetLocalRotation(glm::vec3(90.f, 0.f, 0.f));
	GetTransform()->SetLocalPosition(glm::vec3(0.f, 1.f, 0.f));
	try
	{
		coinSound = GetEntity()->GetComponent<prometheus::SoundSource>();
	}
	catch (std::exception& e)
	{
		std::cout << "Sound loading failed : ";
		std::cout << e.what() << std::endl;
	}

}
