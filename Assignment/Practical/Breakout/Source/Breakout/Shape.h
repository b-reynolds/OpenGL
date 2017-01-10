#pragma once
#include "Vector2f.h"
#include "FloatRect.h"
#include "Colour.h"

class Shape
{

protected:

	Colour colour;
	Colour borderColour;
	Vector2f position;
	float borderSize;

public:
	
	Shape();

	virtual void setPosition(Vector2f position);
	virtual Vector2f getPosition();
	
	virtual void setBorderSize(float size);
	virtual float getBorderSize();

	virtual void setColour(Colour colour);
	virtual void setBorderColour(Colour colour);

	virtual ~Shape();

};

