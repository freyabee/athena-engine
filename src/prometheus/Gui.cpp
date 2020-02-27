#include "Model.h"
#include "Core.h"
#include "Resources.h"
#include "Material.h"
#include <exception>
#include <fstream>
#include "Screen.h"
#include "Gui.h"

namespace prometheus
{
	/// Allows GUI elements to be displayed on the screen.
	///
	///
	Gui::Gui(std::shared_ptr<Core> core)
	{
		this->core = core;
	}

	Gui::~Gui()
	{

	}
	void Gui::OnInit()
	{
		try
		{
			shader = core.lock()->GetContext()->createShader();
			shader->ParseFromPath("resources/shaders/guiShader.txt");
			std::shared_ptr<rend::Buffer> buffer = core.lock()->GetContext()->createBuffer();

			buffer->add(glm::vec2(1, 1));
			buffer->add(glm::vec2(1, 0));
			buffer->add(glm::vec2(0, 0));

			buffer->add(glm::vec2(0, 0));
			buffer->add(glm::vec2(0, 1));
			buffer->add(glm::vec2(1, 1));

			mesh = core.lock()->GetContext()->createMesh();
			mesh->setBuffer("a_Position", buffer);
			mesh->setBuffer("a_TexCoord", buffer);
		}
		catch (std::exception &e)
		{
			std::cout << "Problem loading gui: " << e.what() << std::endl;
		}
		
	}
	std::shared_ptr<Core> Gui::GetCore()
	{
		return core.lock();
	}
	void Gui::Texture(glm::vec4 position, std::shared_ptr<rend::Texture> texture)
	{
		
		glm::ivec2 screenDimensions = GetCore()->GetScreen()->GetWindowDimensions();
		float sw = screenDimensions.x;
		float sh = screenDimensions.y;
		try
		{
			shader->setUniform("u_Projection", glm::ortho(0.f, sw, sh, 0.f));
		}
		catch (std::exception&e)
		{
			std::cout << "Problem setting projection uniform in GUI: " << e.what() << std::endl;
		}
		
		glm::mat4 model(1.f);
		model = glm::translate(model, glm::vec3(position.x, position.y, 0));
		model = glm::scale(model, glm::vec3(position.z, position.w, 1.f));
		try
		{
			shader->setUniform("u_Model", model);
			mesh->setTexture("u_Texture", texture);
			shader->setMesh(mesh);
			shader->setDepthTest(false);
			shader->setBackface(false);
			shader->render();
		}
		catch (std::exception &e)
		{
			std::cout << "Problem rending GUI: "<< e.what() << std::endl;
		}
		
	}

}