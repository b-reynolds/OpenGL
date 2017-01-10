#include "Breakout.h"

Breakout* Breakout::pInstance = nullptr;

void Breakout::update(float deltaTime, int winX, int winY)
{
	this->deltaTime = deltaTime;
	this->winX = winX;
	this->winY = winY;

	if(Mouse::getInstance()->isButtonClicked(0))
	{
		Mouse::hideCursor();
	}
	else if(Mouse::getInstance()->isButtonClicked(2))
	{
		Mouse::showCursor();
	}

	handleInput();

	if(!paused)
	{
		updateBall();
		updatePaddle();
		updateWindowTitle();
		updateText();
	}

}

void Breakout::draw()
{
	draw3D();
	draw2D();
	glutSwapBuffers();
}

void Breakout::setWindowBounds(float left, float right, float top, float bottom)
{
	this->windowBounds.left = left;
	this->windowBounds.right = right;
	this->windowBounds.top = top;
	this->windowBounds.bottom = bottom;
}

void Breakout::setPaused(bool state)
{
	this->paused = state;
}

void Breakout::setColourScheme(unsigned colourScheme)
{
	this->currentColourScheme = colourScheme;
	std::vector<BreakoutBlock>* pBlocks = levels[currentLevel].getBlocks();
	BreakoutBlock* pCurrentBlock = nullptr;;
	for(unsigned int i = 0; i < pBlocks->size(); ++i) // REFACTOR THIS (CURRENTLY CHANGES BG FOR EACH BLOCK ETC)
	{
		pCurrentBlock = &pBlocks->at(i);
		switch(colourScheme)
		{

			case 0: // Default Colour Scheme

				ball.setColour(Colour::DEFAULT_BALL);
				paddle.setColour(Colour::DEFAULT_PADDLE);
				paddle.setBorderColour(Colour::BLACK);
				txtLives.setColour(Colour::DEFAULT_TEXT);
				txtScore.setColour(Colour::DEFAULT_TEXT);
				windowBorder.setColour(Colour::DEFAULT_BORDER);
				Colour::setClearColour(Colour::DEFAULT_BACKGROUND);

				switch(pCurrentBlock->getID())
				{
					case 1:
						pCurrentBlock->setColour(Colour::DEFAULT_BLOCK_ONE);
						pCurrentBlock->setBorderColour(Colour::BLACK);
						break;
					case 2:
						pCurrentBlock->setColour(Colour::DEFAULT_BLOCK_TWO);
						pCurrentBlock->setBorderColour(Colour::BLACK);
						break;
					case 3:
						pCurrentBlock->setColour(Colour::DEFAULT_BLOCK_THREE);
						pCurrentBlock->setBorderColour(Colour::BLACK);
						break;
					case 4:
						pCurrentBlock->setColour(Colour::DEFAULT_BLOCK_FOUR);
						pCurrentBlock->setBorderColour(Colour::BLACK);
						break;
					case 5:
						pCurrentBlock->setColour(Colour::DEFAULT_BLOCK_FIVE);
						pCurrentBlock->setBorderColour(Colour::BLACK);
						break;
					case 6:
						pCurrentBlock->setColour(Colour::DEFAULT_BLOCK_SIX);
						pCurrentBlock->setBorderColour(Colour::BLACK);
						break;
				}

			break;

			case 1: // Pastel Colour Scheme

				ball.setColour(Colour::PASTEL_BALL);
				paddle.setColour(Colour::PASTEL_PADDLE);
				paddle.setBorderColour(Colour::BLACK);
				txtLives.setColour(Colour::PASTEL_TEXT);
				txtScore.setColour(Colour::PASTEL_TEXT);
				windowBorder.setColour(Colour::PASTEL_BORDER);
				Colour::setClearColour(Colour::PASTEL_BACKGROUND);

				switch (pCurrentBlock->getID())
				{
					case 1:
						pCurrentBlock->setColour(Colour::PASTEL_BLOCK_ONE);
						pCurrentBlock->setBorderColour(Colour::BLACK);
						break;
					case 2:
						pCurrentBlock->setColour(Colour::PASTEL_BLOCK_TWO);
						pCurrentBlock->setBorderColour(Colour::BLACK);
						break;
					case 3:
						pCurrentBlock->setColour(Colour::PASTEL_BLOCK_THREE);
						pCurrentBlock->setBorderColour(Colour::BLACK);
						break;
					case 4:
						pCurrentBlock->setColour(Colour::PASTEL_BLOCK_FOUR);
						pCurrentBlock->setBorderColour(Colour::BLACK);
						break;
					case 5:
						pCurrentBlock->setColour(Colour::PASTEL_BLOCK_FIVE);
						pCurrentBlock->setBorderColour(Colour::BLACK);
						break;
					case 6:
						pCurrentBlock->setColour(Colour::PASTEL_BLOCK_SIX);
						pCurrentBlock->setBorderColour(Colour::BLACK);
						break;
				}

			break;

			case 2: // Grayscale Colour Scheme

				ball.setColour(Colour::GRAYSCALE_BALL);
				paddle.setColour(Colour::GRAYSCALE_PADDLE);
				paddle.setBorderColour(Colour::BLACK);
				txtLives.setColour(Colour::GRAYSCALE_TEXT);
				txtScore.setColour(Colour::GRAYSCALE_TEXT);
				windowBorder.setColour(Colour::GRAYSCALE_BORDER);
				Colour::setClearColour(Colour::GRAYSCALE_BACKGROUND);

				switch (pCurrentBlock->getID())
				{
					case 1:
						pCurrentBlock->setColour(Colour::GRAYSCALE_BLOCK_ONE);
						pCurrentBlock->setBorderColour(Colour::BLACK);
						break;
					case 2:
						pCurrentBlock->setColour(Colour::GRAYSCALE_BLOCK_TWO);
						pCurrentBlock->setBorderColour(Colour::BLACK);
						break;
					case 3:
						pCurrentBlock->setColour(Colour::GRAYSCALE_BLOCK_THREE);
						pCurrentBlock->setBorderColour(Colour::BLACK);
						break;
					case 4:
						pCurrentBlock->setColour(Colour::GRAYSCALE_BLOCK_FOUR);
						pCurrentBlock->setBorderColour(Colour::BLACK);
						break;
					case 5:
						pCurrentBlock->setColour(Colour::GRAYSCALE_BLOCK_FIVE);
						pCurrentBlock->setBorderColour(Colour::BLACK);
						break;
					case 6:
						pCurrentBlock->setColour(Colour::GRAYSCALE_BLOCK_SIX);
						pCurrentBlock->setBorderColour(Colour::BLACK);
						break;
				}

				break;

			case 3: // Gameboy Colour Scheme

				ball.setColour(Colour::GAMEBOY_BALL);
				paddle.setColour(Colour::GAMEBOY_PADDLE);
				paddle.setBorderColour(Colour::BLACK);
				txtLives.setColour(Colour::GAMEBOY_TEXT);
				txtScore.setColour(Colour::GAMEBOY_TEXT);
				windowBorder.setColour(Colour::GAMEBOY_BORDER);
				Colour::setClearColour(Colour::GAMEBOY_BACKGROUND);

				switch (pCurrentBlock->getID())
				{
					case 1:
						pCurrentBlock->setColour(Colour::GAMEBOY_BLOCK_ONE);
						pCurrentBlock->setBorderColour(Colour::BLACK);
						break;
					case 2:
						pCurrentBlock->setColour(Colour::GAMEBOY_BLOCK_TWO);
						pCurrentBlock->setBorderColour(Colour::BLACK);
						break;
					case 3:
						pCurrentBlock->setColour(Colour::GAMEBOY_BLOCK_THREE);
						pCurrentBlock->setBorderColour(Colour::BLACK);
						break;
					case 4:
						pCurrentBlock->setColour(Colour::GAMEBOY_BLOCK_FOUR);
						pCurrentBlock->setBorderColour(Colour::BLACK);
						break;
					case 5:
						pCurrentBlock->setColour(Colour::GAMEBOY_BLOCK_FIVE);
						pCurrentBlock->setBorderColour(Colour::BLACK);
						break;
					case 6:
						pCurrentBlock->setColour(Colour::GAMEBOY_BLOCK_SIX);
						pCurrentBlock->setBorderColour(Colour::BLACK);
						break;
				}

				break;

			case 4: // Terminal Colour Scheme

				ball.setColour(Colour::TERMINAL_BALL);
				paddle.setColour(Colour::BLACK);
				paddle.setBorderColour(Colour::TERMINAL_PADDLE);
				txtLives.setColour(Colour::TERMINAL_TEXT);
				txtScore.setColour(Colour::TERMINAL_TEXT);
				windowBorder.setColour(Colour::TERMINAL_BORDER);
				Colour::setClearColour(Colour::TERMINAL_BACKGROUND);

				switch (pCurrentBlock->getID())
				{
				case 1:
					pCurrentBlock->setColour(Colour::BLACK);
					pCurrentBlock->setBorderColour(Colour::TERMINAL_BLOCK_ONE);
					break;
				case 2:
					pCurrentBlock->setColour(Colour::BLACK);
					pCurrentBlock->setBorderColour(Colour::TERMINAL_BLOCK_TWO);
					break;
				case 3:
					pCurrentBlock->setColour(Colour::BLACK);
					pCurrentBlock->setBorderColour(Colour::TERMINAL_BLOCK_THREE);
					break;
				case 4:
					pCurrentBlock->setColour(Colour::BLACK);
					pCurrentBlock->setBorderColour(Colour::TERMINAL_BLOCK_FOUR);
					break;
				case 5:
					pCurrentBlock->setColour(Colour::BLACK);
					pCurrentBlock->setBorderColour(Colour::TERMINAL_BLOCK_FIVE);
					break;
				case 6:
					pCurrentBlock->setColour(Colour::BLACK);
					pCurrentBlock->setBorderColour(Colour::TERMINAL_BLOCK_SIX);
					break;
				}

				break;

		}
	}
}

