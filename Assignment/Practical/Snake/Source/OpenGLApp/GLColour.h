#pragma once
#include <glut.h>

class GLColour
{

public:

	GLfloat r;
	GLfloat g;
	GLfloat b;
	GLfloat a;

	GLColour(const GLfloat &r, const GLfloat &g, const GLfloat &b, const GLfloat &a);
	GLColour(const GLfloat &r, const GLfloat &g, const GLfloat &b);
	GLColour();

	static void setClearColour(const GLColour &colour);
	static void setColour3f(const GLColour &colour);
	static void setColour4f(const GLColour &colour);

};

