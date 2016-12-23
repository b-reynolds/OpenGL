#include "Texture2D.h"
#include <IL/ilut.h>

Texture2D::Texture2D(char* filePath)
{
	initialized = false;
	initialize(filePath);
}

Texture2D::Texture2D()
{
	initialized = false;
}

GLuint& Texture2D::getTexture()
{
	return texture;
}

bool Texture2D::isLoaded() const
{
	return initialized;
}

void Texture2D::initialize(char* filePath)
{

	// Define wrapping behaviour
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// Define filtering behaviour
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);

	texture = ilutGLLoadImage("box.bmp");

	// Define how texture is sent down the rendering pipeline
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	initialized = true;
}
