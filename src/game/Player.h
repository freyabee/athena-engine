#pragma once
#ifndef  _PLAYER_H_
#define _PLAYER_H_
#endif // ! _PLAYER_H_
#include <prometheus/prometheus.h>
#include <iostream>

class Player : public prometheus::Component
{
public:
	Player();
	~Player();

	void HandleInput();
	void PlayerRotation();
	void PlayerMovement();

	void SetRotationalSpeed(float rotationalSpeed);
	void SetSpeed(float speed);
private:
	void OnDisplay();
	void OnTick();
	void OnInit();

	std::shared_ptr<prometheus::Keyboard> keyboard;
	float xAngle = 0.f;
	float yAngle = 0.f;
	float velocity;
	float maxVelocity;
	float rotationalSpeed = 5;
	float speed = 0.f;
	float decel = 0.5f;
	float accel = 0.5f;
	float speedcap = 50.f;
	float factor= 0.1f;
};
