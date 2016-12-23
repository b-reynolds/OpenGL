#include "Random.h"
#include <random>

int Random::getRandomInt(const int& min, const int& max)
{
	std::uniform_int_distribution<int> ud(min, max);
	std::random_device rd;
	return ud(rd);
}
