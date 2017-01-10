#pragma once
#include <glut.h>
#include "Keyboard.h"
#include "Vector2f.h"
#include "RectangleShape.h"

class Paddle : public RectangleShape
{

private:

	Vector2f velocity;

public:

	void setVelocity(Vector2f velocity);
	Vector2f getVelocity();

	void move(float deltaTime);

	Paddle();
	~Paddle();

};

