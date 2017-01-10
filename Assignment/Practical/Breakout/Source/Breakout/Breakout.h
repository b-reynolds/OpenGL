#pragma once
#include "BreakoutLevel.h"
#include "Border.h"
#include "Mouse.h"
#include "Ball.h"
#include "Paddle.h"
#include "RenderText.h"

extern int levelOne[11][11];
extern int levelTwo[11][11];
extern int levelThree[11][11];
extern int levelFour[11][11];
extern int levelFive[11][11];

struct Bounds
{
	float left;
	float right;
	float top;
	float bottom;
};

class Breakout
{
	const float BORDER_SIZE = 48;
	const float PADDLE_SPEED = 1.0f;
	const float BALL_SPEED = 0.25f;
	const int DEFAULT_LIVES = 3;
	const int SCORE_MODIFIER = 25;

	int winX;
	int winY;

	int lives;
	int score;

	float gameSpeed = 2.0f;

	std::vector<BreakoutLevel> levels;

	unsigned int currentLevel;
	unsigned int currentColourScheme;

	Ball ball;
	Paddle paddle;
	float deltaTime;

	float angle;

	bool paused;

	Border windowBorder;
	Bounds windowBounds;

	RenderText txtScore;
	RenderText txtLives;

	static Breakout* pInstance;
	Breakout();

	void handleInput();

	void updatePaddle();
	void updateBall();
	void updateText();

	void resetGame();
	void resetBall();

	void updateWindowTitle() const;

	void draw2D();
	void draw3D();

public:

	static Breakout* getInstance();
	bool initialize(int winX, int winY);

	void update(float deltaTime, int winX, int winY);
	void draw();
	void setWindowBounds(float left, float right, float top, float bottom);

	void setPaused(bool state);

	void setColourScheme(unsigned int colourScheme);

	~Breakout();

};
 