Breakout::Breakout()
{
	winX = 0;
	winY = 0;
	currentLevel = 0;
	currentColourScheme = 0;
	deltaTime = 0.0f;
	lives = 3;
	score = 0;
}

void Breakout::handleInput()
{
	if(Keyboard::getInstance()->isKeyPressed('p'))
	{
		paused = true;
	}
	else if(Keyboard::getInstance()->isKeyPressed('u'))
	{
		paused = false;
	}
}

bool Breakout::initialize(int winX, int winY)
{
	this->winX = winY;
	this->winY = winY;



	levels.push_back(BreakoutLevel(levelOne));
	levels.push_back(BreakoutLevel(levelTwo));
	levels.push_back(BreakoutLevel(levelThree));
	levels.push_back(BreakoutLevel(levelFour));
	levels.push_back(BreakoutLevel(levelFive));

	paddle.setPosition(Vector2f(winX / 2.0f - paddle.getRect().width / 2.0f, BORDER_SIZE + paddle.getRect().height * 1.5f));

	ball.setPosition(Vector2f(winX / 2.0f - ball.getRect().width / 2.0f, BORDER_SIZE + paddle.getRect().height * 1.5f));

	RectangleShape borderBottom;
	borderBottom.setPosition(Vector2f(0.0f, 0.0f));
	borderBottom.setSize(Vector2f((float)winX, BORDER_SIZE));
	borderBottom.setColour(Colour::BLACK);
	windowBorder.bottom = borderBottom;

	RectangleShape borderTop;
	borderTop.setPosition(Vector2f(0.0f, winY - BORDER_SIZE));
	borderTop.setSize(Vector2f((float)winX, BORDER_SIZE));
	borderTop.setColour(Colour::BLACK);
	windowBorder.top = borderTop;

	RectangleShape borderLeft;
	borderLeft.setPosition(Vector2f(0.0f, 0.0f));
	borderLeft.setSize(Vector2f(BORDER_SIZE, (float)winY));
	borderLeft.setColour(Colour::BLACK);
	windowBorder.left = borderLeft;

	RectangleShape borderRight;
	borderRight.setPosition(Vector2f(winX - BORDER_SIZE, 0.0f));
	borderRight.setSize(Vector2f(BORDER_SIZE, (float)winY));
	borderRight.setColour(Colour::BLACK);
	windowBorder.right = borderRight;

	setWindowBounds(borderLeft.getRect().left + borderLeft.getRect().width,
		borderRight.getRect().left, borderTop.getRect().top - borderTop.getRect().height, borderBottom.getRect().top);

	txtScore.setPosition(Vector2f(windowBounds.left, winY - windowBorder.top.getSize().y / 2 - 9));
	txtLives.setPosition(Vector2f(windowBounds.right - 64.0f, winY - windowBorder.top.getSize().y / 2 - 9));

	setColourScheme(currentColourScheme);

	return true;
}

