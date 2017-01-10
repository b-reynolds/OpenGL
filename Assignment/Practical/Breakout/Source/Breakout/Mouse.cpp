#include "Mouse.h"

Mouse* Mouse::pInstance = nullptr;

Mouse::Mouse()
{
	x = 0;
	y = 0;
}

Mouse* Mouse::getInstance()
{
	if(pInstance == nullptr)
	{
		pInstance = new Mouse();
	}
	return pInstance;
}

void Mouse::setMouseButtonState(int button, int state)
{
	prevMouseStates[button] = mouseStates[button];
	mouseStates[button] = (bool)state;
}

void Mouse::setMousePosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Mouse::hideCursor()
{
	glutSetCursor(GLUT_CURSOR_NONE);
}

void Mouse::showCursor()
{
	glutSetCursor(GLUT_CURSOR_CROSSHAIR);
}

int Mouse::getMouseX() const
{
	return x;
}

int Mouse::getMouseY() const
{
	return y;
}

bool Mouse::isButtonDown(int button)
{
	return mouseStates[button];
}

bool Mouse::isButtonClicked(int button)
{
	return mouseStates[button] && !prevMouseStates[button];
}

Mouse::~Mouse()
{
	delete pInstance;
}
