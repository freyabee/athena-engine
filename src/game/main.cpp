#include "Coin.h"
#include "Player.h"
#include "Score.h"

#include <iostream>
#include <prometheus/prometheus.h>



int main()
{
	//Models
	//Coin
	std::string coinModel = "../resources/objs/final/coin.obj";
	std::string coinTexture = "../resources/images/coin.png";
	//Ship
	std::string shipModel = "../resources/objs/sailboat.obj";
	std::string shipTexture = "../resources/images/sailboat.png";
	//Park
	std::string parkModel = "../resources/objs/final/lake.obj";
	std::string parkTexture = "../resources/images/textures/lake.png";
	//Trees
	std::string mTree = "../resources/objs/final/grove.obj";
	std::string tTree = "../resources/images/textures/grove.png";
	//Waterplane
	std::string mWater = "../resources/objs/final/waterplane.obj";
	std::string tWater = "../resources/images/textures/waterplane.png";
	//Shaders
	std::string materialShader = "../resources/shaders/matShader.txt";
	//std::string waterShader = "../resources/shaders/waterShader.txt";

	//GUI

	//Initialize core
	std::shared_ptr<prometheus::Core> core = prometheus::Core::initialize();

	

	
	/*
	
	*/
	//TERRAIN
	std::shared_ptr<prometheus::Entity> ePark = core->addEntity();
	std::shared_ptr<prometheus::MeshRenderer> parkRenderer = ePark->addComponent<prometheus::MeshRenderer>();
	parkRenderer->LoadModel(parkModel, parkTexture, materialShader);
	ePark->SetPosition(glm::vec3(0.f, 0.f, 0.f));

	//TREE
	std::shared_ptr<prometheus::Entity> eTree = core->addEntity();
	std::shared_ptr<prometheus::MeshRenderer> treeRenderer = eTree->addComponent<prometheus::MeshRenderer>();
	treeRenderer->LoadModel(mTree, tTree, materialShader);
	eTree->SetPosition(glm::vec3(0.f, 0.f, 0.f));

	//Ship
	std::shared_ptr<prometheus::Entity> eShip = core->addEntity();
	std::shared_ptr<prometheus::MeshRenderer> shipRenderer = eShip->addComponent<prometheus::MeshRenderer>();
	shipRenderer->LoadModel(shipModel, shipTexture, materialShader);
	std::shared_ptr<prometheus::BoxCollider> shipCollider = eShip->addComponent<prometheus::BoxCollider>();
	shipCollider->SetTrigger(true);
	shipCollider->SetSize(glm::vec3(1.f));
	eShip->addComponent<Player>();
	eShip->SetPosition(glm::vec3(-1.f, 0.f, 0.f));

	//Coin
	std::shared_ptr<prometheus::Entity> eCoin = core->addEntity();
	std::shared_ptr<prometheus::MeshRenderer> coinRenderer = eCoin->addComponent<prometheus::MeshRenderer>();
	coinRenderer->LoadModel(coinModel, coinTexture, materialShader);
	std::shared_ptr<Coin> coin = eCoin->addComponent<Coin>(eShip);
	std::shared_ptr<prometheus::BoxCollider> coinCollider = eCoin->addComponent<prometheus::BoxCollider>();
	coinCollider->SetSize(glm::vec3(1.f));
	//coinCollider->SetTrigger(true);

	//Water
	std::shared_ptr<prometheus::Entity> eWater = core->addEntity();
	std::shared_ptr<prometheus::MeshRenderer> rWater = eWater->addComponent<prometheus::MeshRenderer>();
	rWater->LoadModel(mWater, tWater, materialShader);
	eWater->SetPosition(glm::vec3(0.f, 0.f, 0.f));

	//GUI
	std::shared_ptr<prometheus::Entity> eGUI = core->addEntity();
	eGUI->addComponent<Score>(eShip);

	//SOUND SOURCE
	std::shared_ptr<prometheus::Sound> coinSound = core->GetResources()->load<prometheus::Sound>("../resources/sounds/coin.ogg");
	//std::shared_ptr<prometheus::Entity> soundPlayer = core->addEntity();
	std::shared_ptr<prometheus::SoundSource> sound = eCoin->addComponent <prometheus::SoundSource>();
	sound->OnInit(coinSound);

	core->start();


	std::cout << "Welcome to Prometheus" << std::endl;
	system("pause");
	return 0;
}
