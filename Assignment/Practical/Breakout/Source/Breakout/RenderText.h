#pragma once
#include <freeglut.h>
#include <string>
#include "Vector2f.h"
#include "Colour.h"

class RenderText
{

	std::string text;
	Vector2f position;
	Colour colour;

public:

	RenderText();
	RenderText(Vector2f position, std::string text);

	void draw() const;

	void setText(std::string text);
	void setColour(Colour colour);
	void setPosition(Vector2f position);


	~RenderText();


};

