#include "Shape.h"

Shape::Shape()
{
	this->borderSize = 0.0f;
	this->position = Vector2f(0.0f, 0.0f);
}

void Shape::setPosition(Vector2f position)
{
	this->position = position;
}

Vector2f Shape::getPosition()
{
	return position;
}

void Shape::setColour(Colour colour)
{
	this->colour = colour;
}

void Shape::setBorderColour(Colour colour)
{
	this->borderColour = colour;
}

void Shape::setBorderSize(float size)
{
	this->borderSize = size;
}

float Shape::getBorderSize()
{
	return borderSize;
}

Shape::~Shape()
{
}
