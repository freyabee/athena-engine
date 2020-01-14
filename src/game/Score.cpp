#include "Score.h"


namespace prometheus
{
	Score::Score()
	{

	}
	Score::Score(std::string texturePath)
	{

	}
	Score::~Score()
	{
	}
	void Score::OnInit()
	{
		logo = GetCore()->GetResources()->load<Texture>(texturePath);
	}
	void Score::OnGUI()
	{
		GetCore()->GetGUI()->
	}
}