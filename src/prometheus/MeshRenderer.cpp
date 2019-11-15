#include "MeshRenderer.h"


namespace prometheus
{
	MeshRenderer::MeshRenderer()
	{
		windowHeight = 480;
		windowWidth = 640;

		const char* src =
			"#ifdef VERTEX                                 \n" \
			"                                              \n" \
			"attribute vec3 a_Position;                    \n" \
			"attribute vec2 a_TexCoord;                    \n" \
			"                                              \n" \
			"uniform mat4 u_Projection;                    \n" \
			"                                              \n" \
			"varying vec2 v_TexCoord;                      \n" \
			"                                              \n" \
			"void main()                                   \n" \
			"{                                             \n" \
			"  vec3 pos = a_Position + vec3(0, 0, -5);     \n" \
			"  gl_Position = u_Projection * vec4(pos, 1);  \n" \
			"  v_TexCoord = a_TexCoord;                    \n" \
			"}                                             \n" \
			"                                              \n" \
			"#endif                                        \n" \
			"#ifdef FRAGMENT                               \n" \
			"                                              \n" \
			"varying vec2 v_TexCoord;                      \n" \
			"                                              \n" \
			"void main()                                   \n" \
			"{                                             \n" \
			"  gl_FragColor = vec4(v_TexCoord, 0, 1);      \n" \
			"}                                             \n" \
			"                                              \n" \
			"#endif                                        \n";

		const char* obj =
			"v -1 1 0           \n" \
			"v -1 -1 0          \n" \
			"v 1 -1 0           \n" \
			"v 1 1 0            \n" \
			"                   \n" \
			"vt 0 1             \n" \
			"vt 0 0             \n" \
			"vt 1 0             \n" \
			"vt 1 1             \n" \
			"                   \n" \
			"f 1/1 2/2 3/3 4/4  \n" \
			"                   \n";


		//TODO: ABSTRACT INTO SCREEN CLASS!!!!!
		//LEAVE UNTIL IMPLEMENT REND THO
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			throw std::exception();
		}

		window = SDL_CreateWindow("Lab 4 - Architecture",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			windowWidth, windowHeight, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

		if (!SDL_GL_CreateContext(window))
		{
			throw std::exception();
		}

		//REND


		//Initialise context
		context = rend::Context::initialize();

		//Initialise Shader
		shader = context->createShader();
		shader->parse(src);

		//Mesh init

		shape = context->createMesh();
		shape->parse(obj);


		std::cout << "End of constructor reached" << std::endl;
		bool quit = false;
		
	}
	MeshRenderer::~MeshRenderer()
	{
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
	void MeshRenderer::onInit()
	{
	}
	void MeshRenderer::onDisplay()
	{
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		shader->setUniform("u_Projection", glm::perspective(glm::radians(45.0F), 1.0f, 0.1f, 100.0f));
		shader->setMesh(shape);
		shader->render();


		SDL_GL_SwapWindow(window);
	}
	void MeshRenderer::onTick()
	{
	}
}