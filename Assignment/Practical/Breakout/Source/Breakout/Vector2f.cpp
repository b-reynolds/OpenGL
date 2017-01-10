#include "Vector2f.h"

Vector2f::Vector2f()
{
	x = 0.0f;
	y = 0.0f;
}

Vector2f::Vector2f(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2f Vector2f::operator+(Vector2f v2) const
{
	return Vector2f(x + v2.x, y + v2.y);
}

Vector2f Vector2f::operator+=(Vector2f v2) const
{
	return Vector2f(x + v2.x, y + v2.y);
}

Vector2f Vector2f::operator-(Vector2f v2) const
{
	return Vector2f(x - v2.x, y - v2.y);
}

Vector2f Vector2f::operator-() const
{
	return Vector2f(-x, -y);
}

Vector2f Vector2f::operator*(Vector2f v2) const
{
	return Vector2f(x * v2.x, y * v2.y);
}

Vector2f Vector2f::operator*(float scalar) const
{
	return Vector2f(x * scalar, y * scalar);
}

Vector2f::~Vector2f()
{
}
