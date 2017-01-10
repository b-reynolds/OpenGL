#include "Random.h"
#include <random>
#include <ctime>

int Random::getRandomInt(const int& min, const int& max)
{
	std::uniform_int_distribution<int> ud(min, max);
	std::random_device rd;
	return ud(rd);
}

float Random::nextDouble()
{
	static std::mt19937 rng_engine((unsigned)time(nullptr));
	static std::uniform_real_distribution<float> distribution;
	return distribution(rng_engine);
}