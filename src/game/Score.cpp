#include "prometheus/prometheus.h"
#include "Score.h"

Score::Score(std::string texturePath)
{
	this->texturePath = texturePath;
}
Score::~Score()
{
}
void Score::OnInit()
{
	mat = std::make_shared<prometheus::Material>();
	mat->LoadTexture(texturePath, GetCore());
}
void Score::OnGUI()
{
	GetCore()->GetGUI()->Texture(glm::vec4(10, 10, 100, 100), mat->GetTexture());
}