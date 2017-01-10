#include "Colour.h"

const Colour Colour::BLACK = Colour(0.0f, 0.0f, 0.0f);
const Colour Colour::WHITE = Colour(1.0f, 1.0f, 1.0f);

const Colour Colour::DEFAULT_BLOCK_ONE = WHITE;
const Colour Colour::DEFAULT_BLOCK_TWO = Colour(1.0f, 0.0f, 0.01f);
const Colour Colour::DEFAULT_BLOCK_THREE = Colour(1.0f, 0.48f, 0.0f);
const Colour Colour::DEFAULT_BLOCK_FOUR = Colour(0.98f, 0.99f, 0.04f);
const Colour Colour::DEFAULT_BLOCK_FIVE = Colour(0.0f, 0.99f, 0.50f);
const Colour Colour::DEFAULT_BLOCK_SIX = Colour(0.01f, 0.87f, 0.99f);
const Colour Colour::DEFAULT_BACKGROUND = Colour(0.07f, 0.07f, 0.07f);
const Colour Colour::DEFAULT_PADDLE = WHITE;
const Colour Colour::DEFAULT_BALL = WHITE;
const Colour Colour::DEFAULT_BORDER = Colour(0.49f, 0.48f, 0.78f);
const Colour Colour::DEFAULT_BGCUBE_FACE_ONE = Colour(0.6f, 0.6f, 0.6f, 0.1f);
const Colour Colour::DEFAULT_BGCUBE_FACE_TWO = Colour(0.5f, 0.5f, 0.5f, 0.1f);
const Colour Colour::DEFAULT_BGCUBE_FACE_THREE = Colour(0.4f, 0.4f, 0.4f, 0.1f);
const Colour Colour::DEFAULT_BGCUBE_FACE_FOUR = Colour(0.3f, 0.3f, 0.3f, 0.1f);
const Colour Colour::DEFAULT_BGCUBE_FACE_FIVE = Colour(0.2f, 0.2f, 0.2f, 0.1f);
const Colour Colour::DEFAULT_BGCUBE_FACE_SIX = Colour(0.1f, 0.1f, 0.1f, 0.1f);
const Colour Colour::DEFAULT_TEXT = WHITE;

const Colour Colour::PASTEL_BLOCK_ONE = WHITE;
const Colour Colour::PASTEL_BLOCK_TWO = Colour(1.0f, 0.45f, 1.0f);
const Colour Colour::PASTEL_BLOCK_THREE = Colour(0.7f, 0.6f, 1.0f);
const Colour Colour::PASTEL_BLOCK_FOUR = Colour(1.0f, 1.0f, 0.45f);
const Colour Colour::PASTEL_BLOCK_FIVE = Colour(0.3f, 1.0f, 0.48f);
const Colour Colour::PASTEL_BLOCK_SIX = Colour(0.45f, 0.86f, 1.0f);
const Colour Colour::PASTEL_BACKGROUND = Colour(0.07f, 0.07f, 0.07f);
const Colour Colour::PASTEL_PADDLE = Colour(0.94f, 0.75f, 1.0f);
const Colour Colour::PASTEL_BALL = WHITE;
const Colour Colour::PASTEL_BORDER = Colour(0.6f, 0.9f, 1.0f);
const Colour Colour::PASTEL_TEXT = WHITE;

const Colour Colour::GRAYSCALE_BLOCK_ONE = WHITE;
const Colour Colour::GRAYSCALE_BLOCK_TWO = Colour(0.21f, 0.21f, 0.21f);
const Colour Colour::GRAYSCALE_BLOCK_THREE = Colour(0.55f, 0.55f, 0.55f);
const Colour Colour::GRAYSCALE_BLOCK_FOUR = Colour(0.92f, 0.92f, 0.92f);
const Colour Colour::GRAYSCALE_BLOCK_FIVE = Colour(0.74f, 0.74f, 0.74f);
const Colour Colour::GRAYSCALE_BLOCK_SIX = Colour(0.69f, 0.69f, 0.69f);
const Colour Colour::GRAYSCALE_BACKGROUND = Colour(0.07f, 0.07f, 0.07f);
const Colour Colour::GRAYSCALE_PADDLE = WHITE;
const Colour Colour::GRAYSCALE_BALL = WHITE;
const Colour Colour::GRAYSCALE_BORDER = Colour(0.50f, 0.50f, 0.50f);
const Colour Colour::GRAYSCALE_TEXT = WHITE;

const Colour Colour::GAMEBOY_BLOCK_ONE = Colour(0.75f, 0.75f, 0.50f);
const Colour Colour::GAMEBOY_BLOCK_TWO = Colour(0.25f, 0.25f, 0.0f);
const Colour Colour::GAMEBOY_BLOCK_THREE = Colour(0.50f, 0.50f, 0.25f);
const Colour Colour::GAMEBOY_BLOCK_FOUR = Colour(0.75f, 0.75f, 0.50f);
const Colour Colour::GAMEBOY_BLOCK_FIVE = Colour(0.50f, 0.50f, 0.25f);
const Colour Colour::GAMEBOY_BLOCK_SIX = Colour(0.50f, 0.50f, 0.25f);
const Colour Colour::GAMEBOY_BACKGROUND = Colour(0.07f, 0.07f, 0.07f);
const Colour Colour::GAMEBOY_PADDLE = Colour(0.75f, 0.75f, 0.50f);
const Colour Colour::GAMEBOY_BALL = Colour(0.75f, 0.75f, 0.50f);
const Colour Colour::GAMEBOY_BORDER = Colour(0.50f, 0.50f, 0.25f);
const Colour Colour::GAMEBOY_TEXT = WHITE;

const Colour Colour::TERMINAL_BLOCK_ONE = Colour(0.0f, 1.0f, 0.0f);
const Colour Colour::TERMINAL_BLOCK_TWO = Colour(0.0f, 1.0f, 0.0f);
const Colour Colour::TERMINAL_BLOCK_THREE = Colour(0.0f, 1.0f, 0.0f);
const Colour Colour::TERMINAL_BLOCK_FOUR = Colour(0.0f, 1.0f, 0.0f);
const Colour Colour::TERMINAL_BLOCK_FIVE = Colour(0.0f, 1.0f, 0.0f);
const Colour Colour::TERMINAL_BLOCK_SIX = Colour(0.0f, 1.0f, 0.0f);
const Colour Colour::TERMINAL_BACKGROUND = BLACK;
const Colour Colour::TERMINAL_PADDLE = Colour(0.0f, 1.0f, 0.0f);
const Colour Colour::TERMINAL_BALL = Colour(0.0f, 1.0f, 0.0f);
const Colour Colour::TERMINAL_BORDER = Colour(0.4f, 0.4f, 0.4f);
const Colour Colour::TERMINAL_TEXT = WHITE;

Colour::Colour()
{
	r = 0.0f;
	g = 0.0f;
	b = 0.0f;
	a = 0.0f;
}

Colour::Colour(float r, float g, float b)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = 1.0f;
}

Colour::Colour(float r, float g, float b, float a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

Colour::~Colour()
{
}

void Colour::setColour3f(Colour colour)
{
	glColor3f(colour.r, colour.g, colour.b);
}

void Colour::setColour4f(Colour colour)
{
	glColor4f(colour.r, colour.g, colour.b, colour.a);
}

void Colour::setClearColour(Colour colour)
{
	glClearColor(colour.r, colour.g, colour.b, 1.0f);
}
