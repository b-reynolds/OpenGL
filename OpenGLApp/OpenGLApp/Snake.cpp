#include "Snake.h"
#include <random>
#include "Random.h"

void Snake::setDirection(const Direction& direction)
{
	if(direction == UP && this->direction != DOWN)
	{
		velocity = Vector3D(0.0f, 0.0f, -2.0f);
		this->direction = direction;
	}
	else if(direction == RIGHT && this->direction != LEFT)
	{
		velocity = Vector3D(2.0f, 0.0f, 0.0f);
		this->direction = direction;
	}
	else if(direction == DOWN && this->direction != UP)
	{
		velocity = Vector3D(0.0f, 0.0f, 2.0f);
		this->direction = direction;
	}
	else if(direction == LEFT && this->direction != RIGHT)
	{
		velocity = Vector3D(-2.0f, 0.0f, 0.0f);
		this->direction = direction;
	}
}

void Snake::update()
{
	elapsed = glutGet(GLUT_ELAPSED_TIME);
	if(elapsed - lastMove < SPEED)
	{
		return;
	}

	snake.move(velocity);
	lastMove = elapsed;

	Vector3D currentPosition = snake.getPosition();

	if(currentPosition.x < MIN_X || currentPosition.x > MAX_X || currentPosition.z < MIN_Z || currentPosition.z > MAX_Z)
	{
		reset();
		return;
	}

	for(auto & position : tailPositions)
	{
		if(currentPosition == position)
		{
			reset();
			return;
		}
	}

	if(currentPosition == food.getPosition())
	{
		tailLength++;
		int foodX = 0;
		do { foodX = Random::getRandomInt(MIN_X, MAX_X); } while (abs(foodX) % 2 != 0);
		int foodZ = 0;
		do { foodZ = Random::getRandomInt(MIN_Z, MAX_Z); } while (abs(foodZ) % 2 != 0);
		food.setPosition(Vector3D(foodX, POS_Y, foodZ));
	}

	tailPositions.push_back(currentPosition);
	if(tailPositions.size() > tailLength)
	{
		tailPositions.erase(tailPositions.begin());
	}
}

void Snake::draw()
{
	Vector3D currentPosition = snake.getPosition();

	for(int i = 0; i < tailPositions.size(); ++i)
	{
		snake.setPosition(tailPositions[i]);
		snake.draw();
	}

	snake.setPosition(currentPosition);
	snake.draw();

	food.draw();

}

Snake::Snake()
{
	txtrSnake = Texture2D("Textures/snake.bmp");
	snake = Cube(Vector3D(0.0f, -13.0f, 0.0f), Vector3D(SIZE, SIZE, SIZE), txtrSnake);

	txtrFood = Texture2D("Textures/food.bmp");
	food = Cube(Vector3D(0.0f, -13.0f, 0.0f), Vector3D(SIZE, SIZE, SIZE), txtrFood);

	reset();
}

void Snake::reset()
{

	int startX = 0;
	do { startX = Random::getRandomInt(MIN_X, MAX_X); } while (abs(startX) % 2 != 0);
	int startZ = 0;
	do { startZ = Random::getRandomInt(MIN_Z, MAX_Z); } while (abs(startZ) % 2 != 0);
	snake.setPosition(Vector3D(startX, POS_Y, startZ));

	int foodX = 0;
	do { foodX = Random::getRandomInt(MIN_X, MAX_X); } while (abs(foodX) % 2 != 0);
	int foodZ = 0;
	do { foodZ = Random::getRandomInt(MIN_Z, MAX_Z); } while (abs(foodZ) % 2 != 0);
	food.setPosition(Vector3D(foodX, POS_Y, foodZ));

	tailLength = 2;
	tailPositions.clear();
}
