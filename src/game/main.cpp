#include <iostream>
#include <prometheus/prometheus.h>

int main()
{
	const char* materialShader =
		"#ifdef VERTEX                                 \n" \
		"                                              \n" \
		"attribute vec3 a_Position;                    \n" \
		"attribute vec2 a_TexCoord;                    \n" \
		"attribute vec3 a_Normal;                      \n" \
		"                                              \n" \
		"uniform mat4 u_Projection;                    \n" \
		"uniform mat4 u_Model;                         \n" \
		"uniform mat4 u_View;                         \n" \
		"                                              \n" \
		"varying vec3 v_Normal;                        \n" \
		"varying vec2 v_TexCoord;                      \n" \
		"                                              \n" \
		"void main()                                   \n" \
		"{                                             \n" \
		"  gl_Position = u_Projection *                \n" \
		"    u_View * u_Model * vec4(a_Position, 1);            \n" \
		"                                              \n" \
		"  v_Normal = a_Normal;                        \n" \
		"  v_TexCoord = a_TexCoord;                    \n" \
		"}                                             \n" \
		"                                              \n" \
		"#endif                                        \n" \
		"#ifdef FRAGMENT                               \n" \
		"                                              \n" \
		"uniform sampler2D u_Texture;                  \n" \
		"                                              \n" \
		"varying vec3 v_Normal;                        \n" \
		"varying vec2 v_TexCoord;                      \n" \
		"                                              \n" \
		"void main()                                   \n" \
		"{                                             \n" \
		"  gl_FragColor = texture2D(u_Texture, v_TexCoord);      \n" \
		"  if(gl_FragColor.x == 9) gl_FragColor.x = v_Normal.x;  \n" \
		"}                                             \n" \
		"                                              \n" \
		"#endif                                        \n";

	const char* skyboxShader =
		"#ifdef VERTEX                                 \n" \
		"                                              \n" \
		"                                              \n" \
		"layout (location=0) in vec3 aPos;             \n" \
		"out vec3 TexCoords;                           \n" \
		"uniform mat4 projection;                      \n" \
		"uniform mat4 view;                            \n" \
		"                                              \n" \
		"void main()                                   \n" \
		"{                                             \n" \
		"  TexCoords = aPos                            \n" \
		"  gl_Position = projection * view * vec4(aPos, 1.0); \n" \
		"}                                             \n" \
		"                                              \n" \
		"#endif                                        \n" \
		"#ifdef FRAGMENT                               \n" \
		"                                              \n" \
		"out vec4 FragColor                            \n" \
		"                                              \n" \
		"in vec3 TexCoords                             \n" \
		"uniform samplerCube skybox;                   \n" \
		"                                              \n" \
		"void main()                                   \n" \
		"{                                             \n" \
		"  FragColor = texture(skybox, TexCoords);     \n" \
		"  if(gl_FragColor.x == 9) gl_FragColor.x = v_Normal.x;  \n" \
		"}                                             \n" \
		"                                              \n" \
		"#endif                                        \n";



	std::string curuthersModel = "../resources/objs/curuthers.obj";
	std::string curuthersTexture = "../resources/images/curuthers.png";
	//std::string terrainModel = "../resources/objs/pond.obj";
	//std::string terrainTexture = "../resources/images/pond.png";
	std::string coinModel = "../resources/objs/coin.obj";
	std::string coinTexture = "../resources/images/coin.png";
	std::string grassModel = "../resources/objs/Grass.obj";
	std::string grassTexture = "../resources/images/Grass.png";
	std::string pondModel = "../resources/objs/Pond.obj";
	std::string pondTexture = "../resources/images/Pond.png";
	std::string waterModel = "../resources/objs/Water.obj";
	std::string waterTexture = "../resources/images/Water.png";
	std::string treeModel = "../resources/objs/Tree.obj";
	std::string treeTexture = "../resources/images/Tree.png";
	std::string tree2Model = "../resources/objs/TwoTrees.obj";
	std::string tree2Texture = "../resources/images/TwoTrees.png";
	std::string benchModel = "../resources/objs/BenchRock.obj";
	std::string benchTexture = "../resources/images/BenchRock.png";
	std::string sTreeModel = "../resources/objs/SmallTree.obj";
	std::string sTreeTexture = "../resources/images/SmallTree.png";
	std::string shipModel = "../resources/objs/ship.obj";
	std::string shipTexture = "../resources/images/ship.png";

	std::string parkModel = "../resources/objs/squarelake.obj";
	std::string parkTexture = "../resources/images/squarelake
		.png";
	/*Initialize core*/
	std::shared_ptr<prometheus::Core> core = prometheus::Core::initialize();


	/*Initialize player entity*/
	//std::shared_ptr<prometheus::Entity> playerEntity = core->addEntity();
	/* Add mesh and texture to player entity */
	//std::shared_ptr<prometheus::MeshRenderer> playerRenderer = playerEntity->addComponent<prometheus::MeshRenderer>();
	//playerRenderer->LoadModel(curuthersModel, curuthersTexture, materialShader);
	/*Add player component to player entity*/
	//std::shared_ptr<prometheus::Player> player = playerEntity->addComponent<prometheus::Player>();

	/*Coin*/

	std::shared_ptr<prometheus::Entity> eCoin = core->addEntity();
	std::shared_ptr<prometheus::MeshRenderer> coinRenderer = eCoin->addComponent<prometheus::MeshRenderer>();
	coinRenderer->LoadModel(coinModel, coinTexture, materialShader);
	std::shared_ptr<prometheus::Coin> coin = eCoin->addComponent<prometheus::Coin>();



	/* TERRAIN */
	std::shared_ptr<prometheus::Entity> ePark = core->addEntity();
	std::shared_ptr<prometheus::MeshRenderer> parkRenderer = ePark->addComponent<prometheus::MeshRenderer>();
	parkRenderer->LoadModel(parkModel, parkTexture, materialShader);
	ePark->SetPosition(glm::vec3(0.f, 0.f,0.f));

	//Ship
	std::shared_ptr<prometheus::Entity> eShip = core->addEntity();
	std::shared_ptr<prometheus::MeshRenderer> shipRenderer = eShip->addComponent<prometheus::MeshRenderer>();
	shipRenderer->LoadModel(shipModel, shipTexture, materialShader);
	eShip->SetPosition(glm::vec3(0.f, 0.f, 0.f));

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
