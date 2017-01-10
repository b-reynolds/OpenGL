#include "BreakoutBlock.h"

BreakoutBlock::BreakoutBlock(unsigned int id, Vector2f position)
{
	this->position = position;
	this->id = id;
	borderSize = 1;
	size.x = SIZE_X;
	size.y = SIZE_Y;
	hitPoints = 1;

	colour = Colour::BLACK;
	borderColour = Colour::WHITE;
}

bool BreakoutBlock::takeHit()
{
	return (hitPoints -= 1) > 0;
}

unsigned BreakoutBlock::getID() const
{
	return id;
}

BreakoutBlock::~BreakoutBlock()
{
}
