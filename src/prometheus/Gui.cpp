#include "Model.h"
#include "Core.h"
#include "Resources.h"
#include "Material.h"
#include <exception>
#include "rend/Texture.h"
#include <fstream>
#include "Gui.h"
#include "Screen.h"
namespace prometheus
{
	/// Allows GUI elements to be displayed on the screen.
	///
	///
	Gui::Gui()
	{

	}
	Gui::~Gui()
	{

	}
	void Gui::OnInit()
	{
		std::string shaderData;
		std::ifstream file(" ../resources/shaders/guiShader.txt");
		if(!file.is_open())
		{
			std::cout << "Problem opening shader file." << std::endl;
		}
		while (!file.eof())
		{
			std::string line;
			std::getline(file, line);
			shaderData += line + "\n";
		}
		file.close();
		
		shader = core.lock()->GetContext()->createShader();
		shader->parse(shaderData);

		std::shared_ptr<rend::Buffer> buffer = core.lock()->GetContext()->createBuffer();
		buffer->add(glm::vec3(-1.0f, 0.f, 1.f));
		buffer->add(glm::vec3(1.0f, 0.f, 1.f));
		buffer->add(glm::vec3(-1.0f, 0.f, -1.f));
		buffer->add(glm::vec3(1.0f, 0.f, -1.f));
		
		mesh = core.lock()->GetContext()->createBuffer();
		mesh->setBuffer("a_Position", buffer);
		mesh->setBuffer("a_TexCoord", buffer);


	}
	std::shared_ptr<Core> Gui::GetCore()
	{
		return core.lock();
	}
	void Gui::Texture(glm::vec4 position, std::shared_ptr<rend::Texture> texture)
	{
		sw = GetCore()->GetScreen()->
		shader->setUniform("u_Projection", rend::ortho(0, sw, sh, 0));
	}
}