#pragma once
#include <glut.h>

class Colour
{

public:

	static const Colour BLACK;
	static const Colour WHITE;

	static const Colour DEFAULT_BLOCK_ONE;
	static const Colour DEFAULT_BLOCK_TWO;
	static const Colour DEFAULT_BLOCK_THREE;
	static const Colour DEFAULT_BLOCK_FOUR;
	static const Colour DEFAULT_BLOCK_FIVE;
	static const Colour DEFAULT_BLOCK_SIX;
	static const Colour DEFAULT_BACKGROUND;
	static const Colour DEFAULT_PADDLE;
	static const Colour DEFAULT_BALL;
	static const Colour DEFAULT_BORDER;
	static const Colour DEFAULT_BGCUBE_FACE_ONE;
	static const Colour DEFAULT_BGCUBE_FACE_TWO;
	static const Colour DEFAULT_BGCUBE_FACE_THREE;
	static const Colour DEFAULT_BGCUBE_FACE_FOUR;
	static const Colour DEFAULT_BGCUBE_FACE_FIVE;
	static const Colour DEFAULT_BGCUBE_FACE_SIX;
	static const Colour DEFAULT_TEXT;


	static const Colour PASTEL_BLOCK_ONE;
	static const Colour PASTEL_BLOCK_TWO;
	static const Colour PASTEL_BLOCK_THREE;
	static const Colour PASTEL_BLOCK_FOUR;
	static const Colour PASTEL_BLOCK_FIVE;
	static const Colour PASTEL_BLOCK_SIX;
	static const Colour PASTEL_BACKGROUND;
	static const Colour PASTEL_PADDLE;
	static const Colour PASTEL_BALL;
	static const Colour PASTEL_BORDER;
	static const Colour PASTEL_TEXT;

	static const Colour GRAYSCALE_BLOCK_ONE;
	static const Colour GRAYSCALE_BLOCK_TWO;
	static const Colour GRAYSCALE_BLOCK_THREE;
	static const Colour GRAYSCALE_BLOCK_FOUR;
	static const Colour GRAYSCALE_BLOCK_FIVE;
	static const Colour GRAYSCALE_BLOCK_SIX;
	static const Colour GRAYSCALE_BACKGROUND;
	static const Colour GRAYSCALE_PADDLE;
	static const Colour GRAYSCALE_BALL;
	static const Colour GRAYSCALE_BORDER;
	static const Colour GRAYSCALE_TEXT;

	static const Colour GAMEBOY_BLOCK_ONE;
	static const Colour GAMEBOY_BLOCK_TWO;
	static const Colour GAMEBOY_BLOCK_THREE;
	static const Colour GAMEBOY_BLOCK_FOUR;
	static const Colour GAMEBOY_BLOCK_FIVE;
	static const Colour GAMEBOY_BLOCK_SIX;
	static const Colour GAMEBOY_BACKGROUND;
	static const Colour GAMEBOY_PADDLE;
	static const Colour GAMEBOY_BALL;
	static const Colour GAMEBOY_BORDER;
	static const Colour GAMEBOY_TEXT;

	static const Colour TERMINAL_BLOCK_ONE;
	static const Colour TERMINAL_BLOCK_TWO;
	static const Colour TERMINAL_BLOCK_THREE;
	static const Colour TERMINAL_BLOCK_FOUR;
	static const Colour TERMINAL_BLOCK_FIVE;
	static const Colour TERMINAL_BLOCK_SIX;
	static const Colour TERMINAL_BACKGROUND;
	static const Colour TERMINAL_PADDLE;
	static const Colour TERMINAL_BALL;
	static const Colour TERMINAL_BORDER;
	static const Colour TERMINAL_TEXT;

	float r;
	float g;
	float b;
	float a;

	Colour();
	Colour(float r, float g, float b);
	Colour(float r, float g, float b, float a);

	~Colour();

	static void setColour3f(Colour colour);
	static void setColour4f(Colour colour);
	static void setClearColour(Colour colour);

};


