#pragma once
class FloatRect
{

public:

	float left;
	float top;
	float width;
	float height;

	FloatRect(float left, float top, float width, float height);
	FloatRect();

	~FloatRect();

	bool intersects(FloatRect rect) const;

};

