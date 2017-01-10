#pragma once
class Vector2f
{

public:

	float x;
	float y;

	Vector2f();
	Vector2f(float x, float y);

	Vector2f operator+(Vector2f v2) const;
	Vector2f operator+=(Vector2f v2) const;
	Vector2f operator-(Vector2f v2) const;
	Vector2f operator-() const;
	Vector2f operator*(Vector2f v2) const;
	Vector2f operator*(float scalar) const;

	~Vector2f();

};

