#include "Cubemap.h"
#include "stb_image.h"
#include <vector>
#include "Core.h"
#include <iostream>
namespace prometheus
{
	Cubemap::Cubemap()
	{
	}
	Cubemap::~Cubemap()
	{

	}
	void Cubemap::LoadCubemapTextures(std::vector<std::string> _paths)
	{
		/*
		//Generate texture and bind it to proper cubemap
		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
		int width, height, nrChannels;
		unsigned char *data;
		for (int i = 0; i < _paths.size(); i++)
		{
			data = stbi_load(_paths[i].c_str(), &width, &height, &nrChannels, 0);
			glTexImage2D(
				GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
				0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data
			);
		}
		stbi_image_free(data);

		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

		glDepthMask(GL_FALSE);
		//skyboxShader.use();
		// ... set view and projection matrix
		//glBindVertexArray(skyboxVAO);
		//glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glDepthMask(GL_TRUE);
		*/
		// ... draw rest of the scene
	}

}