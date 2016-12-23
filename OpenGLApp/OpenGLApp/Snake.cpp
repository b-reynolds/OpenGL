#include "Snake.h"


void Snake::setDirection(const Direction& direction)
{
	switch (direction)
	{
	case UP:
		velocity = Vector3D(0.0f, 0.0f, -2.0f);
		break;
	case RIGHT:
		velocity = Vector3D(2.0f, 0.0f, 0.0f);
		break;
	case DOWN:
		velocity = Vector3D(0.0f, 0.0f, 2.0f);
		break;
	case LEFT:
		velocity = Vector3D(-2.0f, 0.0f, 0.0f);
		break;
	}
	this->direction = direction;
}

void Snake::update()
{
	snake.move(velocity);


	bool t = (lastPosition == snake.getPosition());
	if(t == false)
	{
		printf("B");
	}

	if (lastPosition != snake.getPosition())
	{
		previousPositions.push_back(snake.getPosition());
	}
	
	if(previousPositions.size() > tailLength)
	{
		previousPositions.erase(previousPositions.begin());
	}


	lastPosition = snake.getPosition();
}

void Snake::draw()
{
	Vector3D currentPosition = snake.getPosition();

	for(int i = 0; i < previousPositions.size(); ++i)
	{
		snake.setPosition(previousPositions[i]);
		snake.draw();
	}

	snake.setPosition(currentPosition);
	snake.draw();

}

Snake::Snake()
{
	tailLength = 5;
	texture = Texture2D("Textures/grass.bmp");
	snake = Cube(Vector3D(0.0f, -13.0f, 0.0f), Vector3D(SIZE, SIZE, SIZE), texture);
}

Snake::~Snake()
{
}
