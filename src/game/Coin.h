#pragma once
#ifndef _COIN_H_
#define _COIN_H_
#endif // !_COIN_H_
#include <prometheus/prometheus.h>
#include <iostream>

class Coin : public prometheus::Component
{
public:
	Coin();
	~Coin();

	void onDisplay();
	void onTick();
	void onInit();

private:
	float angleRotation;

};