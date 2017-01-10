#include "RenderText.h"

RenderText::RenderText()
{
	text = "";
	colour = Colour::WHITE;
	position = Vector2f(0, 0);
}

RenderText::RenderText(Vector2f position, std::string text)
{
	this->position = position;
	this->text = text;
}

void RenderText::draw() const
{
	glRasterPos2i(position.x, position.y);
	Colour::setColour3f(colour);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char *)text.c_str());
}

void RenderText::setText(std::string text)
{	
	this->text = text;
}

void RenderText::setColour(Colour colour)
{
	this->colour = colour;
}

void RenderText::setPosition(Vector2f position)
{
	this->position = position;
}

RenderText::~RenderText()
{
}
