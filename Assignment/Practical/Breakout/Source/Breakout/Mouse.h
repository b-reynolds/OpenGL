#pragma once
#pragma warning(disable: 4800)
#include <glut.h>

class Mouse
{

private:

	bool prevMouseStates[3] = { false };
	bool mouseStates[3] = { false };

	int x;
	int y;

	static Mouse* pInstance;
	Mouse();

public:

	static Mouse* getInstance();

	static void hideCursor();
	static void showCursor();

	bool isButtonDown(int button);
	bool isButtonClicked(int button);

	void setMouseButtonState(int button, int state);
	void setMousePosition(int x, int y);

	int getMouseX() const;
	int getMouseY() const;

	~Mouse();

};

