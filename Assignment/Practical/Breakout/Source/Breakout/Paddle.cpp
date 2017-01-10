#include "Paddle.h"

void Paddle::setVelocity(Vector2f velocity)
{
	this->velocity = velocity;
}

Vector2f Paddle::getVelocity()
{
	return velocity;
}

void Paddle::move(float deltaTime)
{
	position = position + velocity * deltaTime;
}

Paddle::Paddle()
{
	colour = Colour::WHITE;
	borderColour = Colour(0.8f, 0.8f, 0.8f);
	borderSize = 2;
	size = Vector2f(80, 20);
}

Paddle::~Paddle()
{
}
