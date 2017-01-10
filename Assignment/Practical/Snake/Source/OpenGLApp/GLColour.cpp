#include "GLColour.h"



GLColour::GLColour(const GLfloat &r, const GLfloat &g, const GLfloat &b, const GLfloat &a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

GLColour::GLColour(const GLfloat &r, const GLfloat &g, const GLfloat &b)
{
	this->r = r;
	this->g = g;
	this->b = b;
	a = 0.0f;
}

GLColour::GLColour()
{
	r = 0.0f;
	g = 0.0f;
	b = 0.0f;
	a = 0.0f;
}

void GLColour::setClearColour(const GLColour& colour)
{
	glClearColor(colour.r, colour.g, colour.b, colour.a);
}

void GLColour::setColour3f(const GLColour& colour)
{
	glColor3f(colour.r, colour.g, colour.b);
}

void GLColour::setColour4f(const GLColour& colour)
{
	glColor4f(colour.r, colour.g, colour.b, colour.a);
}
