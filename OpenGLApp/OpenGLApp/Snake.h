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
	~Snake();

private:

	const GLfloat SIZE = 1.0f;

	Vector3D velocity;
	Vector3D lastPosition;
	Direction direction;
	int tailLength;

	std::vector<Vector3D> previousPositions;

	Texture2D texture;
	Cube snake;

};

