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
		"                                              \n" \
		"varying vec3 v_Normal;                        \n" \
		"varying vec2 v_TexCoord;                      \n" \
		"                                              \n" \
		"void main()                                   \n" \
		"{                                             \n" \
		"  gl_Position = u_Projection *                \n" \
		"    u_Model * vec4(a_Position, 1);            \n" \
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


	std::string curuthersModel = "../resources/objs/curuthers.obj";
	std::string curuthersTexture = "../resources/images/curuthers.png";


	std::string graveyardModel = "../resources/objs/graveyard.obj";
	std::string graveyardTexture = "../resources/images/graveyard.png";
	/*Initialize core*/
	std::shared_ptr<prometheus::Core> core = prometheus::Core::initialize();


	/*Initialize player entity*/
	std::shared_ptr<prometheus::Entity> playerEntity = core->addEntity();
	/* Add mesh and texture to player entity */
	std::shared_ptr<prometheus::MeshRenderer> playerRenderer = playerEntity->addComponent<prometheus::MeshRenderer>();
	playerRenderer->LoadModel(curuthersModel, curuthersTexture, materialShader);
	/*Add player component to player entity*/
	std::shared_ptr<prometheus::Player> player = playerEntity->addComponent<prometheus::Player>();

	/* TERRAIN */
	/*Initialize terraom entity*/
	std::shared_ptr<prometheus::Entity> terrainEntity = core->addEntity();
	/* Add mesh and texture for terrain */
	std::shared_ptr<prometheus::MeshRenderer> terrainRenderer = terrainEntity->addComponent<prometheus::MeshRenderer>();
	terrainRenderer->LoadModel(graveyardModel, graveyardTexture, materialShader);
	terrainEntity->SetPosition(glm::vec3(0.f, -5.f, 0.f));

	/*
	//Load Resources
	std::shared_ptr<prometheus::Model> m1 = core->GetResources()->load<prometheus::Model>("../resources/objs/curuthers.obj");
	//TODO:  SetMesh in mesh renderer
	renderer->SetModel(m1);
	std::shared_ptr<prometheus::Material> mat1 = core->GetResources()->load<prometheus::Material>(materialShader);
	mat1->LoadShader(materialShader);
	mat1->LoadTexture("../resources/images/curuthers.png");
	renderer->SetMaterial(mat1);
	*/
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
