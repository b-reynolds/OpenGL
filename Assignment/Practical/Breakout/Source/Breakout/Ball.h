#pragma once
#include <math.h>
#include "Shape.h"

class Ball : public Shape
{

private:

	Vector2f velocity;
	float radius;

public:

	void draw() const;

	void move(float deltaTime);

	void setSize(float radius);
	void setVelocity(Vector2f velocity);

	FloatRect getRect() const;
	Vector2f getVelocity() const;
	float getSize() const;
	
	Ball();
	~Ball();

};

