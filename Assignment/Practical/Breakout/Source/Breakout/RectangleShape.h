#pragma once
#include "Shape.h"

class RectangleShape : public Shape
{

protected:

	Vector2f size;

public:

	void draw();

	void setSize(Vector2f size);
	Vector2f getSize() const;

	FloatRect getRect() const;
	

	RectangleShape();
	~RectangleShape();

};

