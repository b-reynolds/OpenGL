#include "RectangleShape.h"

RectangleShape::RectangleShape()
{
}

RectangleShape::~RectangleShape()
{
}

void RectangleShape::draw()
{
	Colour::setColour3f(borderSize > 0 ? borderColour : colour);
	glBegin(GL_QUADS);
		glVertex2f(position.x, position.y);
		glVertex2f(position.x, position.y + size.y);
		glVertex2f(position.x + size.x, position.y + size.y);
		glVertex2f(position.x + size.x, position.y);
	glEnd();

	if (borderSize > 0)
	{
		Colour::setColour3f(colour);
		glBegin(GL_QUADS);
			glVertex2f(position.x + borderSize, position.y + borderSize);
			glVertex2f(position.x + borderSize, position.y + size.y - borderSize);
			glVertex2f(position.x + size.x - borderSize, position.y + size.y - borderSize);
			glVertex2f(position.x + size.x - borderSize, position.y + borderSize);
		glEnd();
	}
}

void RectangleShape::setSize(Vector2f size)
{
	this->size = size;
}

Vector2f RectangleShape::getSize() const
{
	return size;
}

FloatRect RectangleShape::getRect() const
{
	return FloatRect(position.x, position.y + size.y, size.x, size.y);
}
