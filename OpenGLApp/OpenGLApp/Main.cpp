#include <glut.h>
#include <stdio.h>
#include <IL/ilut.h>
#include <vector>
#include "GLColour.h"
#include "Cube.h"
#include "Snake.h"

const int WIN_X = 1280;
const int WIN_Y = 720;
const char* WIN_TITLE = "SnakeGL <_/\__/\__0>";
const GLColour CLR_BACKGROUND = GLColour(0.0f, 0.0f, 0.0f);
const GLdouble FOV = 45.0f;

int runTime = 0;
int oldRunTime = 0;
GLfloat deltaTime = 0.0f;

Texture2D* txtrFloor;
Texture2D* txtrWall;
Texture2D* txtrCrate;

std::vector<Cube*> gameObjects;

Snake* snake = nullptr;

void initialize()
{
	// Initialize DevIL
	ilInit();

	// Initialize ILU
	iluInit();

	// Initialize the ILUT renderer to OpenGL
	ilutRenderer(ILUT_OPENGL);

	// Enable face culling
	glEnable(GL_CULL_FACE);

	// Set the front facing polygon orientation to counterclockwise
	glFrontFace(GL_CCW);

	// Specify back facing polygons to be culled
	glCullFace(GL_BACK);

	// Specify the colour used when the colour buffers are cleared
	GLColour::setClearColour(CLR_BACKGROUND);

	// Specify the clear value for the depth buffer
	glClearDepth(1.0f);

	// Enable lighting
	glEnable(GL_LIGHTING);

	// Enable LIGHT0
	glEnable(GL_LIGHT0);

	// Enable depth testing for z-culling
	glEnable(GL_DEPTH_TEST);  

	// Set the type of depth-test
	glDepthFunc(GL_LEQUAL);

	// Enable smooth shading
	glShadeModel(GL_SMOOTH);   

	// Nice perspective corrections
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  

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
	gluPerspective(FOV, aspectRatio, 0.1f, 100.0f);
}

void update()
{
	// Get the elapsed time in milliseconds and calculate the delta time
	runTime = glutGet(GLUT_ELAPSED_TIME);
	deltaTime = runTime - oldRunTime;
	oldRunTime = runTime;

	// Update the snake's position
	snake->update(); 
}

void draw()
{
	// Clear the colour and depth buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	GLfloat lightpos[] = { 0.5f, 1.0f, 1.0f, 0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

	// Set the viewing transformation
	gluLookAt(15.0f, 15.0f, 15.0f, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	// Set the matrix mode to model view
	glMatrixMode(GL_MODELVIEW);

	// Draw the game environment
	for(auto & gameObject : gameObjects)
	{
		gameObject->draw();
	}

	// Draw the snake
	snake->draw();

	// Swap the window buffers
	glutSwapBuffers();

	// Mark the current window for redisplaying
	glutPostRedisplay();
}

void run()
{
	update();
	draw();
}

void keyboard(unsigned char key, int x, int y)
{
	// Set the snake's movement direction
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
	default: break;
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	// Initialize GLUT
	glutInit(&__argc, __argv);

	// Set the display mode to double buffered
	glutInitDisplayMode(GLUT_DOUBLE);

	// Set the windows size
	glutInitWindowSize(WIN_X, WIN_Y);

	// Set the windows initial position to be the center point of the screen
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - WIN_X) / 2.0f, (glutGet(GLUT_SCREEN_HEIGHT) - WIN_Y) / 2.0f);
	
	// Set the window name and create it
	glutCreateWindow(WIN_TITLE);

	// Set the display callback function
	glutDisplayFunc(run);

	// Set the keyboard callback function
	glutKeyboardFunc(keyboard);

	// Set the reshape callback function
	glutReshapeFunc(resize);

	// Initialize OpenGL, DevIL, ILU, ILUT and Snake game objects
	initialize();

	// Enter the GLUT event processig loop
	glutMainLoop();

	return 0;
}