void Breakout::updatePaddle()
{
	paddle.setPosition(Vector2f(ball.getPosition().x - paddle.getSize().x / 2, paddle.getPosition().y));
	float posX = (float)Mouse::getInstance()->getMouseX() - paddle.getSize().x / 2.0f;
	if (posX >= windowBounds.left && posX <= windowBounds.right - paddle.getSize().x)
	{
		paddle.setPosition(Vector2f(posX, paddle.getPosition().y));
	}
}

void Breakout::updateBall()
{
	FloatRect rectBall = ball.getRect();

	FloatRect rectPaddleLeft = paddle.getRect();
	rectPaddleLeft.width /= 2.0f;
	FloatRect rectPaddleRight = rectPaddleLeft;
	rectPaddleRight.left += rectPaddleRight.width;

	std::vector<BreakoutBlock>* pBlocks = levels[currentLevel].getBlocks();
	for (unsigned int i = 0; i < pBlocks->size(); ++i)
	{
		// Ball hits a breakout block
		if (rectBall.intersects(pBlocks->at(i).getRect()))
		{
			score += pBlocks->at(i).getID() * SCORE_MODIFIER;
			levels[currentLevel].hitBlock(i);

			if(levels[currentLevel].isCompleted() && currentLevel != levels.size() - 1)
			{
				currentLevel++;
				levels[currentLevel].reset();
				setColourScheme(currentColourScheme);
				resetBall();
			}
			ball.setVelocity(Vector2f(ball.getVelocity().x, -ball.getVelocity().y));
		}
	}

	// Ball hits the left side of the paddle
	if (rectBall.intersects(rectPaddleLeft))
	{
		ball.setVelocity(Vector2f(-BALL_SPEED, BALL_SPEED));
	}
	// Ball hits the right side of the paddle
	else if (rectBall.intersects(rectPaddleRight))
	{
		ball.setVelocity(Vector2f(BALL_SPEED, BALL_SPEED));
	}

	// Ball hits the left boundary
	if (ball.getPosition().x - ball.getSize() <= windowBounds.left)
	{
		ball.setVelocity(Vector2f(BALL_SPEED, ball.getVelocity().y));
	}
	// Ball hits the right boundary
	else if (ball.getPosition().x + ball.getSize() >= windowBounds.right)
	{
		ball.setVelocity(Vector2f(-BALL_SPEED, ball.getVelocity().y));
	}
	// Ball hits the bottom boundary
	else if (ball.getPosition().y + ball.getSize() < 0)
	{
		lives -= 1;
		if(lives == 0)
		{
			resetGame();
		}
		resetBall();
	}
	// Ball hits the top boundary
	else if (ball.getPosition().y + ball.getSize() >= windowBounds.top)
	{
		ball.setVelocity(Vector2f(ball.getVelocity().x, -BALL_SPEED));
	}

	ball.move(gameSpeed * deltaTime);
}

