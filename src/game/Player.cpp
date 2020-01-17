#include "Player.h"


Player::Player()
{
	rotationalSpeed = 20.f;
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
	float dt = GetEnvironment()->GetDeltaTime();

	if (keyboard->GetKey(SDLK_a))
	{
		xAngle = dt * rotationalSpeed* 1.f;
	}
	else if (keyboard->GetKey(SDLK_d))
	{
		xAngle = dt * rotationalSpeed * -1.f;
	}
	GetEntity()->GetTransform()->Rotate(xAngle, glm::vec3(0.f, 1.f, 0.f));
}
void Player::PlayerMovement()
{
	float dx = 0.f;
	float dy = 0.f;
	float dz = 0.f;
	float dt = GetEnvironment()->GetDeltaTime();



	float rotationX = 0.f;
	if (keyboard->GetKey(SDLK_w))
	{
		speed += accel;
		if (speed > speedcap)
		{
			speed = speedcap;
		}
		dz += factor*speed * dt;
	}
	else
	{
		if (speed > 0)
		{
			speed = speed - decel;
			dz += factor*speed*dt;
		}
	}
	if (keyboard->GetKey(SDLK_s))
	{
	}
	if (keyboard->GetKey(SDLK_a))
	{
		rotationX += factor*dt*rotationalSpeed*speed;
	}
	if (keyboard->GetKey(SDLK_d))
	{
		rotationX -= factor*dt*rotationalSpeed*speed;
	}
	
	GetEntity()->GetTransform()->AddRotation(glm::vec3(0.f, rotationX, 0.f));

	glm::vec3 movement(0.f);
	glm::vec3 heading = GetTransform()->GetLocalRotation();
	movement.x = dz * sin(glm::radians(heading.y));
	movement.z = dz * cos(glm::radians(heading.y));
	GetEntity()->GetTransform()->Move(glm::vec3(movement.x, movement.y, movement.z));
	glm::vec3 playerPosition = GetTransform()->GetLocalPosition();
	glm::vec3 offset(0.f, -2.f, -3.f);
	GetCamera()->Follow(playerPosition, offset, heading);
}
void Player::SetRotationalSpeed(float rotationalSpeed)
{
	this->rotationalSpeed = rotationalSpeed;
}
void Player::SetSpeed(float speed)
{
	this->speed = rotationalSpeed;
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