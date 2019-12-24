#include "Player.h"
#include "Entity.h"
#include "Transform.h"
#include "Core.h"
#include "Keyboard.h"

namespace prometheus
{
	Player::Player()
	{
	}
	Player::~Player()
	{
	}
	void Player::HandleInput()
	{
		//PlayerRotation();
		//PlayerMovement();
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
		float dx = 0.f;
		float dy = 0.f;
		float dz = 0.f;
		if (keyboard->GetKey(SDLK_w))
		{
			dz += 1.f;
		}
		if (keyboard->GetKey(SDLK_s))
		{
			dz += -1.f;
		}
		if (keyboard->GetKey(SDLK_a))
		{
			dx += 1.f;
		}
		if (keyboard->GetKey(SDLK_d))
		{
			dx += -1.f;
		}
		GetEntity()->GetTransform()->Move(glm::vec3(dx, dy, dz));

	}
	void Player::onDisplay()
	{
	}
	void Player::onInit()
	{
		keyboard = GetCore()->GetKeyboard();
	}
	void Player::onTick()
	{
		HandleInput();
	}




}