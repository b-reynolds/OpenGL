#include "Border.h"

void Border::draw()
{
	top.draw();
	bottom.draw();
	left.draw();
	right.draw();
}

void Border::setColour(Colour colour)
{
	top.setColour(colour);
	bottom.setColour(colour);
	left.setColour(colour);
	right.setColour(colour);
}

Border::Border()
{
}

Border::~Border()
{
}
