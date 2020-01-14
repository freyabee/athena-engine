#pragma once
#ifndef _SCORE_H_
#define _SCORE_H_
#endif // !_SCORE_H_
#include "prometheus/prometheus.h"

namespace prometheus
{
	class Score : public Component
	{
	public:
		Score();
		Score(std::string texturePath);
		~Score();
		void OnInit();
		void OnGUI();
	private:
		std::shared_ptr<Material> logo;
		std::string texturePath;

	};
}