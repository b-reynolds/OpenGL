#include <glut.h>
#include <stdio.h>
#include "GLColour.h"
#include "Cube.h"
#include <IL/ilut.h>
#include <vector>
#include "Snake.h"

const int WIN_X = 1280;
const int WIN_Y = 720;
const char* WIN_TITLE = "My OpenGL Window";

const GLColour CLR_BACKGROUND = GLColour(0.0f, 0.0f, 0.0f);

GLdouble fieldOfView = 45.0f;
GLfloat deltaTime = 0.0f;
GLfloat frameRate = 0.0f;

int runTime = 0;
int oldRunTime = 0;

Texture2D* txtrFloor;
Texture2D* txtrWall;
Texture2D* txtrCrate;

std::vector<Cube*> gameObjects;

Snake* snake = nullptr;

void initialize()
{
	ilInit();
	iluInit();
	ilutRenderer(ILUT_OPENGL);

	glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	
	GLColour::setClearColour(CLR_BACKGROUND);
	glClearDepth(1.0f);        // Set background depth to farthest
	glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
	glEnable(GL_LIGHTING);

	glEnable(GL_LIGHT0);

	glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
	glShadeModel(GL_SMOOTH);   // Enable smooth shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections

	// Define textures wrapping behaviour
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT	);

	// Define textures filtering behaviour
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);

	// Define how textures is sent down the rendering pipeline
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	// TODO: Clean up dynamic memory

	txtrFloor = new Texture2D("Textures/floor.bmp");
	txtrWall = new Texture2D("Textures/wall.bmp");

	// Create the floor
	for (auto x = -30.0f; x <= 0.0f; x += 2.0f)
	{
		for(auto z = 0.0f; z >= -30.0f; z -= 2.0f)
		{
			gameObjects.push_back(new Cube(Vector3D(x, -15.0f, z), Vector3D(1.0f, 1.0f, 1.0f), *txtrFloor));
		}
	}

	// Create the walls
	for (auto y = -15.0f; y <= 0.0f; y += 2.0f)
	{
		for (auto x = -30.0f; x <= 0.0f; x += 2.0f)
		{
			gameObjects.push_back(new Cube(Vector3D(x, y, -32.0f), Vector3D(1.0f, 1.0f, 1.0f), *txtrWall));
		}
	}

	for (auto y = -15.0f; y <= 0.0f; y += 2.0f)
	{
		for (auto z = -32.0f; z <= 0.0f; z += 2.0f)
		{
			gameObjects.push_back(new Cube(Vector3D(-32.0f, y, z), Vector3D(1.0f, 1.0f, 1.0f), *txtrWall));
		}
	}

	snake = new Snake();
}

void outputDebugInfo()
{
	system("cls");
	printf("Window Size: %d, %d\n", glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
	printf("Screen Size: %d, %d\n", glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));
	printf("FOV: %f\n", fieldOfView);
	printf("FPS: %f\n", frameRate);
	printf("Delta Time: %f\n", deltaTime);
}

void resize(GLsizei width, GLsizei height)
{
	// Get the aspect ratio of the window
	GLfloat aspectRatio = static_cast<GLfloat>(WIN_X) / static_cast<GLfloat>(WIN_Y);

	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);

	// Operate on the  projection matrix
	glMatrixMode(GL_PROJECTION); 

	// Load the identity matrix
	glLoadIdentity();          
	
	// Enable perspective projection with fovy, aspect, zNear and zFar
	gluPerspective(fieldOfView, aspectRatio, 0.1f, 100.0f);
}

void update()
{
	// Get the elapsed time in milliseconds and calculate the delta time
	runTime = glutGet(GLUT_ELAPSED_TIME);

	

	deltaTime = runTime - oldRunTime;
	oldRunTime = runTime;

	snake->update();

	// Output debugging info to the console
	outputDebugInfo();
}

void draw()
{
	update();


	// Clear the colour and depth buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	GLfloat lightpos[] = { 0.5f, 1.0f, 1.0f, 0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);


	// Set the viewing transformation
	gluLookAt(15.0f, 15.0f, 15.0f, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glMatrixMode(GL_MODELVIEW);

	for(auto & gameObject : gameObjects)
	{
		gameObject->draw();
	}

	snake->draw();

	glutSwapBuffers();
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'w':
			snake->setDirection(snake->UP);
			break;
		case 'd':
			snake->setDirection(snake->RIGHT);
			break;
		case 's':
			snake->setDirection(snake->DOWN);
			break;
		case 'a':
			snake->setDirection(snake->LEFT);
			break;
	}
}

int main(int argc, char *argv[])
{
	// Initialize GLUT
	glutInit(&argc, argv);

	// Set the display mode to double buffered
	glutInitDisplayMode(GLUT_DOUBLE);

	// Set the windows size
	glutInitWindowSize(WIN_X, WIN_Y);

	// Set the windows initial position to be the center point of the screen
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - WIN_X) / 2.0f, (glutGet(GLUT_SCREEN_HEIGHT) - WIN_Y) / 2.0f);
	
	// Set the window name and create it
	glutCreateWindow(WIN_TITLE);

	glutDisplayFunc(draw);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(resize);

	initialize();

	glutMainLoop();

	return 0;
}