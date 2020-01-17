#include "prometheus/prometheus.h"
#include "Score.h"

Score::Score(std::shared_ptr<prometheus::Entity> player)
{
	this->player = player;
	score = 0;
}
Score::~Score()
{
}
void Score::OnInit()
{
	try
	{
		scoreGUI = std::make_shared<prometheus::Material>();
		scoreGUI->LoadTexture("../resources/images/ui/score.png", GetCore());
	}
	catch (std::exception &e)
	{
		std::cout << "Error loading UI element" << e.what() << std::endl;
	}
	

	for (int i = 0; i <= 9; i++)
	{
		try
		{
			std::cout << "Initialising UI textures: ";
			std::string path = "../resources/images/ui/" + std::to_string(i) + ".png";

			std::shared_ptr<prometheus::Material> temp = std::make_shared<prometheus::Material>();
			temp->LoadTexture(path, GetCore());
			numbers.push_back(temp);
			std::cout << "success" << std::endl;
		}
		catch (std::exception&e)
		{
			std::cout << "failed with error " << e.what() << std::endl;
		}
	}
	score = 0;
	lastScore = score;

}

void Score::OnTick()
{
	bool coinGet = player->GetComponent<prometheus::BoxCollider>()->GetTriggerCollided();
	if (coinGet)
	{

		//std::cout << "Coin touched" << std::endl;
		score += 1;
	}
}

void Score::OnGUI()
{
	int scoreWidth = 128;
	int height = 68;
	int numberHeight = 68;
	int numberWidth = 28;
	int buffer = 10;

	GetCore()->GetGUI()->Texture(glm::vec4(10, 10, 128, 68), scoreGUI->GetTexture());
	std::string scoreStr = std::to_string(score);

	
	for (int i = 0; i < scoreStr.length(); i++)
	{
		lastScore = score;

		try
		{
			int digit = (int)scoreStr.at(i) - 48;
			GetCore()->GetGUI()->Texture(glm::vec4((scoreWidth + (buffer * 2) + (numberWidth*i)), 10, numberWidth, numberHeight), numbers.at(digit)->GetTexture());
		}
		catch (std::exception& e)
		{
			std::cout << "Problem rendering score: ";
			std::cout << e.what() << std::endl;
		}
	}
	
}