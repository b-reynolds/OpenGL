#pragma once
#include "RectangleShape.h"

class BreakoutBlock : public RectangleShape
{

private:

	unsigned int hitPoints;
	unsigned int id;

public:

	static const unsigned int SIZE_X = 75;
	static const unsigned int SIZE_Y = 20;

	BreakoutBlock(unsigned int id, Vector2f position);

	bool takeHit();

	unsigned int getID() const;

	~BreakoutBlock();

};

