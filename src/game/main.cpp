#include "Coin.h"
#include "Player.h"
#include "Score.h"

#include <iostream>
#include <prometheus/prometheus.h>



int main()
{
	//Models
	//Coin
	std::string coinModel = "../resources/objs/coin.obj";
	std::string coinTexture = "../resources/images/coin.png";
	//Ship
	std::string shipModel = "../resources/objs/sailboat.obj";
	std::string shipTexture = "../resources/images/sailboat.png";
	//Park
	std::string parkModel = "../resources/objs/squarelake.obj";
	std::string parkTexture = "../resources/images/squarelake.png";
	//Waterplane
	std::string mWater = "../resources/objs/waterplane.obj";
	std::string tWater = "../resources/images/water.png";
	//Shaders
	std::string materialShader = "../resources/shaders/matShader.txt";
	//std::string waterShader = "../resources/shaders/waterShader.txt";

	//Initialize core
	std::shared_ptr<prometheus::Core> core = prometheus::Core::initialize();

	

	//Coin
	std::shared_ptr<prometheus::Entity> eCoin = core->addEntity();
	std::shared_ptr<prometheus::MeshRenderer> coinRenderer = eCoin->addComponent<prometheus::MeshRenderer>();
	coinRenderer->LoadModel(coinModel, coinTexture, materialShader);
	std::shared_ptr<Coin> coin = eCoin->addComponent<Coin>();
	std::shared_ptr<prometheus::BoxCollider> coinCollider = eCoin->addComponent<prometheus::BoxCollider>();
	coinCollider->SetSize(glm::vec3(1.f));

	//TERRAIN
	std::shared_ptr<prometheus::Entity> ePark = core->addEntity();
	std::shared_ptr<prometheus::MeshRenderer> parkRenderer = ePark->addComponent<prometheus::MeshRenderer>();
	parkRenderer->LoadModel(parkModel, parkTexture, materialShader);
	ePark->SetPosition(glm::vec3(0.f, 0.f, 0.f));

	//Ship
	std::shared_ptr<prometheus::Entity> eShip = core->addEntity();
	std::shared_ptr<prometheus::MeshRenderer> shipRenderer = eShip->addComponent<prometheus::MeshRenderer>();
	shipRenderer->LoadModel(shipModel, shipTexture, materialShader);
	std::shared_ptr<prometheus::BoxCollider> shipCollider = eShip->addComponent<prometheus::BoxCollider>();
	shipCollider->SetSize(glm::vec3(1.f));
	eShip->addComponent<Player>();

	//Water
	//std::shared_ptr<prometheus::Entity> eWater = core->addEntity();
	//std::shared_ptr<prometheus::MeshRenderer> rWater = eWater->addComponent<prometheus::MeshRenderer>();
	//rWater->LoadModel(mWater, tWater, materialShader);

	//GUI
	std::shared_ptr<prometheus::Entity> eGUI = core->addEntity();
	eGUI->addComponent<Score>("../resources/images/dab.png");

	/*
	std::shared_ptr<prometheus::Sound> sound1 = core->GetResources()->load<prometheus::Sound>("../resources/sounds/dixie_horn.ogg");
	std::shared_ptr<prometheus::SoundSource> dixie = entity->addComponent<prometheus::SoundSource>();
	dixie->onInit(sound1);
	*/

	core->start();


	std::cout << "Welcome to Prometheus" << std::endl;
	system("pause");
	return 0;
}
