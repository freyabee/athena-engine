#include "Texture.h"
#include "Context.h"
#include "Exception.h"

namespace rend
{

Texture::~Texture()
{
  GLuint delId = id;
  glDeleteTextures(1, &delId);
  pollForError();
}

GLuint Texture::getTexId()
{
  return getId();
}

GLuint Texture::getId()
{
	/*
	if (skybox && dirty)
	{
		/*
		glBindTexture(GL_TEXTURE_CUBE_MAP, id);
		pollForError();


		for (GLuint i = 0; i < textures_faces.size(); i++)
		{
			unsigned char *data = stbi_load(faces[i].c_str(), &width, &height, &nrChannels, 0);
			glTexImage2D(
				GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
				0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data
			);
		}

		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

		return id;
		
	}
	*/
    if(dirty)
    {
		glBindTexture(GL_TEXTURE_2D, id);
		pollForError();

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, size.x, size.y, 0, GL_RGBA, GL_FLOAT, &data.at(0));
		pollForError();

		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		pollForError();
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		pollForError();

		glGenerateMipmap(GL_TEXTURE_2D);
		pollForError();

		glBindTexture(GL_TEXTURE_2D, 0);
		pollForError();

		dirty = false;
	}

    return id;
}

ivec2 Texture::getSize() const
{
  return size;
}

int Texture::getWidth() const
{
  return size.x;
}

int Texture::getHeight() const
{
  return size.y;
}

void Texture::setSize(unsigned int width, unsigned int height)
{
  dirty = true;
  size = ivec2(width, height);
  data.resize(width * height);
}

void Texture::setPixel(unsigned int x, unsigned int y, vec3 rgb)
{
  setPixel(x, y, vec4(rgb, 1));
  bpp = 3;
}

void Texture::setPixel(unsigned int x, unsigned int y, vec4 rgba)
{
  dirty = true;
  bpp = 4;
  data.at(size.x * (size.y - 1 - y) + x) = rgba;
}

vec4 Texture::getPixel(unsigned int x, unsigned int y) const
{
  return data.at(size.x * y + x);
}

}
