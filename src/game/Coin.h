#pragma once
#ifndef _COIN_H_
#define _COIN_H_
#endif // !_COIN_H_
#include <prometheus/prometheus.h>
#include <iostream>
#include <memory>
class Coin : public prometheus::Component
{
public:
	Coin(std::shared_ptr<prometheus::Entity> player);
	~Coin();
	
	void SetSpeed(float speed);
	void OnDisplay();
	void OnTick();
	void OnInit();

private:
	float speed;
	float angleRotation;
	std::shared_ptr<prometheus::Entity> player;
	std::shared_ptr<prometheus::Environment> environment;
	std::shared_ptr<prometheus::SoundSource> coinSound;

};