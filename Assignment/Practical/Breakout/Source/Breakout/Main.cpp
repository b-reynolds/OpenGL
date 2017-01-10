#include <glut.h>
#include <freeglut.h>
#include "Keyboard.h"
#include "Mouse.h"
#include "Breakout.h"

const GLint FRAME_RATE = 1000 / 60;

GLint resX = GetSystemMetrics(SM_CXSCREEN);
GLint resY = GetSystemMetrics(SM_CYSCREEN);

GLint winX = 921;
GLint winY = 691;

float time = 0.0f;
float oldTime = 0.0f;
float deltaTime = 0.0f;

void handleKeyUpEvents(unsigned char key, int x, int y)
{
	Keyboard::getInstance()->setKeyState(key, false);
}

void handleKeyDownEvents(unsigned char key, int x, int y)
{
	Keyboard::getInstance()->setKeyState(key, true);
}

void handleMouseMoveEvents(int x, int y)
{
	Mouse::getInstance()->setMousePosition(x, y);
}

void handleMouseClickEvents(int button, int state, int x, int y)
{
	Mouse::getInstance()->setMouseButtonState(button, !state);
}

void handleWindowResize(int x, int y)
{
	glutReshapeWindow(winX, winY);
}

void update(int data)
{
	glutTimerFunc(FRAME_RATE, update, -1);

		Breakout::getInstance()->update(deltaTime, winX, winY);

		time = (float)glutGet(GLUT_ELAPSED_TIME);
		deltaTime = time - oldTime;
		oldTime = time;

	glutPostRedisplay();
}

void RenderString(float x, float y, void *font, char* string, Colour colour)
{
	char *c;

	glColor3f(colour.r, colour.g, colour.b);
	glRasterPos2f(x, y);


}

void draw(void)
{
	Breakout::getInstance()->draw();
}

void colourSchemeMenu(GLint id)
{
	Breakout::getInstance()->setColourScheme(id);
}

void mainMenu(GLint id)
{

}

void initGL()
{
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL); 
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glShadeModel(GL_SMOOTH);   // Enable smooth shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

int main(int Arg_C, char* Arg_V[])
{
	glutInit(&Arg_C, Arg_V);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowSize(winX, winY);
	glutInitWindowPosition((resX - winX) / 2, (resY - winY) / 2);
	//glOrtho(0.0, winX, 0.0, winY, -1.0, 1.0);

	glutCreateWindow("Breakout");

	int colourSchemeMenuID = glutCreateMenu(colourSchemeMenu);
	glutAddMenuEntry("Default", 0);
	glutAddMenuEntry("Pastel", 1);
	glutAddMenuEntry("Grayscale", 2);
	glutAddMenuEntry("Gameboy", 3);
	glutAddMenuEntry("Terminal", 4);

	glutCreateMenu(mainMenu);

	glutAddSubMenu("Colour Scheme", colourSchemeMenuID);

	glutAttachMenu(GLUT_MIDDLE_BUTTON);

	glutKeyboardFunc(handleKeyDownEvents);
	glutKeyboardUpFunc(handleKeyUpEvents);
	glutMouseFunc(handleMouseClickEvents);
	glutPassiveMotionFunc(handleMouseMoveEvents);
	glutReshapeFunc(handleWindowResize);

	glutDisplayFunc(draw);
	glutTimerFunc(FRAME_RATE, update, -1);

	initGL();

	if (Breakout::getInstance()->initialize(winX, winY))
	{
		glutMainLoop();
	}

	return 0;

}