void Breakout::updateText()
{
	txtScore.setText("Score: " + std::to_string(score));
	txtLives.setText("Lives: " + std::to_string(lives));
}

void Breakout::resetGame()
{
	currentLevel = 0;
	levels[currentLevel].reset();
	setColourScheme(currentColourScheme);
	lives = DEFAULT_LIVES;
	score = 0;
}

void Breakout::resetBall()
{
	//ball.setPosition(Vector2f(paddle.getPosition().x, paddle.getPosition().y + paddle.getSize().y + ball.getSize() * 2.0f));
	ball.setPosition(Vector2f(paddle.getPosition().x + paddle.getSize().x / 2 - ball.getSize(), winY / 2));
	ball.setVelocity(Vector2f(0.0f, -BALL_SPEED));
}

void Breakout::updateWindowTitle() const
{
	glutSetWindowTitle(("glBreakout | Score: " + std::to_string(score) + " | Lives: " + std::to_string(lives)).c_str());
}

void Breakout::draw2D()
{
	glClear(GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, winX, 0, winY, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	levels[currentLevel].draw();
	ball.draw();
	windowBorder.draw();
	paddle.draw();
	txtScore.draw();
	txtLives.draw();

}

void Breakout::draw3D()
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glEnable(GL_CULL_FACE);

	float cubeSize = ball.getPosition().y / winY * 0.75f;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -1.0f);

	glRotatef(angle, 1.0f, 1.0f, 1.0f);

	angle++;
	if (angle >= 360.0f)
	{
		angle = 0.0f;
	}

	glBegin(GL_QUADS);

	Colour::setColour4f(Colour::DEFAULT_BGCUBE_FACE_ONE);
	glVertex3f(cubeSize, cubeSize, -cubeSize);
	glVertex3f(-cubeSize, cubeSize, -cubeSize);
	glVertex3f(-cubeSize, cubeSize, cubeSize);
	glVertex3f(cubeSize, cubeSize, cubeSize);

	Colour::setColour4f(Colour::DEFAULT_BGCUBE_FACE_TWO);
	glVertex3f(cubeSize, -cubeSize, cubeSize);
	glVertex3f(-cubeSize, -cubeSize, cubeSize);
	glVertex3f(-cubeSize, -cubeSize, -cubeSize);
	glVertex3f(cubeSize, -cubeSize, -cubeSize);

	Colour::setColour4f(Colour::DEFAULT_BGCUBE_FACE_THREE);
	glVertex3f(cubeSize, cubeSize, cubeSize);
	glVertex3f(-cubeSize, cubeSize, cubeSize);
	glVertex3f(-cubeSize, -cubeSize, cubeSize);
	glVertex3f(cubeSize, -cubeSize, cubeSize);

	Colour::setColour4f(Colour::DEFAULT_BGCUBE_FACE_FOUR);
	glVertex3f(cubeSize, -cubeSize, -cubeSize);
	glVertex3f(-cubeSize, -cubeSize, -cubeSize);
	glVertex3f(-cubeSize, cubeSize, -cubeSize);
	glVertex3f(cubeSize, cubeSize, -cubeSize);

	Colour::setColour4f(Colour::DEFAULT_BGCUBE_FACE_FIVE);
	glVertex3f(-cubeSize, cubeSize, cubeSize);
	glVertex3f(-cubeSize, cubeSize, -cubeSize);
	glVertex3f(-cubeSize, -cubeSize, -cubeSize);
	glVertex3f(-cubeSize, -cubeSize, cubeSize);

	Colour::setColour4f(Colour::DEFAULT_BGCUBE_FACE_SIX);
	glVertex3f(cubeSize, cubeSize, -cubeSize);
	glVertex3f(cubeSize, cubeSize, cubeSize);
	glVertex3f(cubeSize, -cubeSize, cubeSize);
	glVertex3f(cubeSize, -cubeSize, -cubeSize);

	glEnd();

	//glDisable(GL_CULL_FACE);

}

Breakout* Breakout::getInstance()
{
	if(pInstance == nullptr)
	{
		pInstance = new Breakout();
	}
	return pInstance;
}

Breakout::~Breakout()
{

}
