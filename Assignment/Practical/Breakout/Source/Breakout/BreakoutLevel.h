#pragma once
#include <vector>
#include "BreakoutBlock.h"

class BreakoutLevel
{

private:

	static const int SIZE_X = 11;
	static const int SIZE_Y = 11;

	std::vector<BreakoutBlock> originalState;
	std::vector<BreakoutBlock> currentState;

	void removeBlock(int blockIndex);

public:

	explicit BreakoutLevel(int levelGrid[11][11]);

	std::vector<BreakoutBlock>* getBlocks();
	bool isCompleted() const;

	void hitBlock(int blockIndex);
	void reset();
	void draw();

	~BreakoutLevel();

};

