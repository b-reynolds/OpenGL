#pragma once
#include "Cube.h"
#include <vector>

class Snake
{ 

public:

	enum Direction { UP, RIGHT, DOWN, LEFT };
	void setDirection(const Direction &direction);

	void update();
	void draw();

	Snake();

private:

	const GLfloat SIZE = 1.0f;
	const int SPEED = 50;

	const float MIN_X = -30;
	const float MAX_X = 0;
	const float MIN_Z = -30;
	const float MAX_Z = 0;
	const float POS_Y = -13;

	int lastMove;
	int speed;
	int elapsed;

	Vector3D velocity;
	Direction direction;
	int tailLength;

	std::vector<Vector3D> tailPositions;

	Texture2D txtrSnake;
	Texture2D txtrFood;

	Cube snake;
	Cube food;

	void reset();

};

