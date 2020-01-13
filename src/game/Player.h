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
private:
	void OnDisplay();
	void OnTick();
	void OnInit();

	std::shared_ptr<prometheus::Keyboard> keyboard;
	float xAngle = 0.f;
	float yAngle = 0.f;

};
