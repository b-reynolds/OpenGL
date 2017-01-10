#include "BreakoutLevel.h"

BreakoutLevel::BreakoutLevel(int levelGrid[11][11])
{
	for (int y = 0; y < SIZE_Y; ++y)
	{
		for (int x = 0; x < SIZE_X; ++x)
		{
			if (levelGrid[y][x] > 0)
			{
				originalState.push_back(BreakoutBlock(levelGrid[y][x], Vector2f(48 + x * BreakoutBlock::SIZE_X, 691 - BreakoutBlock::SIZE_Y - y * BreakoutBlock::SIZE_Y - 48)));
			}
		}
	}
	reset();
}

std::vector<BreakoutBlock>* BreakoutLevel::getBlocks()
{
	return &currentState;
}

void BreakoutLevel::removeBlock(int blockIndex)
{
	currentState.erase(currentState.begin() + blockIndex);
}

void BreakoutLevel::hitBlock(int blockIndex)
{
	if(!currentState[blockIndex].takeHit())
	{
		removeBlock(blockIndex);
	}
}

void BreakoutLevel::reset()
{
	currentState.clear();
	for(auto block : originalState)
	{
		currentState.push_back(block);
	}
}

bool BreakoutLevel::isCompleted() const
{
	return currentState.size() == 0;
}

void BreakoutLevel::draw()
{
	for (auto& block : currentState)
	{
		block.draw();
	}
}

BreakoutLevel::~BreakoutLevel()
{
}
