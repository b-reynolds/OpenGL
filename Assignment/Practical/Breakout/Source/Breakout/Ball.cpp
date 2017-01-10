#include "Ball.h"

void Ball::draw() const
{
	float theta = 2.0f * 3.1415926f / float(12.0f);
	float c = cosf(theta);
	float s = sinf(theta);
	float t;
	float x = radius;
	float y = 0.0f;

	glColor3f(colour.r, colour.g, colour.b);
	glBegin(GL_POLYGON);
		for (int i = 0; i < 12; i++)
		{
			glVertex2f(x + position.x, y + position.y);
			t = x;
			x = c * x - s * y;
			y = s * t + c * y;
		}
	glEnd();
}

void Ball::move(float deltaTime)
{
	position = position + velocity * deltaTime;
}

void Ball::setSize(float radius)
{
	this->radius = radius;
}

void Ball::setVelocity(Vector2f velocity)
{
	this->velocity = velocity;
}

FloatRect Ball::getRect() const
{
	return FloatRect(position.x, position.y + radius, radius * 2.0f, radius * 2.0f);
}

Vector2f Ball::getVelocity() const
{
	return velocity;
}

float Ball::getSize() const
{
	return radius;
}

Ball::Ball()
{

	colour = Colour(1.0f, 1.0f, 1.0f);
	radius = 8;
}

Ball::~Ball()
{
}
