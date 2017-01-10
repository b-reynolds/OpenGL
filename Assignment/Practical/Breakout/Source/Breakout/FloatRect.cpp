#include "FloatRect.h"

FloatRect::FloatRect(float left, float top, float width, float height)
{
	this->left = left;
	this->top = top;
	this->width = width;
	this->height = height;
}

FloatRect::FloatRect()
{
	this->left = 0.0f;
	this->top = 0.0f;
	this->width = 0.0f;
	this->height = 0.0f;
}

FloatRect::~FloatRect()
{
}

bool FloatRect::intersects(FloatRect rect) const
{
	return left < rect.left + rect.width && left + width > rect.left && top < rect.top + rect.height && top + height > rect.top;
}