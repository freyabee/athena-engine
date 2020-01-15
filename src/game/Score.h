#pragma once
#ifndef _SCORE_H_
#define _SCORE_H_
#endif // !_SCORE_H_
#include "prometheus/prometheus.h"
#include "rend/rend.h"

class Score : public prometheus::Component
{
public:
	Score();
	Score(std::string texturePath);
	~Score();
	void OnInit();
	void OnGUI();
private:
	std::shared_ptr<prometheus::Material> mat;
	std::shared_ptr<prometheus::Material> logo;
	std::string texturePath;

};