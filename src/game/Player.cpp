#include "Player.h"


Player::Player()
{

}
Player::~Player()
{
}
void Player::HandleInput()
{
	PlayerRotation();
	PlayerMovement();
}
void Player::PlayerRotation()
{
	xAngle = 0.f;
	yAngle = 0.f;

	if (keyboard->GetKey(SDLK_a))
	{
		xAngle = 5.f;
	}
	else if (keyboard->GetKey(SDLK_d))
	{
		xAngle = -5.f;
	}
	GetEntity()->GetTransform()->rotate(xAngle, glm::vec3(0.f, 1.f, 0.f));
	GetEntity()->GetTransform()->rotate(yAngle, glm::vec3(1.f, 0.f, 0.f));
}
void Player::PlayerMovement()
{
	float speed = 0.1f;
	float dx = 0.f;
	float dy = 0.f;
	float dz = 0.f;

	float rotationX = 0.f;
	if (keyboard->GetKey(SDLK_w))
	{
		dz += 1.f*speed;
	}
	else
	{
		if (speed > 0)
		{

		}
	}
	if (keyboard->GetKey(SDLK_s))
	{
		dz += -1.f*speed;
	}
	if (keyboard->GetKey(SDLK_a))
	{
		//dx += 1.f*speed;
		rotationX += 1.f;
	}
	if (keyboard->GetKey(SDLK_d))
	{
		//dx += -1.f*speed;
		rotationX -= 1.f;
	}

	if (dz != 0.f)
	{
		GetEntity()->GetTransform()->AddRotation(glm::vec3(0.f, rotationX, 0.f));	
	}
	glm::vec3 movement(0.f);
	glm::vec3 heading = GetTransform()->GetLocalRotation();
	movement.x = dz * sin(glm::radians(heading.y));
	movement.z = dz * cos(glm::radians(heading.y));
	//glm::vec3 movement(0.f);
	//movement.x = dx;
	//movement.z = dz;


	GetEntity()->GetTransform()->Move(glm::vec3(movement.x, movement.y, movement.z));

	//std::cout << movement.x << "," << movement.y << std::endl;
	//std::cout << heading.x << heading.y << heading.z << std::endl;



	glm::vec3 playerPosition = GetTransform()->GetLocalPosition();
	glm::vec3 offset(0.f, -5.f, -7.f);
	//offset.z = -cos(glm::radians(heading.y))*2.f;
	//offset.x = -sin(glm::radians(heading.y))*2.f;
	GetCamera()->Follow(playerPosition, offset, heading);
}
void Player::OnDisplay()
{
}
void Player::OnInit()
{
	keyboard = GetCore()->GetKeyboard();
	GetTransform()->SetLocalPosition(0.f, 1.f, -3.f);
}
void Player::OnTick()
{
	HandleInput();
}