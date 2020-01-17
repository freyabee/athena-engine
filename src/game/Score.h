#pragma once
#ifndef _SCORE_H_
#define _SCORE_H_
#endif // !_SCORE_H_
#include "prometheus/prometheus.h"
#include "rend/rend.h"

class Score : public prometheus::Component
{
public:
	Score(std::shared_ptr<prometheus::Entity> player);
	Score(std::string texturePath);
	~Score();
	void OnInit();
	void OnTick();
	void OnGUI();
private:
	std::shared_ptr<prometheus::Material> scoreGUI;
	std::vector < std::shared_ptr<prometheus::Material>> numbers;
	std::string texturePath;
	std::shared_ptr<prometheus::Entity> player;

	int score;
	int lastScore;
};