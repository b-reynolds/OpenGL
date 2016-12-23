#pragma once
#include "glut.h"

class Texture2D
{

public:

	explicit Texture2D(char* filePath);
	Texture2D();

	GLuint& getTexture();
	bool isLoaded() const;

private:

	GLuint texture;
	bool initialized;

	void initialize(char* filePath);

};

