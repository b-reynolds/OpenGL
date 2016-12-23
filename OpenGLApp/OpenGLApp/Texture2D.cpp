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
	// Load the texture
	texture = ilutGLLoadImage(filePath);


	initialized = true;
}
