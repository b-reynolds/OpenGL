#pragma once
#include "RectangleShape.h"

class Border
{

public:

	RectangleShape top;
	RectangleShape bottom;
	RectangleShape left;
	RectangleShape right;

	void draw();

	void setColour(Colour colour);

	Border();
	~Border();

};

