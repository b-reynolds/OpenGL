#include "Snake.h"
#include <random>
#include "Random.h"

void Snake::setDirection(const Direction& direction)
{
	// Set the snake's velocity
	if(direction == UP && this->direction != DOWN)
	{
		velocity = Vector3D(0.0f, 0.0f, -(SIZE * 2.0f));
		this->direction = direction;
	}
	else if(direction == RIGHT && this->direction != LEFT)
	{
		velocity = Vector3D((SIZE * 2.0f), 0.0f, 0.0f);
		this->direction = direction;
	}
	else if(direction == DOWN && this->direction != UP)
	{
		velocity = Vector3D(0.0f, 0.0f, (SIZE * 2.0f));
		this->direction = direction;
	}
	else if(direction == LEFT && this->direction != RIGHT)
	{
		velocity = Vector3D(-(SIZE * 2.0f), 0.0f, 0.0f);
		this->direction = direction;
	}
}

int Snake::getScore() const
{
	return tailLength - DEFAULT_TAIL_LENGTH;
}

void Snake::update()
{
	// If the snake moved more recently than SPEED then return
	elapsed = glutGet(GLUT_ELAPSED_TIME);
	if(elapsed - lastMove < SPEED)
	{
		return;
	}

	// Move the snake
	snake.move(velocity);
	lastMove = elapsed;

	Vector3D currentPosition = snake.getPosition();

	// If the snake has gone out of bounds reset
	if(currentPosition.x < MIN_X || currentPosition.x > MAX_X || currentPosition.z < MIN_Z || currentPosition.z > MAX_Z)
	{
		reset();
		return;
	}

	// If the snake head intersects with a tail piece reset
	for(auto & position : tailPositions)
	{
		if(currentPosition == position)
		{
			reset();
			return;
		}
	}

	// If the snake head intersects with the food piece increase the tail length and reset the food position
	if(currentPosition == food.getPosition())
	{
		tailLength++;
		resetFood();
	}

	// Add the current position to the tail
	tailPositions.push_back(currentPosition);

	// If the tail position vector size exceeds the tail length then trim it
	if(tailPositions.size() > tailLength)
	{
		tailPositions.erase(tailPositions.begin());
	}
}

void Snake::draw()
{
	// Store the snake's current position
	Vector3D currentPosition = snake.getPosition();

	// Move the snake to each tail position and draw it to simulate a tail
	for(int i = 0; i < tailPositions.size(); ++i)
	{
		snake.setPosition(tailPositions[i]);
		snake.draw();
	}

	// Reposition the snake to its current position and draw it
	snake.setPosition(currentPosition);
	snake.draw();

	// Draw the food piece
	food.draw();
}

Snake::Snake()
{
	// Load in the snake texture and initialize the cube
	txtrSnake = Texture2D("Textures/snake.bmp");
	snake = Cube(Vector3D(0.0f, -13.0f, 0.0f), Vector3D(SIZE, SIZE, SIZE), txtrSnake);

	// Load in the food texure and initialize the cube
	txtrFood = Texture2D("Textures/food.bmp");
	food = Cube(Vector3D(0.0f, -13.0f, 0.0f), Vector3D(SIZE, SIZE, SIZE), txtrFood);

	// Reset the game
	reset();
}

void Snake::reset()
{
	// Set the snake's position to a random position (even numbers only) within the game boards bounds 
	int startX = 0;
	do { startX = Random::getRandomInt(MIN_X, MAX_X); } while (abs(startX) % 2 != 0);
	int startZ = 0;
	do { startZ = Random::getRandomInt(MIN_Z, MAX_Z); } while (abs(startZ) % 2 != 0);
	snake.setPosition(Vector3D(startX, POS_Y, startZ));

	// Randomly set the snake's direction
	int startDirection = Random::getRandomInt(1, 4);
	switch(startDirection)
	{
		case 1:
			setDirection(UP);
			break;
		case 2:
			setDirection(RIGHT);
			break;
		case 3:
			setDirection(DOWN);
			break;
		case 4:
			setDirection(LEFT);
			break;
		default:
			break;
	}


	// Reset the tail length and clear the tail positions vector
	tailLength = DEFAULT_TAIL_LENGTH;
	tailPositions.clear();
	
	// Reset the food piece's position
	resetFood();
}

void Snake::resetFood()
{	
	// Set the food piece's position to a random position (even numbers only) within the game boards bounds 
	int foodX = 0;
	int foodZ = 0;
	bool legalPosition = false;
	do
	{
		do { foodX = Random::getRandomInt(MIN_X, MAX_X); } while (abs(foodX) % 2 != 0);
		do { foodZ = Random::getRandomInt(MIN_Z, MAX_Z); } while (abs(foodZ) % 2 != 0);

		legalPosition = true;
		Vector3D snakePosition = snake.getPosition();
		for (auto & point : tailPositions)
		{
			// If the random position intersects a snake piece then retry
			if (point.x == foodX && point.z == foodZ || point.x == snakePosition.x && point.z == snakePosition.z)
			{
				legalPosition = false;
				break;
			}
		}
	} while (legalPosition == false);
	food.setPosition(Vector3D(foodX, POS_Y, foodZ));
}
